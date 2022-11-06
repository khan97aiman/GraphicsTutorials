#include "GeometryNode.h"

GeometryNode::GeometryNode(Mesh* mesh) : ObjectNode() {
	this->mesh = mesh;
	//texture??
}

void GeometryNode::Draw(const OGLRenderer& r) {
	mesh->Draw();
}
