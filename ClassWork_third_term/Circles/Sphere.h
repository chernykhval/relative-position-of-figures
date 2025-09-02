#pragma once

#include "Point3.h"

class Sphere {
private:
	Point3 _position;
	int _radius;
public:
	Sphere();
	Sphere(Point3 position, int radius);

	int get_radius();
	Point3 get_position();
};
