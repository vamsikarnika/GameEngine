#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class Mass {
private:

	
public:
	float mass;
	Vector2f acceleration;
	Vector2f velocity;
	Mass();
	Mass(float m);

	void setVelocity(Vector2f v);

	void setAcceleration(Vector2f force, float interval);

	void setAcceleration(Vector2f acceleration);

	Vector2f getVelocity(Vector2f force,float interval );

	Vector2f getAcceleration();
};
