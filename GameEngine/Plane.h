#pragma once
#pragma once
#include "stdafx.h"
#include "object.h"
#include<cmath>
#define PI 3.14159265
using namespace sf;
class Plane : public object {
private:
	
public:
	RectangleShape rectangleshape;
	Texture texture;
	Plane();
	Plane(Position2f pos, float angle, Vector2f scale,float mass,Vector2f vel,Vector2f acc) ;
	void setSize(Vector2f s_size);
	void setRotation();
	void setTexture();
	void setTextureRect();
	RectangleShape getRectShape();
	void setTextureRect(int a, int b, int c, int d);
	void setColor(int r, int g, int b);
	void setPosition2f();
	void setPosition2f(Position2f cam_position, Position2f Pos);
	void Update(float interval);
	bool onCollision(Position2f point);
	float getminY(float x);
};