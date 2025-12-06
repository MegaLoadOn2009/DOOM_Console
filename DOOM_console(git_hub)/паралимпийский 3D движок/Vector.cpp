#include "Vector.h"
#include "Global.h"
#include <iostream>
using namespace std;
vec2 VecSumm(vec2 vector1, vec2 vector2)
{
	vec2 result;
	result.x = vector1.x + vector2.x;
	result.y = vector1.y + vector2.y;
	return result;
}
vec2 VecDif(vec2 vector1, vec2 vector2)
{
	vec2 result;
	result.x = vector1.x - vector2.x;
	result.y = vector1.y - vector2.y;
	return result;
}
vec2 VecScale(vec2 vector1, double a)
{
	vector1.x *= a;
	vector1.y *= a;
	return vector1;
}
void VecRotate(vec2& vector, double corner)
{
	double x = vector.x, y = vector.y;
	vector.x = x * cos(corner) - y * sin(corner);
	vector.y = x * sin(corner) + y * cos(corner);
}
vec2 scanVecRotate(vec2 vector, double corner)
{
	double x = vector.x, y = vector.y;
	vector.x = x * cos(corner) - y * sin(corner);
	vector.y = x * sin(corner) + y * cos(corner);
	return vector;
}
double roundToN(double a, int n)
{
	return round(a * pow(10, n)) / double(pow(10, n));
}