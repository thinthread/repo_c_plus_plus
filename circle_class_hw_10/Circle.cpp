#include "Circle.hpp"
#include <cmath> // import library - squareroot funciton

// SETTERS
// set radaius of circle
void Circle::setRadius(double r){
	radius = r;
}

// set x coordinate - center of circle
void Circle::setX(double xValue){
	x = xValue;
}

// set y coordinate - center of circle
void Circle::setY(double yValue){
	y = yValue;
}



// GETTERS
// get radius of circle
double Circle::getRadius() const{
	return radius;
}

// get x coordinate - center of circle
double Circle::getX() const{
	return x;
}

// get y coordinate - center of circle
double Circle::getY() const{
	return y;
}



// CALCULATORS
// calc and return area of circle, return bool value
double Circle::getArea() const{
	return radius * radius * 3.14;
}

// return true if point(xValue, yValue) is within confinds of circle
bool Circle::containsPoint(double xValue, double yValue) const{
	// formula calulates distance from center to expressed point
	double distanceToPoint = sqrt((x - xValue) * (x - xValue) + (y - yValue) * (y - yValue));

	// if distance is less thank or equal to radius, return true
	// outside of circle radious, return false
	return distanceToPoint <= radius;
}

