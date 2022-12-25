#ifndef OBJECT_H
#define OBJECT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

#include "mesh.h"

class model 
{
public:
	mesh Mesh;

	model();

	void render(shader Shader) const;

	void cleanup();
};

#endif //OBJECT_H