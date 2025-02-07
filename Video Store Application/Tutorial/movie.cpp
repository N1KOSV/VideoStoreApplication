#include "Movie.h"
#include "defines.h"
#include "Game.h"
#include <string>
#include "Gameobject.h"
#include "config.h"
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include "graphics.h"


	void Movie::draw(int arrow, bool biography, bool comedy, bool crime, bool drama, bool western, float yrf, float yrt)
	{
		float glow = 0.5f + 0.5f * sinf(graphics::getGlobalTime() / 10);
		pp_ = false;
		p_ = false;
		c_ = false;
		n_ = false;
		nn_ = false;
		start_arrow = arrow;
		yearfrom = 1960.0f + (yrf - 210.0f) / 4.0f;
		yearto = 1960.0f + (yrt - 210.0f) / 4.0f;

		//draw the movie to the centre after checking if it allowed by the filers
		graphics::Brush br;
		br.texture = std::string(ASSET_PATH) + getpic(arrow);
		br.outline_opacity = 0.5f + glow;
		br.outline_width = 2.0f;
		if (movie_type_selected(gettype(arrow), biography, comedy, crime, drama, western) && year(getyr(arrow), yearfrom, yearto))
		{
			graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 4, 135, 200, br);
			c_ = true;
		}

		//draw the movie to the very left after checking if it allowed by the filers
		graphics::Brush pp;
		pp.texture = std::string(ASSET_PATH) + getpic((arrow - 2 < 1) ? arrow - 2 + 8 : arrow - 2);
		pp.outline_opacity = 0.0f;
		pp.fill_opacity = 0.6f;
		if (movie_type_selected(gettype((arrow - 2 < 1) ? arrow - 2 + 8 : arrow - 2), biography, comedy, crime, drama, western) && year(getyr((arrow - 2 < 0) ? 8 : arrow - 2), yearfrom, yearto))
		{
			graphics::drawRect(CANVAS_WIDTH / 2 - 265, CANVAS_HEIGHT / 4, 108, 140, pp);
			pp_ = true;
		}	

		//draw the movie to the left after checking if it allowed by the filers
		graphics::Brush p;
		p.texture = std::string(ASSET_PATH) + getpic((arrow - 1 < 1) ? 8 : arrow - 1);
		p.outline_opacity = 0.0f;
		p.fill_opacity = 0.8f;
		if (movie_type_selected(gettype((arrow - 1 < 1) ? 8 : arrow - 1), biography, comedy, crime, drama, western) && year(getyr((arrow - 1 < 0) ? 8 : arrow - 1), yearfrom, yearto))
		{
			graphics::drawRect(CANVAS_WIDTH / 2 - 140, CANVAS_HEIGHT / 4, 121, 180, p);
			p_ = true;
		}

		//draw the movie to the right after checking if it allowed by the filers
		graphics::Brush n;
		n.texture = std::string(ASSET_PATH) + getpic((arrow + 1 > 8) ? 1 : arrow + 1);
		n.outline_opacity = 0.0f;
		n.fill_opacity = 0.8f;
		if (movie_type_selected(gettype((arrow + 1 > 8) ? 1 : arrow + 1), biography, comedy, crime, drama, western) && year(getyr((arrow + 1 > 8) ? 1 : arrow + 1), yearfrom, yearto))
		{
			graphics::drawRect(CANVAS_WIDTH / 2 + 140, CANVAS_HEIGHT / 4, 121, 180, n);
			n_ = true;
		}

		//draw the movie all to the right after checking if it allowed by the filers
		graphics::Brush nn;
		nn.texture = std::string(ASSET_PATH) + getpic((arrow + 2 > 8) ? arrow + 2 - 8 : arrow + 2);
		nn.outline_opacity = 0.0f;
		nn.fill_opacity = 0.6f;
		if (movie_type_selected(gettype((arrow + 2 > 8) ? arrow + 2 - 8 : arrow + 2), biography, comedy, crime, drama, western) && year(getyr((arrow + 2 > 8) ? 1 : arrow + 2), yearfrom, yearto))
		{
			graphics::drawRect(CANVAS_WIDTH / 2 + 265, CANVAS_HEIGHT / 4, 108, 140, nn);
			nn_ = true;
		}


		//SHADOWS
		//create shadow for the main movie
		br.texture = std::string(ASSET_PATH) + getpic(start_arrow);
		br.outline_opacity = 0.0f;
		br.fill_opacity = 0.2f;
		graphics::setOrientation(180);
		if (c_ == true)
		{
			graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 4 + 200, 135, 200, br);
		}

		//create shadows for the next movies
		p.outline_opacity = 0.0f;
		p.fill_opacity = 0.2f;
		n.outline_opacity = 0.0f;
		n.fill_opacity = 0.2f;
		if (p_ == true)
		{
			graphics::drawRect(CANVAS_WIDTH / 2 - 140, CANVAS_HEIGHT / 4 + 180, 121, 180, p);
		}
		if (n_ == true)
		{
			graphics::drawRect(CANVAS_WIDTH / 2 + 140, CANVAS_HEIGHT / 4 + 180, 121, 180, n);
		}
		//create shadow for the very next movies
		pp.outline_opacity = 0.0f;
		pp.fill_opacity = 0.2f;
		nn.outline_opacity = 0.0f;
		nn.fill_opacity = 0.2f;
		if (pp_ == true)
		{
			graphics::drawRect(CANVAS_WIDTH / 2 - 265, CANVAS_HEIGHT / 4 + 140, 108, 140, pp);
		}
		if (nn_ == true)
		{
			graphics::drawRect(CANVAS_WIDTH / 2 + 265, CANVAS_HEIGHT / 4 + 140, 108, 140, nn);
		}
		graphics::resetPose();
		graphics::Brush t_br;
		t_br.outline_opacity = 1.0f;
		//Write the information about the centre movie, should it be shown
		if (c_ == true)
		{
			graphics::drawText(50, 300, 18, std::string(gettitle(arrow)), t_br);

			graphics::Brush bru;
			bru.outline_opacity = 0.5f;
			SET_COLOR(bru.fill_color, 0.5f, 0.5f, 0.5f);

			graphics::drawRect(83, 320, 55, 15, bru);
			graphics::drawText(57, 325, 11, std::string(gettype(arrow)), t_br);

			graphics::drawText(50, 350, 13, std::string("Director:"), t_br);
			graphics::drawText(130, 350, 13, std::string(getdirector(arrow)), t_br);

			graphics::drawText(50, 380, 13, std::string("Stars:"), t_br);
			graphics::drawText(130, 380, 13, std::string(geta1(arrow) + ", " + geta2(arrow) + ", " + geta3(arrow)), t_br);

			graphics::drawText(50, 410, 13, std::string("Year:"), t_br);
			graphics::drawText(130, 410, 13, std::string(getyr(arrow)), t_br);

			graphics::drawText(50, 440, 13, std::string("Summary:"), t_br);
			graphics::drawText(53, 462, 13, std::string(getp1(arrow)), t_br);
			graphics::drawText(53, 475, 13, std::string(getp2(arrow)), t_br);
			graphics::drawText(53, 488, 13, std::string(getp3(arrow)), t_br);
		}
	}
	using namespace std;
	static string title1;
	static string type;
	static string year1;
	static string director1;
	static string actor1;
	static string actor2;
	static string actor3;
	static string plot1;
	static string plot2;
	static string plot3;
	static string picture;
	//Reading the data.txt file with all the movie data, including the image file name
	void Movie::reader(int mov) {
		ifstream File;
		File.open(std::string(ASSET_PATH) + "data.txt");
		string line;
		{
			istringstream f(line);
			streampos title2 = File.tellg();
			streampos title3 = File.tellg();
			streampos title4 = File.tellg();
			streampos title5 = File.tellg();
			streampos title6 = File.tellg();
			streampos title7 = File.tellg();
			streampos title8 = File.tellg();
			getline(File, line);
			getline(File, line);
			streampos top = File.tellg();
			//The line where each movie starts is saved so that the one matching the integer mov is found and its elements are saved
			while (File.eof() == false) {
				if (line == "02") {
					title2 = File.tellg();
				}
				if (line == "03") {
					title3 = File.tellg();
				}
				if (line == "04") {
					title4 = File.tellg();
				}
				if (line == "05") {
					title5 = File.tellg();
				}
				if (line == "06") {
					title6 = File.tellg();
				}
				if (line == "07") {
					title7 = File.tellg();
				}
				if (line == "08") {
					title8 = File.tellg();
				}
				getline(File, line);
			}
			if (mov == 1) { File.seekg(top); }
			if (mov == 2) { File.seekg(title2); }
			if (mov == 3) { File.seekg(title3); }
			if (mov == 4) { File.seekg(title4); }
			if (mov == 5) { File.seekg(title5); }
			if (mov == 6) { File.seekg(title6); }
			if (mov == 7) { File.seekg(title7); }
			if (mov == 8) { File.seekg(title8); }
			getline(File, line);
			title1 = line;
			getline(File, line);
			type = line;
			getline(File, line);
			year1 = line;
			getline(File, line);
			director1 = line;
			getline(File, line);
			actor1 = line;
			getline(File, line);
			actor2 = line;
			getline(File, line);
			actor3 = line;
			getline(File, line);
			plot1 = line;
			getline(File, line);
			plot2 = line;
			getline(File, line);
			plot3 = line;
			getline(File, line);
			picture = line;
		}
	}

	//Check whether a certain movie should be shown, by checking its type
	bool Movie::movie_type_selected(std::string type, bool bio, bool com, bool cri, bool dra, bool wes)
	{
		if ((bio == com) && (com == cri) && (cri == dra) && (dra == wes)) {
			return true;
		}
		if (type == "Biography") {
			return bio;
		}
		if (type == "Comedy") {
			return com;
		}
		if (type == "Crime") {
			return cri;
		}
		if (type == "Drama") {
			return dra;
		}
		if (type == "Western") {
			return wes;
		}

		
	}
	//Check whether a certain movie should be shown, by checking its release year
	bool Movie::year(std::string year1,float yrf,float yrt) {
		if (year1.length() == 4) {
			float y2 = std::stof(year1);
			if((y2 >= yrf) && (y2 <= yrt))
			{
				return true;
			}
		}
			return false;
		}
	// Getting each element for a specific movie (nr)
	std::string Movie::gettitle(int nr) {
		Movie::reader(nr);
		return title1;
	}
	std::string Movie::gettype(int nr) {
		Movie::reader(nr);
		return type;
	}
	std::string Movie::getyr(int nr) {
		Movie::reader(nr);
		return year1;
	}
	std::string Movie::getdirector(int nr) {
		Movie::reader(nr);
		return director1;
	}
	std::string Movie::geta1(int nr) {
		Movie::reader(nr);
		return actor1;
	}
	std::string Movie::geta2(int nr) {
		Movie::reader(nr);
		return actor2;
	}
	std::string Movie::geta3(int nr) {
		Movie::reader(nr);
		return actor3;
	}
	std::string Movie::getp1(int nr) {
		Movie::reader(nr);
		return plot1;
	}
	std::string Movie::getp2(int nr) {
		Movie::reader(nr);
		return plot2;
	}
	std::string Movie::getp3(int nr) {
		Movie::reader(nr);
		return plot3;
	}
	std::string Movie::getpic(int nr) {
		Movie::reader(nr);
		return picture;
	}
	void Movie::update()
	{

	}



	void Movie::init()
	{

	}
