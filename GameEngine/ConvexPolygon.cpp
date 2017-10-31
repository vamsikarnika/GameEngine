#include"stdafx.h"
#include"ConvexPolygon.h"
ConvexPolygon::ConvexPolygon() 
	:object(Position2f(0,0), 0, Vector2f(0,0),1,Vector2f(0,0),Vector2f(0,0)){
	sides = 0;
}
ConvexPolygon::ConvexPolygon(Position2f pos, vector<Vector2f> v, int sides, float angle,float mass,Vector2f vel,Vector2f acc)
	:object(pos, angle, Vector2f(0, 0), mass,vel,acc){
	this->sides = sides;
	//cout << sides << "	" << v.size() << endl;
	for (int i = 0; i < sides;i++) {
		//cout << v[i].x << "			" << v[i].y << endl;//
		edges.push_back(Position2f(v[i]));
	}
	setNodes();
	setPosition2f();
}
void ConvexPolygon::setNodes() {
	convex.setPointCount(sides);
}
void ConvexPolygon::setTexture() {
	convex.setTexture(&texture);
}
void ConvexPolygon::setPosition2f() {
	cout << sides << endl;
	for (int i = 0; i < sides;i++) {
		Vector2f vv = edges[i].getAbsPosition();
		cout << edges[i].pos.y << "	" << vv.y << endl;
  		convex.setPoint(i,vv);
	}
	convex.setPosition(position.getAbsPosition());
}
void ConvexPolygon::setPosition2f(Position2f cam_position,Position2f p_position) {
	/*for (int i = 0; i < sides; i++) {
		convex.setPoint(i,RelativeToCam(edges[i],cam_position).getAbsPosition());
	}*/
	Position2f ppos = Position2f(-cam_position.pos.x + p_position.pos.x, -cam_position.pos.y + p_position.pos.y);
	convex.setPosition(ppos.getAbsPosition());
}
ConvexShape ConvexPolygon::getConvexShape() {
	cout << "Subclass getConvexShape" << endl;
	return convex;
}
Position2f ConvexPolygon::RelativeToCam(Position2f p_position,Position2f cam_position) {
	Position2f ppos = Position2f(-cam_position.pos.x + p_position.pos.x, -cam_position.pos.y + p_position.pos.y);
	return ppos;
}
void ConvexPolygon::Update(float interval) {
	Vector2f dis;
	dis.x = (Velocity.x)*interval + (Acceleration.x)*(interval*interval) / 2;
	dis.y = (Velocity.y)*interval + (Acceleration.y)*(interval*interval) / 2;
	Velocity.x += Acceleration.x*interval;
	Velocity.y += Acceleration.y*interval;
	for (int i = 0; i < sides; i++) {
		edges[i].movePos(dis);
	}
}