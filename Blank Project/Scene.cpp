#include "Scene.h"
#include "StainedGlass.h"
#include "CubeRobot.h"
#include <algorithm>


Scene::Scene(Window& parent) : OGLRenderer(parent) {
	meshes.push_back(Mesh::LoadFromMeshFile("OffsetCubeY.msh")); //cube
	meshes.push_back(Mesh::GenerateQuad()); //quad
	texture = SOIL_load_OGL_texture(TEXTUREDIR"stainedglass.tga", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0);

	camera = new Camera(0.0f, 0.0f, (Vector3(0, 100, 750.0f)));
	world = new ObjectNode();

	for (int i = 0; i < 5; ++i) {
		world->AddChild(new StainedGlass(meshes[1], texture, Matrix4::Translation(Vector3(0, 100.0f, -300.0f + 100.0f + 100.0f * i))));
	}
	world->AddChild(new CubeRobot(meshes[0]));
	
}

Scene::~Scene() {
	delete world;
	delete camera;
	Shader* shader;

	for (const auto i : meshes) {
		delete i;
	}
	glDeleteTextures(1, &texture);
}


void Scene::DrawNodes() {
	for (const auto& i : nodeList) {
		DrawNode(i);
	}
	for (const auto& i : transparentNodeList) {
		DrawNode(i);
	}
}

void Scene::DrawNode(GeometryNode* n) {
	if (n->GetMesh()) {
		Matrix4 model = n->GetWorldTransform() * Matrix4::Scale(n->GetModelScale());
		glUniformMatrix4fv(glGetUniformLocation(shader->GetProgram(), "modelMatrix"), 1, false, model.values);
		glUniform4fv(glGetUniformLocation(shader->GetProgram(), "nodeColour"), 1, (float*)&n->GetColour());
		texture = n->GetTexture();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glUniform1i(glGetUniformLocation(shader->GetProgram(), "useTexture"), texture);
		n->Draw(*this);
	}
}

void Scene::BuildNodeLists(ObjectNode* from) {
	if (frameFrustum.InsideFrustum(*dynamic_cast<GeometryNode*>(from))) {
		Vector3 dir = from->GetWorldTransform().GetPositionVector() - camera->GetPosition();
		from->SetCameraDistance(Vector3::Dot(dir, dir));
		if (from->GetColour().w < 1.0f) {
			transparentNodeList.push_back(from);
		}
		else {
			nodeList.push_back(from);
		}
	}
	for (vector <ObjectNode*>::const_iterator i = from->GetChildIteratorStart(); i != from->GetChildIteratorEnd(); ++i) {
		BuildNodeLists((dynamic_cast<GeometryNode*>( * i)));
	}
}

void Scene::SortNodeLists() {
	std::sort(transparentNodeList.rbegin(), transparentNodeList.rend(), ObjectNode::CompareByCameraDistance);
	std::sort(nodeList.begin(), nodeList.end(), ObjectNode::CompareByCameraDistance);
}

void Scene::ClearNodeLists() {
	transparentNodeList.clear();
	nodeList.clear();
}

void Scene::UpdateScene(float dt) {
	camera->UpdateCamera(dt);
	
	frameFrustum.FromMatrix(projMatrix * viewMatrix);
	world->Update(dt);
}

void Scene::RenderScene() {
	BuildNodeLists(world);
	SortNodeLists();
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	BindShader(shader);
	UpdateShaderMatrices();
	glUniform1i(glGetUniformLocation(shader->GetProgram(), "diffuseTex"), 0);
	DrawNodes();
	ClearNodeLists();
}
