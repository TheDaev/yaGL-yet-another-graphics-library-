#include "yatc.h"


void setBG(Color color)
{
	glClearColor(color.r, color.g, color.b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwPollEvents();
}
void Init(int width, int height, const char* title)
{

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Vertices coordinates
	GLfloat vertices[]=
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
		-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
		0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
		0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
	};

	GLuint indices[] =
	{
		0, 3, 5, // Lower left triangle
		3, 2, 4, // Lower right triangle
		5, 4, 1 // Upper triangle
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

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	shaderprogram = glCreateProgram();
	glAttachShader(shaderprogram, vertexShader);
	glAttachShader(shaderprogram, fragmentShader);
	glLinkProgram(shaderprogram);

	glDeleteProgram(vertexShader);
	glDeleteProgram(fragmentShader);

	glClearColor(0.7f, 0.5f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);


	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


}
void BeginDraw()
{
}
void EndDraw()
{
}
void Terminate()
{

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(shaderprogram);

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
void swapBuffers()
{
	glfwSwapBuffers(window);
}
void rec(vec2 pos, vec2 size, Color color)
{
}
void triangle(vec2 pos, int size, Color color)
{
	glClearColor(color.r, color.g, color.b, 1.0f);
	glUseProgram(shaderprogram);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
}
void obj2d::Draw()
{
}
