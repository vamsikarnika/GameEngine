#include"stdafx.h"
#include"Position2f.h"

Position2f::Position2f() {
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	pos.x = 0;pos.y = 0;
	abs_pos.x = pos.x + resolution.x / 2;
	abs_pos.y = pos.y + resolution.y / 2;
	leftBorder = 0;rightBorder = resolution.x;
	topBorder = 0;bottomBorder = resolution.y;
}
Position2f::Position2f(float x,float y) {
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	pos.x = x;pos.y = y;
	abs_pos.x = pos.x + resolution.x / 2;
	abs_pos.y = pos.y + resolution.y / 2;
}
Position2f::Position2f(Vector2f vec) {
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	pos.x = vec.x;pos.y = vec.y;
	abs_pos.x = pos.x + resolution.x / 2;
	abs_pos.y = pos.y + resolution.y / 2;
}
Position2f::Position2f(string start,float ppos) {
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	if (start == "left") {
		pos.x = -resolution.x/2;pos.y = ppos;
	}
	else if (start == "right") {
		pos.x = resolution.x;pos.y = ppos;
	}
	else if (start == "up") {
		pos.x = ppos;pos.y = -resolution.y/2;
	}
	else if (start == "down") {
		pos.x = -ppos;pos.y = resolution.y;
	}
	else {
		cout << "string should be left/right/up/down" << endl;
	}
	abs_pos.x = pos.x + resolution.x / 2;
	abs_pos.y = pos.y + resolution.y / 2;

}
Vector2f Position2f::getPos() {
	return pos;
}
Vector2f Position2f::getAbsPosition() {
	return abs_pos;
}
void Position2f::movePos(float x,float y) {
	pos.x += x;
	pos.y += y;
	abs_pos.x += x;
	abs_pos.y += y;
}
void Position2f::movePos(Vector2f shift) {
	movePos(shift.x, shift.y);
}
