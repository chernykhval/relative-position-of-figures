#pragma once

#include "Point2.h"

class Circle {
private:
	Point2 _position;
	int _radius;
public:
	Circle();
	Circle(Point2 position, int radius);

	int get_radius();
	Point2 get_position();
};
