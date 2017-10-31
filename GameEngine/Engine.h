#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h";
#include "Ground.h"
#include"Circle.h"
#include"Psprite.h"
#include"Plane.h"
#include"ConvexPolygon.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
using namespace sf;

class Engine
{
private:

	// A regular RenderWindow
	RenderWindow m_Window;
	bool moveLeft, moveRight;
	float drawDist;
	float cam_speed = 500;
	Position2f cam_position;
	Vector2f resolution;
	// Declare a sprite and a Texture for the background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
	// An instance of Bob
	Text hud;
	sf::ConvexShape convex;
	Font font;
	vector<int> vobj;
	vector<object*> vec;
	Psprite m_Bob = Psprite(Position2f(0,150),0,Vector2f(500,0),100,Vector2f(500,0),Vector2f(0,0));
	//Plane plane1 = Plane(Position2f(-960,250),30,Vector2f(500,300),100.0);
	/*Plane plane2 = Plane(Position2f(-500, 250), Vector2f(2000, 300), Vector2f(0, 0));
	Plane pole1 = Plane(Position2f(100, -250), Vector2f(20, 800), Vector2f(0, 0));
	Plane pole2 = Plane(Position2f(600, -250), Vector2f(20, 800), Vector2f(0, 0));
	Plane Board0 = Plane(Position2f(60, -300), Vector2f(600, 440), Vector2f(0, 0));
	Plane Board = Plane(Position2f(80,-280),Vector2f(560,400),Vector2f(0,0));*/
	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	// The Engine constructor
	object* objj[100];
	Engine();
	void LeftPressed();

	void RightPressed();

	void stopLeft();

	void stopRight();
	// start will call all the private functions
	void start();

};