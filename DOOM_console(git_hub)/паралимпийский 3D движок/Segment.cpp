#include "Segment.h"
#include <iostream>
#include "Global.h"
Wall createWall(int Height, int Width)
{
	Wall box;
	box.s1.p1.x = Width;
	box.s1.p1.y = Height;
	box.s1.p2.x = Width + 1;
	box.s1.p2.y = Height;
	box.s2.p1.x = Width + 1;
	box.s2.p1.y = Height;
	box.s2.p2.x = Width + 1;
	box.s2.p2.y = Height + 1;
	box.s3.p1.x = Width + 1;
	box.s3.p1.y = Height + 1;
	box.s3.p2.x = Width;
	box.s3.p2.y = Height + 1;
	box.s4.p1.x = Width;
	box.s4.p1.y = Height + 1;
	box.s4.p2.x = Width;
	box.s4.p2.y = Height;
	return box;
}
void BuildWorldSegments()
{
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if (worldMap[i][j] != 0)
			{
				Wall box = createWall(i, j);
				worldSegments.push_back(box.s1);
				worldSegments.push_back(box.s2);
				worldSegments.push_back(box.s3);
				worldSegments.push_back(box.s4);
			}
		}
	}
}