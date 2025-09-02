#include "Point2.h"
#include "Point3.h"
#include "Circle.h"
#include "Sphere.h"
#include <iostream>

enum class IntersectionType{
	No_Intersection,
	One_Inside_Other,
	Intersection,
	External_Tangency,
	Internal_Tangency
};

template <typename T>
IntersectionType intersection_betwen(T first, T second) {
	int big_r = first.get_radius();
	int small_r = second.get_radius();

	float distance = first.get_position().distance_to(second.get_position());

	if (big_r < small_r) {
		int temp = big_r;
		big_r = small_r;
		small_r = temp;
	}

	if (distance > big_r + small_r) {
		return IntersectionType::No_Intersection;
	}
	else if (distance == big_r + small_r) {
		return IntersectionType::External_Tangency;
	}
	else if (distance < big_r - small_r) {
		return IntersectionType::One_Inside_Other;
	}
	else if (distance == big_r - small_r) {
		return IntersectionType::Internal_Tangency;
	}
	else if (distance > big_r - small_r && distance < big_r + small_r){
		return IntersectionType::Intersection;
	}

	throw std::exception("Error type");
}

void print_intersection(IntersectionType result) {
	switch (result) {
	case IntersectionType::No_Intersection:
		std::cout << "No_Intersection" << std::endl;
		break;
	case IntersectionType::One_Inside_Other:
		std::cout << "One_Inside_Other" << std::endl;
		break;
	case IntersectionType::Intersection:
		std::cout << "Intersection" << std::endl;
		break;
	case IntersectionType::External_Tangency:
		std::cout << "External_Tangency" << std::endl;
		break;
	case IntersectionType::Internal_Tangency:
		std::cout << "Internal_Tangency" << std::endl;
		break;
	default:
		std::cout << "Error" << std::endl;
		break;
	}
}

int main() {
	Point2 pos_1 = Point2(3, 4);
	Point2 pos_2 = Point2(0, 0);

	std::cout << "Point2 tests\nexpected: 5\nactual: " << pos_1.distance_to(pos_2) << "\n" << std::endl;

	std::cout << "Circle tests\nexpected: No_Intersection\nactual: ";
	Circle first_circle = Circle(Point2(3, 4), 1);
	Circle second_circle = Circle(Point2(0, 0), 1);
	IntersectionType case_1 = intersection_betwen(first_circle, second_circle);
	print_intersection(case_1);

	std::cout << "expected: One_Inside_Other\nactual: ";
	first_circle = Circle(Point2(1, 1), 2);
	second_circle = Circle(Point2(0, 0), 5);
	IntersectionType case_2 = intersection_betwen(first_circle, second_circle);
	print_intersection(case_2);

	std::cout << "expected: Intersection\nactual: ";
	first_circle = Circle(Point2(3, 0), 2);
	second_circle = Circle(Point2(0, 1), 4);
	IntersectionType case_3 = intersection_betwen(first_circle, second_circle);
	print_intersection(case_3);

	std::cout << "expected: External_Tangency\nactual: ";
	first_circle = Circle(Point2(2, 0), 1);
	second_circle = Circle(Point2(0, 0), 1);
	IntersectionType case_4 = intersection_betwen(first_circle, second_circle);
	print_intersection(case_4);

	std::cout << "expected: Internal_Tangency\nactual: ";
	first_circle = Circle(Point2(1, 0), 2);
	second_circle = Circle(Point2(0, 0), 3);
	IntersectionType case_5 = intersection_betwen(first_circle, second_circle);
	print_intersection(case_5);
	std::cout << std::endl;

	Point3 point_1 = Point3(3, 4, 12);
	Point3 point_2 = Point3(0, 0, 0);

	std::cout << "Point3 tests\nexpected: 13\nactual: " << point_1.distance_to(point_2) << "\n" << std::endl;

	std::cout << "Sphere tests\nexpexted: No_Intersection\nactual: ";
	Sphere first_sphere = Sphere(Point3(0, 0, 10), 2);
	Sphere second_sphere = Sphere(Point3(0, 0, 0), 3);
	case_1 = intersection_betwen(first_sphere, second_sphere);
	print_intersection(case_1);

	std::cout << "expected: One_Inside_Other\nactual: ";
	first_sphere = Sphere(Point3(0, 0, 0), 5);
	second_sphere = Sphere(Point3(1, 1, 1), 1);
	case_2 = intersection_betwen(first_sphere, second_sphere);
	print_intersection(case_2);

	std::cout << "expected: Intersection\nactual: ";
	first_sphere = Sphere(Point3(0, 0, 0), 4);
	second_sphere = Sphere(Point3(0, 0, 5), 3);
	case_3 = intersection_betwen(first_sphere, second_sphere);
	print_intersection(case_3);

	std::cout << "expected: External_Tangency\nactual: ";
	first_sphere = Sphere(Point3(0, 0, 0), 4);
	second_sphere = Sphere(Point3(0, 0, 7), 3);
	case_4 = intersection_betwen(first_sphere, second_sphere);
	print_intersection(case_4);

	std::cout << "expected: Internal_Tangency\nactual: ";
	first_sphere = Sphere(Point3(0, 0, 0), 5);
	second_sphere = Sphere(Point3(0, 0, 2), 3);
	case_5 = intersection_betwen(first_sphere, second_sphere);
	print_intersection(case_5);
	return 0;
}