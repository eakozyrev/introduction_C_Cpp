// https://www.youtube.com/watch?v=faUVucdIFFY
// https://github.com/RobotRage/snake_cpp/blob/master/snake/main.cpp
#include <GLFW/glfw3.h>
#include "windows.h"
#include <vector>
#include <time.h> 

//forward declaration
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void start();

//define window size here
static int windowSizeX = 600;
static int windowSizeY = 600;

static int gridSize = 20;

int snakeDirectionX;
int snakeDirectionY;

bool allowInput = true;

struct point
{
	int x;
	int y;
};

std::vector<point> mapBounds;
std::vector<point> snake;
std::vector<point> fruit;


void renderObjects()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(10);
	glLineWidth(2.5);
	glColor3f(0.0, 1.0, 0.0);


	for (int i = 0; i < mapBounds.size(); i++)
	{
		//start rendering a line
		glBegin(GL_LINES);

		//specify first point in the vector list, where x and y are the coords
		glVertex3f(mapBounds[i].x, mapBounds[i].y, 0);

		//if i is at the third element, link back to the first element
		if (i == mapBounds.size() - 1)
		{
			glVertex3f(mapBounds[0].x, mapBounds[0].y, 0);
		}
		//otherwise link to the next element
		else
		{
			glVertex3f(mapBounds[i + 1].x, mapBounds[i + 1].y, 0);
		}

		glEnd();
	}

	for (int i = 0; i < snake.size(); i++)
	{
		if (i == 0)
		{
			glColor3f(.5f, .5f, 0.0);
		}
		else
		{
			glColor3f(1.0, 0.0, 0.0);
		}

		glBegin(GL_POLYGON);

		glVertex3f(snake[i].x, snake[i].y, 0);
		glVertex3f(snake[i].x, snake[i].y + gridSize, 0);
		glVertex3f(snake[i].x + gridSize, snake[i].y + gridSize, 0);
		glVertex3f(snake[i].x + gridSize, snake[i].y, 0);

		glEnd();
	}

	glColor3f(0.0, 0.0, 1.0);

	for (int i = 0; i < fruit.size(); i++)
	{
		glBegin(GL_POLYGON);

		glVertex3f(fruit[i].x, fruit[i].y, 0);
		glVertex3f(fruit[i].x, fruit[i].y + gridSize, 0);
		glVertex3f(fruit[i].x + gridSize, fruit[i].y + gridSize, 0);
		glVertex3f(fruit[i].x + gridSize, fruit[i].y, 0);

		glEnd();
	}
}

void reset()
{
	snake.clear();
	//snake initial pos

	int remainderX = (windowSizeX / 2) % (gridSize * 2);
	int remainderY = (windowSizeY / 2) % (gridSize * 2);

	int midX = (windowSizeX / 2) - remainderX;
	int midY = (windowSizeY / 2) - remainderY;

	snake.push_back(point());
	snake[0].x = midX;
	snake[0].y = midY;

	snake.push_back(point());
	snake[1].x = midX;
	snake[1].y = midY - (gridSize);

	snake.push_back(point());
	snake[2].x = midX;
	snake[2].y = midY - (gridSize * 2);

	snake.push_back(point());
	snake[3].x = midX;
	snake[3].y = midY - (gridSize * 3);

	snake.push_back(point());
	snake[4].x = midX;
	snake[4].y = midY - (gridSize * 4);


	//set initial snake direction
	snakeDirectionX = 0;
	snakeDirectionY = 1;
}

void eatFruit()
{
	snake.push_back(point());
	snake[snake.size() - 1].x = -20;
	snake[snake.size() - 1].y = -20;
}

bool checkBounds()
{
	for (int i = 1; i < snake.size(); i++)
	{
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
		{
			reset();
		}
	}

	for (int i = 0; i < fruit.size(); i++)
	{
		if (snake[0].x == fruit[i].x && snake[0].y == fruit[i].y)
		{
			eatFruit();
			fruit.erase(fruit.begin() + i);
		}
	}

	if ((snake[0].x >= windowSizeX | snake[0].y >= windowSizeY) | (snake[0].x <= 0 | snake[0].y <= 0))
	{
		reset();
	}

	return true;
}

void moveSnake()
{
	for (int i = snake.size() - 1; i >= 0; i--)
	{

		if (i != 0)
		{
			snake[i].x = snake[i - 1].x;
			snake[i].y = snake[i - 1].y;
		}
		else
		{
			if (snakeDirectionX != 0)
			{
				snake[i].x += gridSize * snakeDirectionX;
			}
			else if (snakeDirectionY != 0)
			{
				snake[i].y += gridSize * snakeDirectionY;
			}
		}
		allowInput = true;
	}
}

bool spawnFruit()
{

	if (fruit.size() < 20)
	{
		int posX = rand() % (windowSizeX - (gridSize * 2)) + (gridSize * 2);
		int posY = rand() % (windowSizeY - (gridSize * 2)) + (gridSize * 2);

		int leftOverX = posX % (gridSize * 2);
		int leftOverY = posY % (gridSize * 2);

		int newPosX = posX - leftOverX;
		int newPosY = posY - leftOverY;

		for (int i = 0; i < snake.size(); i++)
		{
			if (newPosX == snake[i].x && newPosY == snake[i].y)
			{
				return false;
			}
		}
		fruit.push_back(point());

		fruit[fruit.size() - 1].x = newPosX;
		fruit[fruit.size() - 1].y = newPosY;
	}
	return true;
}

int tickrate = 15;
int tick = 0;
void mainloop()
{
	checkBounds();
	tick++;

	if (tick >= tickrate)
	{

		if (checkBounds())
		{
			moveSnake();
		}
		spawnFruit();
		tick = 0;
	}
}

void start()
{

	//instantiate point
	mapBounds.push_back(point());
	//set point coords
	mapBounds[0].x = 0;
	mapBounds[0].y = 0;

	mapBounds.push_back(point());
	mapBounds[1].x = 0;
	mapBounds[1].y = windowSizeY - 0;

	mapBounds.push_back(point());
	mapBounds[2].x = windowSizeX - 0;
	mapBounds[2].y = windowSizeY - 0;

	mapBounds.push_back(point());
	mapBounds[3].x = windowSizeX - 0;
	mapBounds[3].y = 0;

	//call reset to set init snake pos
	reset();
}

//entry point
int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//window variable
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	//create window x,y size in pixels and window name
	window = glfwCreateWindow(windowSizeX, windowSizeY, "snake", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	//for key input
	glfwSetKeyCallback(window, key_callback);

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);


	// set up view
	glViewport(0, 0, windowSizeX, windowSizeY);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0.0, windowSizeX, 0.0, windowSizeY, 0.0, 1.0); // this creates a canvas you can do 2D drawing on

	//contains all setup stuff ran once
	start();

	//main while loop
	while (!glfwWindowShouldClose(window))
	{

		renderObjects();

		//call our main loop containing logic
		mainloop();

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//close
	glfwTerminate();
	return 0;
}



//key inputs
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	char c = key;

#pragma region

	// key codes can be found here > https://www.glfw.org/docs/3.3/group__keys.html

	//left
	if (key == 263 | key == 65 && action == GLFW_REPEAT | action == GLFW_PRESS)
	{
		if (snakeDirectionY != 0 && allowInput)
		{
			snakeDirectionX = -1;
			snakeDirectionY = 0;
			allowInput = false;
		}

	}

	//right
	if (key == 262 | key == 68 && action == GLFW_REPEAT | action == GLFW_PRESS)
	{
		if (snakeDirectionY != 0 && allowInput)
		{
			snakeDirectionX = 1;
			snakeDirectionY = 0;
			allowInput = false;
		}
	}

	//down
	if (key == 264 | key == 83 && action == GLFW_REPEAT | action == GLFW_PRESS)
	{
		if (snakeDirectionX != 0 && allowInput)
		{
			snakeDirectionX = 0;
			snakeDirectionY = -1;
			allowInput = false;
		}
	}

	//up
	if (key == 265 | key == 87 && action == GLFW_REPEAT | action == GLFW_PRESS)
	{
		if (snakeDirectionX != 0 && allowInput)
		{
			snakeDirectionX = 0;
			snakeDirectionY = 1;
			allowInput = false;
		}
	}

#pragma endregion Movement Input
}