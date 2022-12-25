#include "Shader.h"

unsigned int shader::get_id() const {
	return id;
}

shader::shader() {}
shader::shader(const char* vertexShaderPath, const char* fragmentShaderPath) {
	generate(vertexShaderPath, fragmentShaderPath);
}

void shader::generate(const char* vertexShaderPath, const char* fragmentShaderPath) {
	int success;
	char infoLog[512];

	GLuint vertexShader = compileShader(vertexShaderPath, GL_VERTEX_SHADER);
	GLuint fragShader = compileShader(fragmentShaderPath, GL_FRAGMENT_SHADER);

	id = glCreateProgram();
	glAttachShader(id, vertexShader);
	glAttachShader(id, fragShader);
	glLinkProgram(id);

	//catch error
	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(id, 512, NULL, infoLog);
		std::cout << "Linking error:" << std::endl << infoLog << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragShader);
}

void shader::activate() const {
	glUseProgram(id);
}

std::string shader::loadShaderSrc(const char* filename) const {
	std::ifstream file;
	std::stringstream buf;

	std::string ret = "";

	file.open(filename);

	if (file.is_open()) {
		buf << file.rdbuf(); //?
		ret = buf.str();
	}
	else {
		std::cout << "error open " << filename << std::endl;
	}

	file.close();

	return ret;
}
GLuint shader::compileShader(const char* filepath, GLenum type) const {
	int success;
	char infoLog[512];

	GLuint ret = glCreateShader(type);
	std::string shaderSrc = loadShaderSrc(filepath);
	const GLchar* shader = shaderSrc.c_str();
	glShaderSource(ret, 1, &shader, NULL);
	glCompileShader(ret);

	//catch error
	glGetShaderiv(ret, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(ret, 512, NULL, infoLog);
		std::cout << "Error with fragment shader comp.:" << std::endl << infoLog << std::endl;
	}

	return ret;
}

//передача матрицы name в vertex_shader(id), как uniform
void shader::setMat4(const std::string& name, glm::mat4 value) const {
	glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}
//передача int name
void shader::setInt(const std::string& name, int value) const {
	glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}
//передача float name
void shader::setFloat(const std::string& name, float value) const {
	glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}