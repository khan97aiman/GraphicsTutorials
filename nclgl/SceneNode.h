#include <vector>
#include "Matrix4.h"

class SceneNode {
public:
	void SetTransform(const Matrix4& matrix) { transform = matrix; }
	const Matrix4& GetTransform() const { return transform; }
	Matrix4 GetWorldTransform() const { return worldTransform; }
	
protected:
	SceneNode* parent = NULL;
	Matrix4 worldTransform;
	Matrix4 transform;
};
