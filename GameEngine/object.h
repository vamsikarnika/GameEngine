#pragma once
#include"stdafx.h"
#include "Position2f.h"
#include "Mass.h"
#include"Rotation.h"
using namespace sf;
class object {
protected:
	Rotation rotation;
	
public:
	//Mass mass;
	Position2f position;
	Vector2f Scale;
	float angle;
	Texture texture;
	Vector2f Velocity;
	Vector2f Acceleration;
	float mass;
	object();
	int moveFlag = 0;
	void setVelocity(Vector2f v);

	void setAcceleration(Vector2f force, float interval);

	void setAcceleration(Vector2f acceleration);



	CircleShape cs;RectangleShape rs;Sprite ss;ConvexShape cos;
	
	object(Position2f pos,float angle, Vector2f scale, float mas,Vector2f vel,Vector2f acc);
	
	virtual void setTexture(Texture *tex);
	
	virtual CircleShape getCircleShape();
	
	virtual RectangleShape getRectShape();
	
	virtual Sprite getSprite();
	
	virtual void setRotation();
	
	virtual void setPosition2f();
	
	virtual void setPosition2f(Position2f cam_pos, Position2f p_position);
	
	virtual void setPosition2f(Position2f cam_pos);
	
	void onGravity();
	
	virtual ConvexShape getConvexShape();
	
	virtual void Update(float interval);
	
	void setColor(int r, int g, int b);
	
	virtual void setTextureRect(int a, int b, int c, int d);
	
	virtual void UpPressed();

	virtual void DownPressed();

	virtual void LeftPressed();

	virtual void RightPressed();

	virtual void stopUp();

	virtual void stopDown();

	virtual void stopLeft();

	virtual void stopRight();
};