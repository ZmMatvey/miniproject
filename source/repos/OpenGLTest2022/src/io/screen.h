#ifndef SCREEN_H
#define SCREEN_H

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class screen final
{
private:
	GLFWwindow* window; 

	static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

	//размеры контекстного окна
	static int SCR_WIDTH;
	static int SCR_HEIGHT;

	static bool init_context_window;

public:
	static void OpenGL_Version(int major = 3, int minor = 3); 
	static void Init_Glad();

	screen();

	void init(int widht = 800, int height = 600, const char* name = "OpenGL Project");

	void MakeContextCurrent();

	GLFWwindow* getWindow() const;
	static int getWidth();
	static int getHeight();

	void setFramebufferSize() const;
	void setKeyboard() const;
	void setMouse(int mode_cursor = GLFW_CURSOR_NORMAL) const;
	void setParameters() const;

	static void setEnable();

	void setSize(int widht, int height) const;
	void setPos(int pos_x, int pos_y) const;

	// main loop
	void update() const; 
	void newFrame() const;

	// window closing
	bool shouldClose() const;

	void setShouldClose(bool shouldClose) const;
	void setFullScreen(int mode = GLFW_CURSOR_DISABLED) const;
	void setRestoreScreen(int mode = GLFW_CURSOR_NORMAL) const;
};

#endif //SCREEN_H