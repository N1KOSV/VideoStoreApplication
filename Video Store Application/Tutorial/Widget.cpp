#include "Widget.h"
#include "Button.h"
#include "Slider.h"

Slider* b = new Slider;
//Depending on the data, the correct draw operation is selected so that a Widget object can be both a button and a slider. 
//Some functions that apply to both classes are saved as slider functions to be executed quicker
void Widget::draw(int i, float B_pos_x, float B_pos_y, float height, float width, std::string txt, bool pressed) {
	Button* a = new Button;
	a->draw(i, B_pos_x, B_pos_y, height, width, txt, pressed);
}
void Widget::draw(float pos_x, float pos_y, float pos_p, std::string title) {
	Slider* b = new Slider;
	b->draw(pos_x, pos_y, pos_p, title);
}

float Widget::getposx() {
	return B_pos_x;
}

float Widget::getposy() {
	return B_pos_y;
}

float Widget::getwidth() {
	return width;
}

float Widget::getheight() {
	return height;
}
float Widget::restore(float pos) {
	return pos;
}
float Widget::getYr1() {
	return b->getYr1();
}