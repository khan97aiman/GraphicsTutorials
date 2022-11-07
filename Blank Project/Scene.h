#pragma once
#include <nclgl/GeometryNode.h>
#include <nclgl/Camera.h>
#include <nclgl/Frustum.h>

class Scene : public OGLRenderer {
public:
	Scene(Window& parent);
	~Scene();
	void DrawNodes();
	void DrawNode(GeometryNode* n);
	void BuildNodeLists(ObjectNode* from);
	void SortNodeLists();
	void ClearNodeLists();
	void UpdateScene(float dt); //change to update and render
	void RenderScene();
protected:
	ObjectNode* world;
	Camera* camera;
	std::vector<Mesh*> meshes;
	GLuint texture;
	Frustum frameFrustum;
	vector <GeometryNode*> transparentNodeList;
	vector <GeometryNode*> nodeList;
	Shader* shader;
};

