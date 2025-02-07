#pragma once
#include "Movie.h"
class Game
{
	Movie * player = nullptr;


	
public:
	//Whether each button was pressed, to help determine the filters. The variables starting with o, are used to save the value of the other ones should the menu close
	bool reset;
	bool wes = true;
	bool owes;
	bool dra = true;
	bool odra;
	bool cri = true;
	bool ocri;
	bool com = true;
	bool ocom;
	bool bio = true;
	bool obio;

	//helper variables
	bool b;
	bool c1;
	bool c2;
	bool dr;
	bool w;

	bool highlighted = false;
	bool dest = false;
	bool save = false;
	bool next = false;
	bool previous = false;
	int arrow_ = 1;
	void update();
	void draw();
	void init();
	Game();
	~Game();
	bool contains(float x, float y);
	bool clearf(float x, float y);
	bool savef(float x, float y);
	bool Rarrow(float x, float y);
	bool Larrow(float x, float y);
	void Bio(float x, float y);
	float l_x = CANVAS_WIDTH / 2 - 345;
	float r_x = CANVAS_WIDTH / 2 + 345;
	float same_y = CANVAS_HEIGHT / 4;
	

};