#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>

//Class
class vec2 {
public:
	float x, y;
};
class Color {
public:
	GLfloat r, g, b;
};
class obj2d {
public:
	vec2 pos, size;
	Color color;
	void Draw();
};

//Windowing stuff
inline GLFWwindow* window = nullptr;
inline const char* vertexShaderSource;
inline const char* fragmentShaderSource;
inline GLuint VAO, VBO, EBO;
inline GLuint shaderprogram;
inline GLuint fragmentShader;
inline GLuint vertexShader;

void Init(int width, int height, const char *title);
void BeginDraw();
void EndDraw();
void Terminate();
void ep();
void setBG(Color color);
void swapBuffers();
bool winShouldClose();
int getScreenWidth();
int getScreenHeight();


//Drawing
void rec(vec2 pos, vec2 size, Color color);
void triangle(vec2 pos, int size, Color color);
