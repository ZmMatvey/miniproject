#ifndef MESH_H
#define MESH_H

#include <vector>
#include <glm/glm.hpp>

#include "../rendering/texture.h"
#include "../rendering/shader.h"

struct Vertex final
{
	glm::vec3 pos;

	/*
	v1.vec3.x|v1.vec3.y|v1.vec3.z|
	v2.vec3.x|v2.vec3.y|v2.vec3.z|
	*/

	static std::vector<Vertex> genList(float* vertices, int noVertices);
};

class mesh final 
{
private:
	unsigned int VBO, EBO, VAO;

	void setup();

public:

	std::vector<Vertex> vertices;

	std::vector<unsigned int> indices;

	mesh();

	mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);

	void render(shader Shader) const;

	void cleanup();

};

#endif //MESH_H