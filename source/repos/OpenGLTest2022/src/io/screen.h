#ifndef SCREEN_H
#define SCREEN_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class screen final
{
private:
	GLFWwindow* window;

	static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

public:
	static unsigned int SCR_WIDTH;
	static unsigned int SCR_HEIGHT;

	static void OpenGL_version();

	screen();

	bool init();

	void setParameters() const;

	// main loop
	void update() const; 
	void newFrame() const;

	// window closing
	bool shouldClose() const;
	void setShouldClose(bool shouldClose) const;

};

#endif //SCREEN_H