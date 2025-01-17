#ifndef CIRCLE_H
#define CIRCLE_H

class Circle{
	private:
		// keep private base components of circle
		double x;		// x coordiante of center of circle
		double y;		// y coordinate of center of circle
		double radius;  // radius of circle

	public:
		// setters - like function prototype within class
		void setRadius(double r);
		void setX(double value);
		void setY(double value);

		// getters - get user input, keep values pasted to function calls const
		double getRadius() const;
		double getX() const;
		double getY() const;

		// Calc area of circle
		double getArea() const;

		// check given point is contained the circle, if yes return true 
		bool containsPoint(double xValue, double yValue) const;

};

#endif		