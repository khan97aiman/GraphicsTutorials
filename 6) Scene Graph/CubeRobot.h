#pragma once
#include <nclgl/SceneGraphNode.h>

class CubeRobot : public SceneGraphNode {
public:
	CubeRobot(Mesh * cube);
	~CubeRobot(void) { };
	void Update(float dt) override;
	
protected:
	SceneGraphNode* head;
	SceneGraphNode* leftArm;
	SceneGraphNode* rightArm;
};

