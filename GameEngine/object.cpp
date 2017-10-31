#include"stdafx.h"
#include"object.h"
object::object() {
	position = Position2f();
	angle = float();
	Scale = Vector2f(0,0);
	mass = 1.0;
	cs = CircleShape(50);
}
object::object(Position2f p_pos, float angle, Vector2f scale, float mas,Vector2f vel,Vector2f acc) {
	position = Position2f(p_pos.pos.x,p_pos.pos.y);
	this->angle = angle;
	mass = mas;
	Scale = scale;
	Velocity = vel;
	Acceleration = acc;
}
void object::onGravity() {
	setAcceleration(Vector2f(0,100));
}

void object::setVelocity(Vector2f v) {
	Velocity = v;
}

void object::setAcceleration(Vector2f force, float interval) {
	Acceleration.x = (force.x / mass);
	Acceleration.y = ((force.y / mass));
	Velocity.x += (Acceleration.x)*interval;
	Velocity.y += (Acceleration.y)*interval;
}

void object::setAcceleration(Vector2f acceleration) {
	Acceleration = acceleration;
}

CircleShape object::getCircleShape() { cout << "Fucked" << endl;return cs; }
RectangleShape object::getRectShape() { return rs; }
Sprite object::getSprite() { return ss; }
ConvexShape object::getConvexShape() { cout <<" SuperClass getConvexShape "<< endl;return cos; }
void object::setTexture(Texture *tex) {}
void object::setColor(int r, int g, int b) {}
void object::setPosition2f(Position2f cam_pos) {}
void object::setPosition2f() { cout << "Error" << endl; }
void object::setRotation() { cout << "SuperClass SetRotation called." << endl; }
void object::setPosition2f(Position2f cam_pos, Position2f p_position) { cout << "help" << endl; }
void object::Update(float interval) {}

void object::setTextureRect(int a, int b, int c, int d) {}
void object::UpPressed() {}

void object::DownPressed() {}

void object::LeftPressed() {}

void object::RightPressed() {}

void object::stopUp() {}

void object::stopDown() {}

void object::stopLeft() {}

void object::stopRight() {}
