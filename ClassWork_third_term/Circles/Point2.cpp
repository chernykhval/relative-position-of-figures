#include "Point2.h"
#include <cmath>

Point2::Point2() : _x(0), _y(0){}
Point2::Point2(int x, int y) : _x(x), _y(y) {}
Point2::Point2(const Point2& other) {
	_x = other._x;
	_y = other._y;
}

float Point2::distance_to(const Point2& other) {
	int dx = _x - other._x;
	int dy = _y - other._y;
	float distance = sqrt(dx * dx + dy * dy);
	return distance;
}