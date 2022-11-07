#pragma once
#include "..\nclgl\ObjectNode.h"
class StainedGlass : public ObjectNode {
public:
	StainedGlass(Mesh* quad, GLuint texture, Matrix4 transform);
};

