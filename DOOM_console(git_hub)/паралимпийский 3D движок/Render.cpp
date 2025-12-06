#include "Render.h"
#include "Global.h"
#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
void clearScreen()
{
	for (int i = 0; i < screenHeight; i++)
		for (int j = 0; j < screenWidth; j++)
			screen[i][j] = ' ';
}
void renderToConsole()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(hConsole, pos);
	string buf = "";
	for (int i = 0; i < screenHeight; i++)
	{

		for (int j = 0; j < screenWidth; j++)
			buf += screen[i][j];
	}
		cout << buf;
	cout.flush();
}
int foundWallHeight(double len)
{
	return min(round(focusLen * screenHeight / len), screenHeight);
}
void renderScreen()
{
	for (int i = 0; i < screenWidth; i++)
	{
		int drawStart = (screenHeight - foundWallHeight(lenToObject[i])) / 2;
		int drawEnd = drawStart + foundWallHeight(lenToObject[i]);
		int pigment = max(0,min(round(5 * camera.maxView / lenToObject[i]), 10));
		char col = color[pigment];
		for (int j = 0; j < screenHeight; j++)
		{
			char a;
			if (j < drawStart)
				a = ' ';
			else if (j > drawEnd)
				a = '.';
			else
				a = col;
			screen[j][i] = a;
		}
	}
}