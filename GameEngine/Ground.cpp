#include "stdafx.h"
#include "Ground.h"

Ground::Ground(float startX,float startY) {
	position = Position2f(startX,startY);
	rectangle.setPosition(position.getAbsPosition());
	cout << position.getAbsPosition().x << endl;
	cout<<	position.getAbsPosition().y << endl;
	rectangle.setSize(Vector2f(2000,300));
	m_Texture.loadFromFile("GroundTexture.jpg");
	rectangle.setTexture(&m_Texture);
}
RectangleShape Ground::getShape() {
	return rectangle;
}
void Ground::moveLeft() {
	RightPressed = true;
}
void Ground::moveRight() {
	LeftPressed = true;
}
void Ground::stopLeft() {
	RightPressed = false;
}
void Ground::stopRight() {
	LeftPressed = false;
}
void Ground::update(float interval) {
	if (RightPressed) {
		//position.x -= g_Speed*interval;
		position.movePos(-g_Speed*interval,0);
	}
	if (LeftPressed) {
		//position.x += g_Speed*interval;
		position.movePos(g_Speed*interval,0);
	}
	rectangle.setPosition(position.getAbsPosition());
}