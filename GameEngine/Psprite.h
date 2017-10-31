#pragma once
#include"stdafx.h"
#include"object.h"
using namespace sf;
class Psprite:public object {
private:
	bool moveLeft, moveRight,moveUp,moveDown;
public:
	Sprite sprite;
	Texture texture;
	Psprite();
	Psprite(Position2f pos,float angle,Vector2f scale,float mass,Vector2f vel, Vector2f acc);
	int counter = 0;
	Sprite getSprite();

	void UpPressed();

	void DownPressed();

	void LeftPressed();

	void RightPressed();

	void SpacePressed();

	void stopUp();

	void stopDown();

	void stopLeft();

	void stopRight();

	void setTexture();

	void setRotation();

	void setPosition2f();

	void setTextureRect(int a,int b,int c,int d);

	void setPosition2f(Position2f cam_pos, Position2f position);

	void Update(float interval);
};
