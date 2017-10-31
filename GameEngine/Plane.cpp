#include"stdafx.h"
#include"Plane.h"
Plane::Plane() {
	rectangleshape = RectangleShape();

}
Plane::Plane(Position2f pos,float angle,Vector2f scale,float mass,Vector2f vel,Vector2f acc)
	:object(pos, angle,scale,mass,vel,acc) {
	setPosition2f();
	setRotation();
	rectangleshape.setSize(Scale);
}
void Plane::setSize(Vector2f s_size) {
	rectangleshape.setSize(s_size);
}
void Plane::setRotation() {
	rectangleshape.setRotation(angle);
}
RectangleShape Plane::getRectShape() {
	return rectangleshape;
}
void Plane::setTexture() {
	rectangleshape.setTexture(&texture);
}
void Plane::setTextureRect(int a, int b, int c, int d) {
	rectangleshape.setTextureRect(IntRect(a, b, c, d));
}
void Plane::setColor(int r, int g, int b) {
	rectangleshape.setFillColor(Color(r,g,b));
}
void Plane::setPosition2f() {
	rectangleshape.setPosition(position.getAbsPosition());
}
void Plane::setPosition2f(Position2f cam_pos,Position2f abs_pos) {
	Position2f ppos = Position2f(-cam_pos.pos.x + abs_pos.pos.x, -cam_pos.pos.y + abs_pos.pos.y);
	rectangleshape.setPosition(ppos.getAbsPosition());
}
bool Plane::onCollision(Position2f point) {
	return false;
}
void Plane::Update(float interval) {
	//setPosition2f();
	Vector2f dis;
	dis.x = (Velocity.x)*interval + (Acceleration.x)*(interval*interval)/2;
	dis.y = (Velocity.y)*interval + (Acceleration.y)*(interval*interval) / 2;
	Velocity.x += Acceleration.x*interval;
	Velocity.y += Acceleration.y*interval;
	position.movePos(dis.x,dis.y);
}
float Plane::getminY(float x) {
	float y = (x - position.pos.x)*tan(angle*PI / 180.0) + position.pos.y;
	return y;
}