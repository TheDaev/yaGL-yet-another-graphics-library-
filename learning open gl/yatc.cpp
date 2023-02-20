#include "yatc.h"


void Init(int width, int height, const char* title)
{

	vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
		"}\n\0";

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Vertices coordinates
	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
	};

	window = glfwCreateWindow(width, height, title, NULL, NULL);

	//Check if window fails to create
	if (window == NULL) {
		std::cout << "Failed to create window!" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	gladLoadGL();


	glViewport(0, 0, width, height);

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER)

	glClearColor(0.7f, 0.5f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);


}

void BeginDraw()
{
}

void EndDraw()
{
}

void Terminate()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

bool winShouldClose()
{
	return glfwWindowShouldClose(window);
}

void ep()
{
	glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int getScreenWidth()
{
	return 0;
}

int getScreenHeight()
{
	return 0;
}

void rec(vec2 pos, vec2 size, Color color)
{
}

void triangle(vec2 pos, int size, Color color)
{
}

void obj2d::Draw()
{
}
