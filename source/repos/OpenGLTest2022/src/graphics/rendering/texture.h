#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stb/stb_image.h>

class texture final
{
private:
	static int currentId;

	// img properties
	const char* path;
	int width;
	int height;
	int nChannels;

public:
	texture();
	texture(const char* path, const char* name, bool defaultParams = true);

	void generate();
	void load(bool flip = true);

	void setFilters(GLenum all) const;
	void setFilters(GLenum mag, GLenum min) const;

	void setWrap(GLenum all) const;
	void setWrap(GLenum s, GLenum t) const;

	void setBorderColor(float borderColor[4]) const;

	void activate() const;

	// texture object
	int id;
	unsigned int tex;
	const char* name;

};

#endif //TEXTURE_H