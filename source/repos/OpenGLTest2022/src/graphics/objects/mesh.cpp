#include "mesh.h"

std::vector<Vertex> Vertex::genList(float* vertices, int noVertices) {
	std::vector<Vertex> ret(noVertices);

	int stride = sizeof(Vertex) / sizeof(float);

	for (int i = 0; i < noVertices; i++) {
		ret[i].pos = glm::vec3(
			vertices[i * stride + 0],
			vertices[i * stride + 1],
			vertices[i * stride + 2]
		);
	}

	return ret;
}

mesh::mesh() {}

mesh::mesh(std::vector<Vertex> vertices, 
	std::vector<unsigned int> indices)
	: vertices(vertices), 
	indices(indices) {
	setup();
}

void mesh::render(shader Shader) const {
	// EBO stuff
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, vertices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void mesh::cleanup() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void mesh::setup() {
	// create buffers/arrays
	glGenVertexArrays(1, &VAO); // vertex array object
	glGenBuffers(1, &VBO); // vertex buffer object
	glGenBuffers(1, &EBO); // element buffer object

	glBindVertexArray(VAO);

	// load data into VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	// load data into EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	// set vertex attribute pointers
	// vertex.position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

	glBindVertexArray(0);
}