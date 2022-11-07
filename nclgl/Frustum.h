#pragma once
#include "Plane.h"
#include "SceneGraphNode.h"
#include "GeometryNode.h"

class Frustum {
public:
	Frustum(void) {};
	~Frustum(void) {};
	void FromMatrix(const Matrix4 & mvp);
	bool InsideFrustum(SceneGraphNode & n);
protected:
	Plane planes[6];
};

