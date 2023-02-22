#include "yatc.h"

int main() {

	Init(800, 800, "Test 1");

	while (!winShouldClose()) {
		setBG({ 1,1,1 });
		triangle({ 0,0 }, 1, { 0.7f,0.5f,0.6f });
		swapBuffers();
	}

	Terminate();

	return 0;
}