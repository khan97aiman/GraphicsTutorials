#include "Renderer.h"

Renderer::Renderer(Window& parent) : OGLRenderer(parent) {
	triangle = Mesh::GenerateTriangle();
	matrixShader = new Shader("matrixVertex.glsl", "colourFragment.glsl");
	camera = new Camera;
	if (!matrixShader->LoadSuccess()) {
		return;
	}
	init = true;
	SwitchToOrthographic();
}

Renderer::~Renderer() {
	delete triangle;
	delete matrixShader;
	delete camera;
}

void Renderer::SwitchToPerspective() {
	projMatrix = Matrix4::Perspective(1.0f, 10000.0f,
	(float)width / (float)height, 45.0f);
}

void Renderer::SwitchToOrthographic() {
	projMatrix = Matrix4::Orthographic(-1.0f, 10000.0f,
	width / 2.0f, -width / 2.0f, height / 2.0f, -height / 2.0f);
}

void Renderer::UpdateScene(float dt) {
	camera->UpdateCamera(dt);
	viewMatrix = camera->BuildViewMatrix();
}
void Renderer::RenderScene() {
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	BindShader(matrixShader);
	
	for (int i = 0; i < 3; ++i) {
		Vector3 tempPos = position;
		tempPos.z += (i * 500.0f);
		tempPos.x -= (i * 100.0f);
		tempPos.y -= (i * 100.0f);
		modelMatrix  =	Matrix4::Translation(tempPos) *
						Matrix4::Rotation(rotation, Vector3(0, 1, 0)) *
						Matrix4::Scale(Vector3(scale, scale, scale));
		UpdateShaderMatrices();
		triangle->Draw();
	}
}