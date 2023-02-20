#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>

//Windowing stuff
inline GLFWwindow* window = nullptr;
const char* vertexShaderSource;
//Fragment Shader source code
const char* fragmentShaderSource;

void Init(int width, int height, const char *title);
void BeginDraw();
void EndDraw();
void Terminate();
bool winShouldClose();
void ep();
int getScreenWidth();
int getScreenHeight();


//Drawing
class vec2 {
public:
	float x, y;
};
class Color {
public:
	float r, g, b;
};
class obj2d {
public:
	vec2 pos, size;
	Color color;
	void Draw();
};
void rec(vec2 pos, vec2 size, Color color);
void triangle(vec2 pos, int size, Color color);
