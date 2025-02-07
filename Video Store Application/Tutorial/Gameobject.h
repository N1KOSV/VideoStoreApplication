#pragma once

class Gameobject
{
public:
	virtual void update() = 0;
	virtual void draw(int arrow, bool biography, bool comedy, bool crime, bool drama, bool western, float yrf, float yrt) = 0;
	virtual void init() = 0;
};