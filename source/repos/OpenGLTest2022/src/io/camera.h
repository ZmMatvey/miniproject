#ifndef CAMERA_H
#define CAMERA_H

#define GLFW_INCLUDE_NONE
#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum class CameraDirection 
{
	NONE = 0,
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT, 
	UP,
	DOWN
};

class camera
{
private:
	void updateCameraVectors();

public:
	glm::vec3 cameraPos;

	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	glm::vec3 cameraRight;

	glm::vec3 worldUp;

	float yaw;
	float pitch;
	float zoom;

	camera(glm::vec3 position);

	void updateCameraDiraction(double dx, double dy);
	void updateCameraPos(CameraDirection dir, float velocity);
	void updateCameraZoom(double dy);

	float getZoom() const;

	glm::mat4 getVeiwMatrix();
};


#endif //CAMERA_H

