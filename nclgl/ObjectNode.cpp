#include "ObjectNode.h"

ObjectNode::~ObjectNode() {
	for (unsigned int i = 0; i < children.size(); ++i) {
		delete children[i];
	}
}

void ObjectNode::AddChild(ObjectNode* s) {
	children.push_back(s);
	s->parent = this;
}

void ObjectNode::Update(float dt) {
	if (parent) { //This node has a parent ...
		worldTransform = parent->GetWorldTransform() * transform;
	}
	else { //Root node , world transform is local transform!
		worldTransform = transform;
	}
	for (vector <ObjectNode*>::iterator i = children.begin(); i != children.end(); ++i) {
		(*i)->Update(dt);
	}
}
