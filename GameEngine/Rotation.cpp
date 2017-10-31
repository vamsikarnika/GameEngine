#include"stdafx.h"
#include"Rotation.h"
Rotation::Rotation() {
	rotation = Vector2f(0,0);
}
Rotation::Rotation(float x, float y) {
	rotation = Vector2f(x,y);
}