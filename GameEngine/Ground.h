#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h";
class Ground
{
private:
	RectangleShape rectangle;
	Position2f position;
	Texture m_Texture ;
	float g_Speed = 400;
	bool RightPressed;
	bool LeftPressed;
public:
	Ground(float startX,float startY);

	RectangleShape getShape();

	void moveLeft();

	void moveRight();

	void stopLeft();

	void stopRight();
	void update(float interval);

};