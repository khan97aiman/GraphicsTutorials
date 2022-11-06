#include "SceneGraphNode.h"

SceneGraphNode::SceneGraphNode(Mesh* m, Vector4 colour) {
	this->mesh = m;
	this->colour = colour;
}

SceneGraphNode::~SceneGraphNode(void) {
	for (unsigned int i = 0; i < children.size(); ++i) {
		delete children[i];
	}
}

void SceneGraphNode::AddChild(SceneGraphNode* s) {
	children.push_back(s);
	s->parent = this;
}

void SceneGraphNode::Update(float dt) {
	if (parent) { //This node has a parent ...
		worldTransform = parent->worldTransform * transform;
	}
	else { //Root node , world transform is local transform!
		worldTransform = transform;
	}
	for (vector <SceneGraphNode*>::iterator i = children.begin(); i != children.end(); ++i) {
		(*i)->Update(dt); 
	}
}

void SceneGraphNode::Draw(const OGLRenderer& r) {
	if (mesh) { mesh->Draw(); }
}
