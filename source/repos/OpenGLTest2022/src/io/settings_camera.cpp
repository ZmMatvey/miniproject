#include "settings_camera.h"

#include "keyboard.h"
#include "mouse.h"
#include "joystick.h"
#include "screen.h"

settings_camera::settings_camera(camera user) 
	: camera(user),
	sensitivity(15.0f),
	sensitivity_zoom(4.5f),
	dt(0), 
	lastTime(0) {
	speed_DOWN = speed_UP = speed_LEFT = speed_RIGHT = speed_BACKWARD = speed_FORWARD = 12.5f;
}

void settings_camera::input_keyboard() {
	if (keyboard::key(GLFW_KEY_W)) {
		updateCameraPos(CameraDirection::FORWARD, dt * speed_FORWARD);
	}
	if (keyboard::key(GLFW_KEY_S)) {
		updateCameraPos(CameraDirection::BACKWARD, dt * speed_BACKWARD);
	}
	if (keyboard::key(GLFW_KEY_D)) {
		updateCameraPos(CameraDirection::RIGHT, dt * speed_RIGHT);
	}
	if (keyboard::key(GLFW_KEY_A)) {
		updateCameraPos(CameraDirection::LEFT, dt * speed_LEFT);
	}
	if (keyboard::key(GLFW_KEY_UP)) {
		updateCameraPos(CameraDirection::UP, dt * speed_UP);
	}
	if (keyboard::key(GLFW_KEY_DOWN)) {
		updateCameraPos(CameraDirection::DOWN, dt * speed_DOWN);
	}
	if (keyboard::key(GLFW_KEY_ENTER)) {
		zoom = 60.0f;
	}
}

void settings_camera::input_mouse() {
	double dx = mouse::getDX();
	double dy = mouse::getDY();
	double dY = mouse::getScrollDY();
	if (dx != 0 || dy != 0) {
		updateCameraDiraction(dx * (sensitivity / 100), dy * (sensitivity / 100));
	}
	if (dY != 0) {
		updateCameraZoom(dY * sensitivity_zoom);
	}
}

void settings_camera::input_joystick() {
}
