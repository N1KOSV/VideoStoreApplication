#pragma once
#define SET_COLOR(c,r,g,b) { c[0]=r; c[1]=g; c[2]=b; }


inline float distance(float x1, float y1, float x2, float y2) 
{
	float dx = x1 - x2;
	float dy = y1 - y2;
	return sqrtf(dx * dx + dy * dy);

}
