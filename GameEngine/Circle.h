#pragma once
#include "stdafx.h"
#include "object.h"
using namespace sf;
class Circle: public object {
private:
public:
	CircleShape circleshape;
	int radius;
	int sides;
	Circle();
	Circle(int rad);
	Circle(Position2f pos, float angle, Vector2f scale,float mass,Vector2f vec,Vector2f acc,int pol_sides);
	void setTexture();
	void setRotation();
	CircleShape getCircleShape();
	void setColor(int r,int g,int b);
	void setTextureRect(int a, int b, int c, int d);
	void setPosition2f();
	void setPosition2f(Position2f cam_position,Position2f Pos);
	void Update(float interval);
};

