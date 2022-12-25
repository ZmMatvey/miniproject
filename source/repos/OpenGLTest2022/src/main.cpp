#include "io/screen.h"
#include "io/settings_camera.h"
#include "io/keyboard.h"

#include "graphics/rendering/shader.h"
#include "graphics/models/cube.hpp"


int main()
{
	float mixVal = 0.5f;

	screen Screen;

	settings_camera user(camera({ 0.0f, 0.0f, 0.0f }));

	glfwInit();

	screen::OpenGL_version();

	if (!Screen.init()) {
		std::cout << "Could not open window" << std::endl;
		glfwTerminate();
		return -1;
	}

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}

	Screen.setParameters();

	// SHADERS===============================
	shader Shader("assets/object.vs", "assets/object.fs");

	// MODELS==============================
	
	//задай колличество кубов===========================
	std::vector<cube> MultyCube;
	
	for (int i = 0; i < 8000; i++) {
		MultyCube.push_back(cube());
		MultyCube[i].init();
	}
	//==================================================

	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	while (!Screen.shouldClose()) {

		// calculate dt
		double currentTime = glfwGetTime();
		user.dt = currentTime - user.lastTime;
		user.lastTime = currentTime;

		if (keyboard::key(GLFW_KEY_ESCAPE)) {
			Screen.setShouldClose(true);
		}

		// process input
		user.input_keyboard();
		user.input_mouse();

		// render
		Screen.update();

		// draw shapes
		Shader.activate();

		Shader.setFloat("mixVal", mixVal);

		// create transformation

		view = user.getVeiwMatrix();
		//http://www.songho.ca/opengl/gl_projectionmatrix.html
		projection = glm::perspective(glm::radians(user.zoom), (float)screen::SCR_WIDTH / (float)screen::SCR_HEIGHT, 0.1f, 100.0f);

		Shader.setMat4("view", view);
		Shader.setMat4("projection", projection);

		
		//подставь параметры сюда!===============================
		
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				for (int k = 0; k < 20; k++) {
					MultyCube[380 * i + 19 * j + k].render(Shader,
						{ 0.2 * i * glfwGetTime(), 0.2 * j * glfwGetTime(),  0.2 * k * glfwGetTime() }, //позиция куба x, y, z
						{ 0.05f * i, 0.05f * j, 0.05f * k, 0.0f }); //цвет куба меняется от 0 до 1, первые 3 параметра r,g,b, последний всунь по умолчанию 0
				}
			}
		}

		//=======================================================
		// send new frame to window
		Screen.newFrame();
		glfwPollEvents();
	}
	
	for (int i = 0; i < 8000; i++) {
		MultyCube[i].cleanup();
	}

	glfwTerminate();
	return 0;
}
