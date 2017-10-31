#pragma once
#include <SFML/Graphics.hpp>
#include"Position2f.h"
using namespace sf;
class Player
{
private:

	Sprite p_Sprite;
	Texture p_Texture;
	bool moveLeft,moveRight,moveUp,moveDown;

	float p_Speed;

public:
	Position2f position;
	Player();
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
	void setPosition2f(Position2f cam_pos,Position2f position);
	void Update(float interval);
};
