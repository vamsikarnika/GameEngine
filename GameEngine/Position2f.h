#pragma once
#include"stdafx.h"
#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Position2f {
private:
	//Vector2f pos;
	Vector2f resolution;
	Vector2f abs_pos;
	float leftBorder;
	float rightBorder;
	float topBorder;
	float bottomBorder;
public:
	Vector2f pos;
	Position2f();
	Position2f(float x,float y);
	Position2f(Vector2f pos);
	Position2f(string start,float y);
	Vector2f getPos();
	Vector2f getAbsPosition();
	void movePos(float x,float y);
	void movePos(Vector2f shift);
};
