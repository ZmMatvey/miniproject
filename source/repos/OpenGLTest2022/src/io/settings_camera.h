#ifndef SETTINGS_CAMERA_H
#define SETTINGS_CAMERA_H

#include "camera.h"

class settings_camera final: public camera
{
private:
	float sensitivity;
	float sensitivity_zoom;

	float speed_FORWARD;
	float speed_BACKWARD;
	float speed_RIGHT;
	float speed_LEFT;
	float speed_UP;
	float speed_DOWN;

public:

	double dt;
	double lastTime;

	settings_camera(camera user);

	void input_keyboard();
	void input_mouse();
	void input_joystick();
};

#endif //SETTINGS_CAMERA_H
