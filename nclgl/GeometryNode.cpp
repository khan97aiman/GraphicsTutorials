#include "GeometryNode.h"

GeometryNode::GeometryNode(Mesh* mesh, GLuint texture) {
	this->mesh = mesh;
	this->texture = texture;
}

void GeometryNode::Draw(const OGLRenderer& r) {
	mesh->Draw();
}

void GeometryNode::UpdateShaderMatrices() {
	if (shader) {
		glUniformMatrix4fv(glGetUniformLocation(shader->GetProgram(), "modelMatrix"), 1, false, modelMatrix.values);
		glUniformMatrix4fv(glGetUniformLocation(shader->GetProgram(), "viewMatrix"), 1, false, viewMatrix.values);
		glUniformMatrix4fv(glGetUniformLocation(shader->GetProgram(), "projMatrix"), 1, false, projMatrix.values);
		glUniformMatrix4fv(glGetUniformLocation(shader->GetProgram(), "textureMatrix"), 1, false, textureMatrix.values);
		glUniformMatrix4fv(glGetUniformLocation(shader->GetProgram(), "shadowMatrix"), 1, false, shadowMatrix.values);
	}
}
