#include "Widget.h"
#include <string>

class Button : Widget{

public:
	void update();
	void draw(int i, float pos_x, float pos_y, float height, float width, std::string txt, bool pressed);
	void colour();
	void setcolour(float r, float g, float b);
	bool ispressed(float x, float y);
};