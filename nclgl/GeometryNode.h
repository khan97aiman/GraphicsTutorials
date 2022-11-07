#pragma once
#include "ObjectNode.h"
#include "Mesh.h"

class GeometryNode : public ObjectNode {
public:
	GeometryNode(Mesh* mesh, GLuint texture = NULL);
	Vector3 GetModelScale() const { return modelScale; }
	void SetModelScale(Vector3 s) { modelScale = s; }
	Mesh* GetMesh() const { return mesh; }
	void SetMesh(Mesh* m) { mesh = m; }
	Vector4 GetColour() const { return colour; }
	void SetColour(Vector4 c) { colour = c; }
	void SetTexture(GLuint tex) { texture = tex; }
	GLuint GetTexture() const { return texture; }
	virtual void Draw(const OGLRenderer& r);
	void UpdateShaderMatrices();

protected:
	Mesh* mesh = NULL;
	GLuint texture = 0; //should texture be here? or should it be part of mesh?
	Vector4 colour = Vector4(1, 1, 1, 1);
	Vector3 modelScale = Vector3(1, 1, 1);
	Shader* shader;

	Matrix4 projMatrix;		//Projection matrix
	Matrix4 modelMatrix;	//Model matrix. NOT MODELVIEW
	Matrix4 viewMatrix;		//View matrix
	Matrix4 textureMatrix;	//Texture matrix
	Matrix4 shadowMatrix;
};

