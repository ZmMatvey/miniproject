#include "joystick.h"

joystick::joystick(int i) {
	id = getId(i);

	update();
}

void joystick::update() {
	present = glfwJoystickPresent(id);

	if (present) {
		name = glfwGetJoystickName(id);
		axes = glfwGetJoystickAxes(id, &axesCount);
		buttons = glfwGetJoystickButtons(id, &buttonCount);
	}
}

float joystick::axesState(int axis) const {
	if (present) {
		return axes[axis];
	}
	return 0.0f;
}

unsigned char joystick::buttonState(int button) const {
	return present ? buttons[button] : GLFW_RELEASE;
}

int joystick::getAxesCount() const {
	return axesCount;
}

int joystick::getButtonCount() const {
	return buttonCount;
}

bool joystick::isPresent() const{
	return present;
}

const char* joystick::getName() const {
	return name;
}

int joystick::getId(int i) {
	return GLFW_JOYSTICK_1 + i;
}
