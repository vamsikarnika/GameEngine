#include"stdafx.h"
#include"Circle.h"
Circle::Circle() {
	radius = 10;
	circleshape = CircleShape(10);
}
Circle::Circle(int rad) {
	radius = rad;
	circleshape = CircleShape(radius);
}
Circle::Circle(Position2f pos,float angle,Vector2f scale,float mas,Vector2f vel,Vector2f acc,int sides)
	:object(pos,angle,scale,mas,vel,acc){
	this->sides = sides;
	radius = max(scale.x,scale.y);
	if(sides == 0 || sides == 1 || sides == 2)
		circleshape = CircleShape(radius);
	else {
		circleshape = CircleShape(radius,sides);
	}
	setPosition2f();
}
void Circle::setTexture() {
	circleshape.setTexture(&texture);
}
void Circle::setTextureRect(int a, int b, int c, int d) {
	circleshape.setTextureRect(IntRect(a, b, c, d));
}
CircleShape Circle::getCircleShape() {
	return circleshape;
}
void Circle::setColor(int r,int g,int b) {
	circleshape.setFillColor(Color(r,g,b));
}
void Circle::setPosition2f(Position2f cam_pos, Position2f p_position) {
	Position2f ppos = Position2f(-cam_pos.pos.x + p_position.pos.x, -cam_pos.pos.y + p_position.pos.y);
	circleshape.setPosition(ppos.getAbsPosition());
}
void Circle::setPosition2f() {
	circleshape.setPosition(position.getAbsPosition());
}
void Circle::setRotation() {
	circleshape.setRotation(angle);
}
void Circle::Update(float interval) {
	Vector2f dis;
	dis.x = (Velocity.x)*interval + (Acceleration.x)*(interval*interval) / 2;
	dis.y = (Velocity.y)*interval + (Acceleration.y)*(interval*interval) / 2;
	Velocity.x += Acceleration.x*interval;
	Velocity.y += Acceleration.y*interval;
	cout << "Circle moves with " << Velocity.x << endl;
	position.movePos(dis.x, dis.y);
}