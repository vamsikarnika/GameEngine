#include "stdafx.h"
#include "Player.h"
#include<iostream>
using namespace std;
Player::Player() {
	position = Position2f(0,-150);
	//cout << position.getAbsPosition().x << endl;
	//cout << position.getAbsPosition().y << endl;
	p_Speed = 500;
	p_Texture.loadFromFile("sonic_walk.png");
	p_Sprite.setTexture(p_Texture);
	p_Sprite.setTextureRect(IntRect(0,0,102,110));
	p_Sprite.setPosition(position.getAbsPosition());
}
Sprite Player::getSprite() {
	return p_Sprite;
}

void Player::LeftPressed() {
	//if(position.x > 100)
		moveLeft = true;
}
void Player::RightPressed() {
	//if(position.x < VideoMode::getDesktopMode().width)
		moveRight = true;
}
void Player::UpPressed() {
	//if(position.y > 100)
	moveUp = true;
}
void Player::DownPressed() {
	//if(position.y  < 1080)
		moveDown = true;
}
void Player::stopUp() {
	moveUp = false;
}
void Player::stopDown() {
	moveDown = false;
}
void Player::stopLeft() {
	moveLeft = false;
}
void Player::stopRight() {
	moveRight = false;
}
void Player::Update(float interval) {
	if (moveLeft) {
		//position.x -= p_Speed*interval;
		position.movePos(-1*p_Speed*interval,0);
	}
	if (moveRight) {
		//position.x += p_Speed*interval;
		position.movePos(p_Speed*interval, 0);
	}
	if (moveUp) {
		//position.y -= p_Speed*interval;
		position.movePos(0,-p_Speed*interval);
	}
	if (moveDown) {
		//position.y += p_Speed*interval;
		position.movePos(0,p_Speed*interval);
	}
	p_Sprite.setTextureRect(IntRect((counter/10) * 102, 0, 102, 110));
	//p_Sprite.setTextureRect(IntRect((counter / 20) * 90, 0, 90, 75));
	//p_Sprite.setPosition(position.getAbsPosition());
}
void Player::setPosition2f(Position2f cam_pos,Position2f p_position) {
	Position2f ppos = Position2f(cam_pos.pos.x - p_position.pos.x, cam_pos.pos.y - p_position.pos.y);
	p_Sprite.setPosition(ppos.getAbsPosition());
}