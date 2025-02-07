#pragma once
#include "Movie.h"
class Menu
{
	Menu* menu = nullptr;
	float menu_x = 0;
	float menu_y = 0;
	float menu_sx = 0;
	float menu_sy = 0;

public:
	void update();
	void draw(float i, int k, bool bio, bool com, bool cri, bool dra, bool wes, float pos_from, float pos_to);
	void init();
	void move(float x ,float y);
	void pressed(bool a);
	void setYr2();
	Menu();
	~Menu();

	bool ispressed(float x, float y);

	float get_menu_x() { return menu_x; }
	float get_menu_y() { return menu_y; }
	void set_menu_x(float x) { menu_x = x; }
	void set_menu_y(float y) { menu_y = y; }
	int getYr1();
	int getYr2();

	void setYr1();

};
