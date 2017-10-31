#pragma once
#include"stdafx.h"
#include<SFML/Graphics.hpp>
using namespace sf;
class Rotation {
private:
	Vector2f rotation;
public:
	Rotation();
	Rotation(float x,float y);
};
