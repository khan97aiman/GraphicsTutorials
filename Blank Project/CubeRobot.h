#pragma once
#include <nclgl/ObjectNode.h>

class CubeRobot : public ObjectNode {
public:
	CubeRobot(Mesh* cube);
	void Animate(float dt);
protected:
	GeometryNode* head;
	GeometryNode* leftArm;
	GeometryNode* rightArm;
};

