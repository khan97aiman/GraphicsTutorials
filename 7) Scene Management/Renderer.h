#pragma once
#include "..\nclgl\OGLRenderer.h"
#include <nclgl/SceneGraphNode.h>
#include <nclgl/Camera.h>
#include <nclgl/Frustum.h>

class Renderer : public OGLRenderer {
public:
	Renderer(Window & parent);
	~Renderer(void);
	void UpdateScene(float msec) override;
	void RenderScene() override;
protected:
	void BuildNodeLists(SceneGraphNode * from);
	void SortNodeLists();
	void ClearNodeLists();
	void DrawNodes();
	void DrawNode(SceneGraphNode * n);
	SceneGraphNode * root;
	Camera * camera;
	Mesh * quad;
	Mesh * cube;
	Shader * shader;
	GLuint texture;
	Frustum frameFrustum;
	vector <SceneGraphNode*> transparentNodeList;
	vector <SceneGraphNode*> nodeList;
};

