#define _USE_MATH_DEFINES
#include "Raycaster.h"
#include "Global.h"
#include "Vector.h"
#include <iostream>
#include <cmath>
double IntersectionDistance(point2D vecOrigin, vec2 RayDir, Segment wall)
{
	double D, t, u;
	D = RayDir.x * (wall.p2.y - wall.p1.y) - RayDir.y * (wall.p2.x - wall.p1.x);
	if (abs(D) < 0.1)
		return 1000;
	t = ((wall.p1.x - vecOrigin.x) * (wall.p1.y - wall.p2.y) - (wall.p1.y - vecOrigin.y) * (wall.p1.x - wall.p2.x)) / D;
	u = ((wall.p1.x - vecOrigin.x) * RayDir.y - (wall.p1.y - vecOrigin.y) * RayDir.x) / D;
	if (t < 0 or u < 0 or u > 1)
		return 1000;
	else
		return t;
}
void masOfLens()
{
	for (int i = 0; i < screenWidth; i++)
	{
		double angle = camera.viewingAngle * (double(i) / double(screenWidth) - 0.5);
		vec2 RayDir = scanVecRotate(camera.dir, angle);
		masOfRays[i] = RayDir;
		lenToObject[i] = 1000;
		for (Segment& wall : worldSegments)
		{
			double len = IntersectionDistance(camera.cord, masOfRays[i], wall);
			if (len < lenToObject[i])
			{
				lenToObject[i] = len;
			}
		}
	}
}