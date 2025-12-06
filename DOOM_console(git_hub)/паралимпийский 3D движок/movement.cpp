#include "Global.h"
#include "vector.h"
#include <cmath>
#include <iostream>
#include <windows.h>
const double moveSpeed = 1;
const double rotSpeed = 1.3;
using namespace std;
const double FIXED_DT = 1.0 / 24;
void move()
{
	double actualMoveSpeed = moveSpeed * FIXED_DT;
	double actualRotSpeed = rotSpeed * FIXED_DT;
	if (GetAsyncKeyState(0x53) & 0x8000)
	{
		camera.cord.x += camera.dir.x * actualMoveSpeed;
		camera.cord.y += camera.dir.y * actualMoveSpeed;
	}
	if (GetAsyncKeyState(0x57) & 0x8000)
	{
		camera.cord.x -= camera.dir.x * actualMoveSpeed;
		camera.cord.y -= camera.dir.y * actualMoveSpeed;
	}
	if (GetAsyncKeyState(0x41) & 0x8000)
	{
		camera.cord.x -= camera.dir.y * actualMoveSpeed;
		camera.cord.y += camera.dir.x * actualMoveSpeed;
	}
	if (GetAsyncKeyState(0x44) & 0x8000)
	{
		camera.cord.x += camera.dir.y * actualMoveSpeed;
		camera.cord.y -= camera.dir.x * actualMoveSpeed;
	}
	if (GetAsyncKeyState(0x27) & 0x8000)
	{
		VecRotate(camera.dir, actualRotSpeed);
	}
	if (GetAsyncKeyState(0x25) & 0x8000)
	{
		VecRotate(camera.dir, -actualRotSpeed);
	}
}