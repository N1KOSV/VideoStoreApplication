#include "Button.h"
#include "graphics.h"
#include "defines.h"
#include "Game.h"
#include "config.h"
#include "menu.h"
#include "Movie.h"


graphics::Brush m_br;
//Initialise the Button
void Button::draw(int i, float B_pos_x, float B_pos_y, float height, float width, std::string txt, bool pressed)
{
	graphics::Brush m_br;
	m_br.outline_opacity = 1.0f;
	m_br.outline_width = 2.0f;
	//The colour is decided on whether it was pressed and the button type(filter, save, exit)
	if (!pressed) {
		if (i == 1) { SET_COLOR(m_br.fill_color, 0.85f, 0.46f, 0.11f); }
		else if (i == 2) { SET_COLOR(m_br.fill_color, 0.3f, 0.3f, 0.3f); }
		else { SET_COLOR(m_br.fill_color, 0.6f, 0.7f, 0.4f); }
		graphics::drawRect(B_pos_x, B_pos_y, height, width, m_br);
		SET_COLOR(m_br.fill_color, 1.0f, 1.0f, 1.0f);
		graphics::drawText(B_pos_x - (width / 2.0f) - 25, B_pos_y + 5.0f, height / 5.0f, std::string(txt), m_br);
	}
	else {
		SET_COLOR(m_br.fill_color, 1.0f, 1.0f, 1.0f);
		graphics::drawRect(B_pos_x, B_pos_y, height, width, m_br);
		if (i == 1) { SET_COLOR(m_br.fill_color, 0.1f, 1.0f, 0.6f);
		graphics::drawText(B_pos_x - (width / 2.0f) - 25, B_pos_y + 5.0f, height / 5.0f, std::string(txt), m_br);
			SET_COLOR(m_br.outline_color, 0.1f, 1.0f, 0.6f);
		}
		else if (i == 2) {SET_COLOR(m_br.fill_color, 0.1f, 0.0f, 0.6f);
		graphics::drawText(B_pos_x - (width / 2.0f) - 25, B_pos_y + 5.0f, height / 5.0f, std::string(txt), m_br);
			SET_COLOR(m_br.outline_color, 0.1f, 0.0f, 0.6f);
		}
		else { SET_COLOR(m_br.fill_color, 1.0f, 0.1f, 0.0f); 
		graphics::drawText(B_pos_x - (width / 2.0f) - 25, B_pos_y + 5.0f, height / 5.0f, std::string(txt), m_br);
			SET_COLOR(m_br.outline_color, 0.1f, 0.1f, 0.0f);
		}
		SET_COLOR(m_br.fill_color, 1.0f, 1.0f, 1.0f);
		graphics::drawRect(B_pos_x, B_pos_y, height, width, m_br);
		
	}

}
