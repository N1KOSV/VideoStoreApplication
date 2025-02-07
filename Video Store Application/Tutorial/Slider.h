#pragma once
#include "Widget.h"
#include <string>


class Slider : Widget {
	Slider* slider = nullptr;
	float position;
	float width = 80.0f;
	float height = 20.0f;
	int year;
	bool res = false;

public:
	void update();
	void draw(float pos_x, float pos_y, float pos_p, std::string title);
	void move(float pos_x, float pos_y);
	float restore(float pos_x);
	int getYr1();
	bool ispressed(float x, float y);
};