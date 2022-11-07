#include "StainedGlass.h"
#include <nclgl/GeometryNode.h>

StainedGlass::StainedGlass(Mesh* quad, GLuint texture, Matrix4 transform) {
	//this->transform = Matrix4::Translation(Vector3(0, 100.0f, -300.0f + 100.0f));
	GeometryNode* body = new GeometryNode(quad, texture);
	body->SetTransform(transform);
	body->SetModelScale(Vector3(100.0f, 100.0f, 100.0f));
	body->SetColour(Vector4(1.0f, 1.0f, 1.0f, 0.5f));
	body->SetBoundingRadius(100.0f);
	this->AddChild(body);
}
