#pragma once
#include "..\nclgl\OGLRenderer.h"
#include <nclgl/SceneGraphNode.h>
#include <nclgl/Camera.h>
#include "CubeRobot.h"

class Renderer : public OGLRenderer {
public:
	Renderer(Window & parent);
	~Renderer(void);
	void UpdateScene(float dt) override;
	void RenderScene() override;
protected:
	void DrawNode(SceneGraphNode * n);
	SceneGraphNode* root;
	Camera * camera;
	Mesh * cube;
	Shader * shader;
};

