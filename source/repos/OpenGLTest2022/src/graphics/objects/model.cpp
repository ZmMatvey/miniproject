#include "model.h"

model::model() {}

void model::render(shader Shader) const {
	Mesh.render(Shader);
}

void model::cleanup() {
	Mesh.cleanup();
}