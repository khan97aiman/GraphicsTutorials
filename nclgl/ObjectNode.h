#pragma once
#include "SceneNode.h"
#include "OGLRenderer.h"
class ObjectNode : public SceneNode {
public:(
	~ObjectNode();
	void AddChild(ObjectNode* s);
	std::vector <ObjectNode*>::const_iterator GetChildIteratorStart() { return children.begin(); }
	std::vector <ObjectNode*>::const_iterator GetChildIteratorEnd() { return children.end(); }
	float GetBoundingRadius() const { return boundingRadius; }
	void SetBoundingRadius(float f) { boundingRadius = f; }
	float GetCameraDistance() const { return distanceFromCamera; }
	void SetCameraDistance(float f) { distanceFromCamera = f; }
	static bool CompareByCameraDistance(ObjectNode* a, ObjectNode* b) { return (a->distanceFromCamera < b->distanceFromCamera) ? true : false; }
	virtual void Update(float dt);
protected:
	std::vector<ObjectNode*> children;
	float distanceFromCamera = 0.0f;
	float boundingRadius = 1.0f;
};

