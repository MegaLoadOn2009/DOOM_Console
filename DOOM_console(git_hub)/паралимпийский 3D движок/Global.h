#ifndef GLOBAL_H
#define GLOBAL_H
#include <vector>
using namespace std;
const int mapHeight = 24, mapWidth = 24;
const int screenHeight = 60, screenWidth = 200;
const double focusLen = 2;
const char color[11] = { ' ', '^', ':', ';', '+', '=', '*', '1', '#', '%', '@'};
extern char screen[screenHeight][screenWidth];
extern int worldMap[mapHeight][mapWidth];
struct point2D {
	double x;
	double y;
};
struct vec2 {
	double x;
	double y;
};
struct Segment {
	point2D p1;
	point2D p2;
};
struct Wall {
	Segment s1;
	Segment s2;
	Segment s3;
	Segment s4;
};
struct cam {
	point2D cord;
	vec2 dir;
	double viewingAngle;
	double maxView;
};
extern vector<Segment> worldSegments;
extern cam camera;
extern double lenToObject[screenWidth];
extern vec2 masOfRays[screenWidth];
#endif // GLOBAL_H
