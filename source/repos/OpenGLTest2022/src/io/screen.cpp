#include "screen.h"

#include "keyboard.h"
#include "mouse.h"

unsigned int screen::SCR_WIDTH = 800; 
unsigned int screen::SCR_HEIGHT = 600;

void screen::framebufferSizeCallback(GLFWwindow* widnow, int width, int height) {
	glViewport(0, 0, width, height);

	SCR_WIDTH = width;
	SCR_HEIGHT = height;
}
void screen::OpenGL_version() {
	//OpenGL version 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

	//для запуска на Mac OS
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif //__APPLE__
}

screen::screen()
	: window(nullptr) {}

bool screen::init() {
	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL Project", NULL, NULL);
	if (window == NULL) {
		// window not created;
		return false;
	}
	glfwMakeContextCurrent(window);

	return true;
}

void screen::setParameters() const {
	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

	glfwSetFramebufferSizeCallback(window, screen::framebufferSizeCallback);

	glfwSetKeyCallback(window, keyboard::keyCallback);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, mouse::cursorPosCallback);
	glfwSetMouseButtonCallback(window, mouse::mouseButtonCallback);
	glfwSetScrollCallback(window, mouse::mouseWheelCallback);

	glEnable(GL_BLEND);
}

// main loop
void screen::update() const {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void screen::newFrame() const {
	glfwSwapBuffers(window);
}

// window closing
bool screen::shouldClose() const {
	return glfwWindowShouldClose(window);
}

void screen::setShouldClose(bool shouldClose) const {
	glfwSetWindowShouldClose(window, shouldClose);
}
