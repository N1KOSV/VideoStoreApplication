#pragma once
#include <string>
#include "Gameobject.h"
#include "config.h"
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>

class Movie : public Gameobject
{
	float speed = 10.0f;
	float pos_x = CANVAS_WIDTH / 2, pos_y = CANVAS_HEIGHT / 2;
public:
	int arrow = 1; // the movie number
	//Variables to check whether each of the five movies is to be rendered
	bool pp_ = false;
	bool p_ = false;
	bool c_ = false;
	bool n_ = false;
	bool nn_ = false;
	float yearfrom;
	float yearto;
	int start_arrow;
	std::string getyr(int nr);
	std::string getdirector(int nr);
	std::string geta1(int nr);
	std::string geta2(int nr);
	std::string geta3(int nr);
	std::string getp1(int nr);
	std::string getp2(int nr);
	std::string getp3(int nr);
	std::string getpic(int nr);
	bool year(std::string year1, float yrf, float yrt);
	void update() override;
	void init() override;
	void draw(int arrow, bool biography, bool comedy, bool crime, bool drama, bool western, float yrf, float yrt) override;
	void reader(int mov);
	float color();
	bool movie_type_selected(std::string type, bool biography, bool comedy, bool crime, bool drama, bool western);

	std::string gettitle(int nr);

	std::string gettype(int nr);


	int main() {

		Movie* m = new Movie;

		//boards with all the attributes, for each movie see vertically 
		return 0;
	}


};
	


