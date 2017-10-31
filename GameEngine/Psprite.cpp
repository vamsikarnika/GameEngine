#include"stdafx.h"
#include"Psprite.h"
#include<iostream>
using namespace std;
Psprite::Psprite() {
	angle = 0;
	texture =Texture();
}
Psprite::Psprite(Position2f pos,float anlge,Vector2f scale,float mass,Vector2f vel,Vector2f acc)
	:object(pos,angle,scale,mass,vel,acc)
{
	texture=Texture();
	setPosition2f();
	setRotation();
}

Sprite Psprite::getSprite() {
	return sprite;
}
void Psprite::LeftPressed() {
	//if(position.x > 100)
	moveLeft = true;
}
void Psprite::RightPressed() {
	//if(position.x < VideoMode::getDesktopMode().width)
	moveRight = true;
}
void Psprite::UpPressed() {
	//if(position.y > 100)
	moveUp = true;
}
void Psprite::DownPressed() {
	//if(position.y  < 1080)
	moveDown = true;
}
void Psprite::stopUp() {
	moveUp = false;
}
void Psprite::stopDown() {
	moveDown = false;
}
void Psprite::stopLeft() {
	moveLeft = false;
}
void Psprite::stopRight() {
	moveRight = false;
}
void Psprite::setRotation() {
	sprite.setRotation(angle);
}
void Psprite::setPosition2f() {
	sprite.setPosition(position.getAbsPosition());
}
void Psprite::setTexture() {
	sprite.setTexture(texture);
}
void Psprite::setTextureRect(int a, int b, int c, int d) {
	sprite.setTextureRect(IntRect(a, b, c, d));
}
void Psprite::Update(float interval) {
	Vector2f dis;
	if (moveLeft) {
		//position.x -= p_Speed*interval;
		dis.x = -1*((Velocity.x)*interval + (Acceleration.x)*(interval*interval) / 2);
		Velocity.x += -1*Acceleration.x*interval;
		//position.movePos(-1 *Velocity.x*interval, 0);
	}
	if (moveRight) {
		//position.x += p_Speed*interval;
		dis.x = (Velocity.x)*interval + (Acceleration.x)*(interval*interval) / 2;
		Velocity.x += Acceleration.x*interval;
		//position.movePos(mass.velocity.x*interval, 0);
	}
	if (moveUp) {
		//position.y -= p_Speed*interval;
		//position.movePos(0, mass.velocity.y*interval);
	}
	if (moveDown) {
		//position.y += p_Speed*interval;
		//position.movePos(0, mass.velocity.y*interval);
	}
	sprite.setTextureRect(IntRect((counter / 10) * 102, 0, 102, 110));
	//dis.x = (Velocity.x)*interval + (Acceleration.x)*(interval*interval) / 2;
	dis.y = (Velocity.y)*interval + (Acceleration.y)*(interval*interval) / 2;
	//Velocity.x += Acceleration.x*interval;
	Velocity.y += Acceleration.y*interval;
	position.movePos(dis);
}
void Psprite::setPosition2f(Position2f cam_pos, Position2f p_position) {
	Position2f ppos = Position2f(-cam_pos.pos.x + p_position.pos.x, -cam_pos.pos.y + p_position.pos.y);
	sprite.setPosition(ppos.getAbsPosition());
}