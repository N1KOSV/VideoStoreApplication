#include "menu.h"
#include "graphics.h"
#include "defines.h"
#include "Widget.h"
#include "Button.h"
#include "Slider.h"

using namespace std;
void Menu::update()
{
}
//Initialise all the Widgets
Widget* western = new Widget;
Widget* drama = new Widget;
Widget* crime = new Widget;
Widget* comedy = new Widget;
Widget* biography = new Widget;
Widget* save = new Widget;
Widget* reset = new Widget;
Widget* yearfrom = new Widget();
Widget* yearto = new Widget();



void Menu::draw(float i, int k, bool bio, bool com, bool cri, bool dra, bool wes, float pos_from, float pos_to)
{
	//Draw all the menu buttons and sliders
	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);
		graphics::Brush b;
		b.texture = "";
		b.outline_opacity = 1.0f;
		b.fill_opacity = 0.8f;
		SET_COLOR(b.fill_color, 0.5f, 0.5f, 0.5f);
		graphics::Brush br;
		br.texture = "";
		br.outline_opacity = 0.0f;
		menu_sx = 600.0f;
		menu_sy = 400.0f;

		graphics::drawRect(CANVAS_WIDTH /2, CANVAS_HEIGHT / 2 - 50, menu_sx, menu_sy, b);
		save->draw(1, 730.0f, 370.0f, 120.0f, 40.0f,"Save",false);
		reset->draw(3, 730.0f, 320.0f, 120.0f, 40.0f,"Reset", false);

		biography->draw(2, 260.0f, 110.0f, 80.0f, 20.0f,"Biography", bio);
		comedy->draw(2, 350.0f, 110.0f, 80.0f, 20.0f,"Comedy", com);
		crime->draw(2, 440.0f, 110.0f, 80.0f, 20.0f,"Crime", cri);
		drama->draw(2, 530.0f, 110.0f, 80.0f, 20.0f,"Drama", dra);
		western->draw(2, 620.0f, 110.0f, 80.0f, 20.0f,"Western", wes);

		yearfrom->draw( 210.0f, 190.0f, pos_from, "Year From: ");
		yearto->draw( 210.0f, 300.0f, pos_to, "Year To: ");
		string yr = to_string(getYr1());
		yr = to_string(getYr2());
}

void Menu::pressed(bool a) {
	if (a) {
		a = false;
	}
	else {
		a = true;
	}
}
//Return the top slider location
int Menu::getYr1()
{
	return yearfrom->getYr1();
}
//Return the bottom slider location
int Menu::getYr2()
{
	return yearto->getYr1();
}

Menu::Menu() {

}
Menu::~Menu()
{
	delete menu;
}

