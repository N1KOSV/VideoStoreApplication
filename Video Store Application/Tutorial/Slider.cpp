#include "Button.h"
#include "graphics.h"
#include "defines.h"
#include "Game.h"
#include "config.h"
#include "menu.h"
#include "Movie.h"
#include "Slider.h"
using namespace std;
graphics::Brush m_br2;
void Slider::draw(float pos_x, float pos_y, float pos_p, std::string title)
{
	//Draw the slider line , and vertical lines in every 10 years mark as well as the moving part and the year is shown above it
	m_br2.outline_opacity = 1.0f;
	m_br2.outline_width = 2.0f;
	SET_COLOR(m_br2.fill_color, 1.0f, 1.0f, 1.0f);
	SET_COLOR(m_br2.outline_color, 1.0f, 1.0f, 1.f);
	m_br2.outline_opacity = 0.2f;
	graphics::drawLine(pos_x, pos_y - 10.0f, pos_x, pos_y, m_br2);
	graphics::drawLine(pos_x + 40.0f, pos_y - 10.0f, pos_x + 40.0f, pos_y, m_br2);
	graphics::drawLine(pos_x + 80.0f, pos_y - 10.0f, pos_x + 80.0f, pos_y, m_br2);
	graphics::drawLine(pos_x + 120.0f, pos_y - 10.0f, pos_x + 120.0f, pos_y, m_br2);
	graphics::drawLine(pos_x + 160.0f, pos_y - 10.0f, pos_x + 160.0f, pos_y, m_br2);
	graphics::drawLine(pos_x + 200.0f, pos_y - 10.0f, pos_x + 200.0f, pos_y, m_br2);
	graphics::drawLine(pos_x + 240.0f, pos_y - 10.0f, pos_x + 240.0f, pos_y, m_br2);
	m_br2.fill_opacity = 1.0f;
	graphics::drawRect(pos_x + 120.0f, pos_y + 3.0f, 240.0f, 4.0f,m_br2);
	graphics::drawRect(pos_p, pos_y + 3.0f, 5.0f, 18.0f, m_br2);
	// The year is calculated using the slider location
	year = 1960.0f + (pos_p - pos_x) / 4.0f;
	string yr = to_string (year);
	graphics::drawText(pos_p - 10.0f, pos_y - 16.0f, 12.0f,yr, m_br2);
	graphics::drawText(pos_x, pos_y - 40.0f, 23.0f,title, m_br2);
	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);
}


//The slider location is returned
int Slider::getYr1() {
	return year;
}