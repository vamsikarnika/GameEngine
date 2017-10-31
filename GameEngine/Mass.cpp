#include"stdafx.h"
#include"Mass.h"
Mass::Mass() {
	mass = 1.0;
	/*velocity = Vector2f(0.0,0.0);
	acceleration = Vector2f(0.0,0.0);*/
}
Mass::Mass(float m) {
	mass = m;
	/*velocity = Vector2f(0.0,0.0);
	acceleration = Vector2f(0.0,0.0);*/
}
void Mass::setVelocity(Vector2f v) {
	velocity = v;
}
void Mass::setAcceleration(Vector2f force, float interval) {
	acceleration.x = (force.x / mass);
	acceleration.y = ((force.y / mass));
	velocity.x += (acceleration.x)*interval;
	velocity.y += (acceleration.y)*interval;
}
void Mass::setAcceleration(Vector2f acceleration) {
	this->acceleration = acceleration;
}
Vector2f Mass::getVelocity(Vector2f force,float interval) {
	return velocity;
}
Vector2f Mass::getAcceleration() {
	return acceleration;
}

