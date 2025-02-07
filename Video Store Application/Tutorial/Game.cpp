#include "Game.h"
#include "graphics.h"
#include "config.h"
#include "menu.h"
#include "defines.h"
#include "Movie.h"
#include "Button.h"
float pos_from;
float pos_to;

void Game::update()
{//If movies havent been initialised, they are initialised
	if (!player) {
		player = new Movie();
	}
	
	if (player) {
		player->update();
	}
	//Get the mouse location
	graphics::MouseState ms;
	graphics::getMouseState(ms);

	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);
	//If the menu button is pressed and there is no menu, the menu is initialised based on the last values of each button
	if (contains(mx, my) && ms.button_left_pressed && !highlighted) {
		bio = obio;
		com = ocom;
		cri = ocri;
		dra = odra;
		wes = owes;
		highlighted = true;
		//create menu
	}
	//If highlighted = false and menu is pressed again
	else if (contains(mx, my) && ms.button_left_pressed && highlighted) {
		dest = true;
		//move menu up 
	}
	if (Rarrow(mx, my) && ms.button_left_pressed) { next = true; }
	if (Larrow(mx, my) && ms.button_left_pressed) { previous = true; }

	if (ms.button_left_pressed) {
		//If the reset button is pressed, reset
		if (clearf(mx, my) && highlighted) {
			reset = true;
		}
	}
	if (ms.button_left_pressed) {
		if (savef(mx, my) && highlighted) {// If the save button is pressed, save the selection and then close the Menu
			dest = true;
		}
	}
	//If the button is pressed on a slider, move said slider to the location of the mouse. If the reset button is pressed, reset the sliders
	if (ms.button_left_down) {
		if ((mx > 210.0f) && (mx < 480.0f)) {
			if ((my > 183.9f) && (my < 202.0f)) {
				pos_from = mx;
			}
			else if ((my > 293.9f) && (my < 312.1f)) {
				pos_to = mx;
			}
		}
		else if (pos_from == 0) {
			pos_from = 210.0f;
			pos_to = 450.0f;
		}
	}
}
void Game::draw()
{//The background and the arrows are drawn
	graphics::MouseState ms;
	graphics::getMouseState(ms);

	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "background.png";
	br.outline_opacity = 0.0f;

	//draw background
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	graphics::Brush l_r_br;
	l_r_br.texture = std::string(ASSET_PATH) + "arrow.png";
	l_r_br.outline_opacity = 0.0f;
	graphics::Brush d;
	d.texture = "";
	SET_COLOR(d.fill_color, 1.0f, 1.0f, 1.0f);
	d.fill_opacity = 0.3f;
	d.outline_opacity = 1.0f;
	
	
	graphics::drawRect(CANVAS_WIDTH / 2 - 350, CANVAS_HEIGHT / 4, 40, 40, l_r_br);
	graphics::drawDisk(l_x, same_y, 20, d);
	graphics::setOrientation(180);
	
	
	graphics::drawRect(CANVAS_WIDTH / 2 + 350, CANVAS_HEIGHT / 4, 40, 40, l_r_br);
	graphics::drawDisk(r_x, same_y, 20, d);
	graphics::resetPose();


	//draw the movies
	if (player) {
		player->draw(arrow_, bio, com, cri, dra, wes, pos_from, pos_to);
	 }	

	//if menu is opened
	if (highlighted) {
		//if the menu is reset, set everything to false, and restart the movie draw process
		if (reset == true) {
			bio = false;
			com = false;
			cri = false;
			dra = false;
			wes = false;
			player->draw(arrow_, bio, com, cri, dra, wes, pos_from, pos_to);
			reset = false;
		}
			
		Menu* menu = new Menu();
		menu->draw(1.0f, 1,bio,com,cri,dra,wes, pos_from,pos_to);
		if (ms.button_left_pressed) {
			Bio(mx, my);
			}
		//If the menu is to be destroyed, it gets deleted and drawn with zero size
		if (dest == true) {
			menu->~Menu();
			Menu* menu = new Menu();
			menu->draw(0.0f,1,bio,com,cri,dra,wes, pos_from, pos_to);
			highlighted = false;
			dest = false;
		}
	}
	if (next)//If the right arrow is pressed, draw the movies again, but the new central one, is the one on the right of the original central movie
	{
		Movie* movie = new Movie;
		arrow_ += 1;
		if (arrow_ > 8) { arrow_ = 1; }
		movie->draw(arrow_, bio, com, cri, dra, wes, pos_from, pos_to);
		next = false;
	}
	// if the left arrow is pressed, draw the movies again, but the new central one, is the one on the left of the original central movie
	if (previous)
	{
		Movie* movie = new Movie;
		arrow_ -= 1;
		if (arrow_ < 0) { arrow_ = 8; }
		movie->draw(arrow_, bio, com, cri, dra, wes, pos_from, pos_to);
		previous = false;
	}
	// if the menu is to be closed, draw the movies according to the filters
	if (dest)
	{
		Movie* movie = new Movie;
		movie->draw(arrow_, bio, com, cri, dra, wes, pos_from, pos_to);
	}	
	//draw menu button
	graphics::Brush bru;
	bru.outline_opacity = 0.5f;
	SET_COLOR(bru.fill_color, 0.5f, 0.5f, 0.5f);

	graphics::drawRect(CANVAS_WIDTH/2, 8, 600, 15, bru);
	graphics::drawText(CANVAS_WIDTH / 2, 11, 12, std::string("MENU"), br); 
}
void Game::init()
{
	graphics::setFont(std::string(ASSET_PATH) + "Font.ttf");
}
Game::Game()
{
}
Game::~Game()
{
	if (player)
	{
		delete player;
	}
}
//Check if the menu button has been pressed
bool Game::contains(float x, float y)
{
	if ((x > CANVAS_WIDTH / 2 - 300) && (x < CANVAS_WIDTH / 2 + 300)) {
		if ((y > 0) && (y < 15)) {
			return true;
		}
	}
	return false;
}
//If the clear button was pressed, clear all the filters
bool Game::clearf(float x, float y)
{
	if ((x > 670) && (x < 790)) {
		if ((y > 300) && (y < 340)) {
			bio = true;
			com = true;
			cri = true;
			dra = true;
			wes = true;
			reset = true;
			pos_from = 210.0f;
			pos_to = 450.0f;
			return true;
		}
	}
	return false;
}
//if the save button was pressed, sava all the current filters
bool Game::savef(float x, float y)
{
	if ((x > 670) && (x < 790)) {
		if ((y > 350) && (y < 390)) {
			obio = bio;
			ocom = com;
			ocri = cri;
			odra = dra;
			owes = wes;
			return true;
		}
	}
	return false;
}
bool Game::Rarrow(float x, float y) {

	return distance(x, y, r_x, same_y) < 20;
}
bool Game::Larrow(float x, float y)
{
	return distance(x, y, l_x, same_y) < 20;
}
//If a button is pressed, change the corresponding boolean
void Game::Bio(float x, float y) {
	if ((y > 99) && (y < 131)) {
		if ((x > 219) && (x < 301)) {
			bio = not bio;
		}
		else if ((x > 309) && (x < 391)) {
			com = not com;
		}
		else if ((x > 399) && (x < 481)) {
			cri = not cri;
		}
		else if ((x > 489) && (x < 571)) {
			dra = not dra;
		}
		else if ((x > 579) && (x < 661)) {
			wes = not wes;
		}
	}
}