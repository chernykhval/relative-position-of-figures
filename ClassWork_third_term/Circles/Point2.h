#pragma once

class Point2 {
private:
	int _x, _y;
public:
	Point2();
	Point2(int x, int y);
	Point2(const Point2& other);

	float distance_to(const Point2&);
};