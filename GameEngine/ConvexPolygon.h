#pragma once
#include "stdafx.h"
#include "object.h"
using namespace sf;
class ConvexPolygon :public  object {
private:
	ConvexShape convex;
public:

	int sides;
	vector<Position2f> edges;
	ConvexPolygon();
	ConvexPolygon(Position2f pos,vector<Vector2f> vec,int sides, float angle, float mass,Vector2f vel,Vector2f acc);
	void setNodes();
	void setPosition2f();
	void setTexture();
	void setPosition2f(Position2f cam_pos,Position2f p_position);
	ConvexShape getConvexShape();
	void Update(float interval);
	Position2f RelativeToCam(Position2f p_position, Position2f cam_position);
};
