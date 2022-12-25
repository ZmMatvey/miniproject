#include "camera.h"

void camera::updateCameraVectors() {
	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(direction);
	 
	cameraRight = glm::normalize(glm::cross(cameraFront, worldUp));
	cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));
}

camera::camera(glm::vec3 position)
	: cameraPos(position), 
	cameraFront(glm::vec3(0.0f, 0.0f, -1.0f)),
	worldUp(glm::vec3(0.0f, 1.0f, 0.0f)),
	yaw(-90.0f), 
	pitch(0.0f),  
	zoom(60.0f) {
	updateCameraVectors();
}

void camera::updateCameraDiraction(double dx, double dy) {
	yaw += dx;
	pitch += dy;
	
	if (pitch > 89.0f) {
		pitch = 89.0f;
	}
	else if (pitch < -89.0f) {
		pitch = -89.0f;
	}
	
	updateCameraVectors();
}

void camera::updateCameraPos(CameraDirection dir, float velocity) {
	switch (dir) {
	case CameraDirection::FORWARD:
		cameraPos += cameraFront * velocity;
		break;
	case CameraDirection::BACKWARD:
		cameraPos -= cameraFront * velocity;
		break;
	case CameraDirection::RIGHT:
		cameraPos += cameraRight * velocity;
		break;
	case CameraDirection::LEFT:
		cameraPos -= cameraRight * velocity;
		break;
	case CameraDirection::UP:
		cameraPos += cameraUp * velocity;
		break;
	case CameraDirection::DOWN:
		cameraPos -= cameraUp * velocity; 
		break;
	}
}

void camera::updateCameraZoom(double dy) {
	if (zoom >= 15.0f && zoom <= 60.0f) {
		zoom -= dy;
	}
	else if (zoom < 15.0f) {
		zoom = 15.0f;
	}
	else { //>60.0f && zoom >= 15.0f
		zoom = 60.0f;
	}
}

float camera::getZoom() const {
	return zoom;
}

glm::mat4 camera::getVeiwMatrix() {
	//выделите lookAt, нажмите F12(Fn F12), поставьте точку останова возле lookAtRH, чтобы понять, как работает камера
	return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}
