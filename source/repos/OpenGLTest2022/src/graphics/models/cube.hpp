#ifndef CUBE_H
#define CUBE_H

#include "../objects/model.h"

class cube : public model 
{
public:
	glm::vec3 pos;
	glm::vec4 colors;
	glm::vec3 size;

	cube(glm::vec4 colors = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
		glm::vec3 size = glm::vec3(1.0f, 1.0f, 1.0f))
		: pos(glm::vec3(0.0f, 0.0f, 0.0f)), colors(colors), size(size) {}

	void init() {
		int noVertices = 36;
	
		float vertices[] = {
				//	position			
				-0.5f, -0.5f, -0.5f,
				 0.5f, -0.5f, -0.5f,
				 0.5f,  0.5f, -0.5f,
				 0.5f,  0.5f, -0.5f,
				-0.5f,  0.5f, -0.5f,
				-0.5f, -0.5f, -0.5f,

				-0.5f, -0.5f,  0.5f,
				 0.5f, -0.5f,  0.5f,
				 0.5f,  0.5f,  0.5f,
				 0.5f,  0.5f,  0.5f,
				-0.5f,  0.5f,  0.5f,
				-0.5f, -0.5f,  0.5f,

				-0.5f,  0.5f,  0.5f,
				-0.5f,  0.5f, -0.5f,
				-0.5f, -0.5f, -0.5f,
				-0.5f, -0.5f, -0.5f,
				-0.5f, -0.5f,  0.5f,
				-0.5f,  0.5f,  0.5f,

				 0.5f,  0.5f,  0.5f,
				 0.5f,  0.5f, -0.5f,
				 0.5f, -0.5f, -0.5f,
				 0.5f, -0.5f, -0.5f,
				 0.5f, -0.5f,  0.5f,
				 0.5f,  0.5f,  0.5f,

				-0.5f, -0.5f, -0.5f,
				 0.5f, -0.5f, -0.5f,
				 0.5f, -0.5f,  0.5f,
				 0.5f, -0.5f,  0.5f,
				-0.5f, -0.5f,  0.5f,
				-0.5f, -0.5f, -0.5f,

				-0.5f,  0.5f, -0.5f,
				 0.5f,  0.5f, -0.5f,
				 0.5f,  0.5f,  0.5f,
				 0.5f,  0.5f,  0.5f,
				-0.5f,  0.5f,  0.5f,
				-0.5f,  0.5f, -0.5f
		};

		std::vector<unsigned int> indices(noVertices);
		for (int i = 0; i < 36; i++) {
			indices[i] = i;
		}

		Mesh = mesh(Vertex::genList(vertices, noVertices), indices);
	}

	void render(shader Shader, glm::vec3 pos, glm::vec4 colors) const {
		glm::mat4 Model = glm::mat4(1.0f);
		glm::mat4 Colors = {colors,
			glm::vec4(0.0f),
			glm::vec4(0.0f),
			glm::vec4(0.0f)};
		Model = glm::rotate(Model, glm::radians(10.0f) * (float)glfwGetTime(), glm::vec3(0.5f, 0.5f, 0.5f));
		Model = glm::translate(Model, pos);
		Model = glm::scale(Model, size);
		Shader.setMat4("model", Model);
		Shader.setMat4("Colors", Colors);
		
		model::render(Shader);
	}
};

#endif //CUBE_H