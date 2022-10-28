#pragma once
#include "Matrix4.h"
#include "Vector3.h"
class Camera {
public:
	Camera() {};
	Camera(float pitch, float yaw, Vector3 position);
	~Camera(void) {};
	void UpdateCamera(float dt = 1.0f);
	Matrix4 BuildViewMatrix();
	Vector3 GetPosition() const { return position; }
	void SetPosition(Vector3 val) { position = val; }
	float GetYaw() const { return yaw; }
	void SetYaw(float y) { yaw = y; }
	float GetPitch() const { return pitch; }
	void SetPitch(float p) { pitch = p; }
protected:
	float yaw = 0.0f;
	float pitch = 0.0f;
	Vector3 position = Vector3(0.0f,0.0f,0.0f); //Set to 0,0,0 by Vector3 constructor ;)
	
};

