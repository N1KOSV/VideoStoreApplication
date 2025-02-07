#pragma once
#include <string>
class Widget {
	float B_pos_x;
	float B_pos_y;
	float width = 80.0f;
	float height = 20.0f;
public:
	std::string name;
	std::string type;
	void update();
	void draw(int a);
	void draw(int i, float B_pos_x, float B_pos_y, float height, float width, std::string txt, bool pressed);
	void draw(float pos_x, float pos_y, float pos_p, std::string title);
	void init();
	float getposx();
	float getposy();
	float getwidth();
	float getheight();
	float restore(float pos);
	float getYr1();
};