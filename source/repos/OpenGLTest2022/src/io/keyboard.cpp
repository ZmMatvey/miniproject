#include "keyboard.h"

//массив клавиш
bool keyboard::keys[GLFW_KEY_LAST] = { 0 };
//массив изменения клавиш при смене кадра 
bool keyboard::keysChanged[GLFW_KEY_LAST] = { 0 };

//1 - с какого окна принимаются параметры, 2 - номер клавиши, 3 - параметр для работы с необычной клавиатурой (например, в ней 1000 клавиш иностранного алфавита)
//4 - действие(повторение(2), нажатие клавиши(1), опускание клавиши(0)), 4 - сочетание клавиш
void keyboard::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action != GLFW_RELEASE) {
		if (!keys[key]) {
			keys[key] = true;
		}
	}
	else {
		keys[key] = false;
	}

	keysChanged[key] = action != GLFW_REPEAT;
}

bool keyboard::key(int key){
	return keys[key];
}
bool keyboard::keyChanged(int key){
	bool ret = keysChanged[key];
	keysChanged[key] = false;
	return ret;
}
bool keyboard::keyWentUp(int key){
	return !keys[key] && keyChanged(key);
}
bool keyboard::keyWentDown(int key){
	return keys[key] && keyChanged(key);
}

