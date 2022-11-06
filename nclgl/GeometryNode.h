#pragma once
#include "ObjectNode.h"
#include "Mesh.h"

class GeometryNode : public ObjectNode {
public:
	GeometryNode(Mesh* mesh);
	Vector3 GetModelScale() const { return modelScale; }
	void SetModelScale(Vector3 s) { modelScale = s; }
	Mesh* GetMesh() const { return mesh; }
	void SetMesh(Mesh* m) { mesh = m; }
	void SetTexture(GLuint tex) { texture = tex; }
	GLuint GetTexture() const { return texture; }
	virtual void Draw(const OGLRenderer& r);

protected:
	Mesh* mesh = NULL;
	GLuint texture = 0; //should texture be here? or should it be part of mesh?
	Vector3 modelScale = Vector3(1, 1, 1);
};

