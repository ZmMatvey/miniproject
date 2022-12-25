#ifndef KEYBOARD_H
#define KEYBOARD_H

#define GLFW_INCLUDE_NONE
#include <glad/glad.h> //многоязычный загрузчик
#include <GLFW/glfw3.h>

class keyboard final
{
private:
	static bool keys[];
	static bool keysChanged[];

public:
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	/*
		accessors
	*/

	static bool key(int key);
	static bool keyChanged(int key);
	static bool keyWentUp(int key);
	static bool keyWentDown(int key);
};

#endif //KEYBOARD_H

