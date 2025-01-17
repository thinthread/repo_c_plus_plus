/* Stephanie - Assignment 10 - Circle Class
	This program  creates a simple class named Circle, with three private variables: 
		doubles named x, y and radius.
	Intanciates a class object of Circle
	Passes in set values to meet the requitedments to creat said class object
	Tests/ verifies calcualtions
	Updates the initial values of the intance of Circle class object
	Tests/verifies calculations
	cout wheather or not set x,y coordinates are with the circle parameters of the circle ocject

*/

#include <iostream>
#include "Circle.hpp"
using namespace std;


int main(){

	// 3 main parts

	// AREA STUFF - 2 parts
	// 1.1 CREATE a loscal Circle object and set it's x, y, and radius
	Circle myCircle;
	myCircle.setX(2.0);
	myCircle.setY(3.0);
	myCircle.setRadius(2.0);


	// 1.2 VERIFY calculated area of circle
	cout << "Circle center: (" << myCircle.getX() << ", " << myCircle.getY() << ") \n";
	cout << "Circle radious: " << myCircle.getRadius() << endl;
	cout << "Circle area: " << myCircle.getArea() << "\n\n";

	// POINTER STUFF for Circle instance  - 3 parts
	// 2.1 CREATE circle pointer - point to local Circle instance/object
	Circle* circlePtr = &myCircle;


	// 2.2 SET new values for instance Circle, use x, y & radius pointer
	circlePtr->setX(4.0);
	circlePtr->setY(5.0);
	circlePtr->setRadius(3.0);

	// 2.3 VERIFY new area calulated
	cout << "Updated circle center: (" << circlePtr->getX() << ", " << circlePtr->getY() << ") \n";
	cout << "Updated circle radious: " << circlePtr->getRadius() << endl;
	cout << "Updated circle area: " << circlePtr->getArea() << "\n\n";


	// TEST
	// 3.1 test containsPoint() via poiter
	// POINT in circle parameters
	if (circlePtr->containsPoint(4.0, 6.0)){
		cout << "Point (4.0, 6.0) is within the circle." << "\n\n";
	} else {
		cout << "Point (4.0, 6.0) is not within the circle." << "\n\n";
	}

	
	// POINT outside circle parameters
	if (circlePtr->containsPoint(4.0, 10.0)){
		cout << "Point (4.0, 10.0) is within the circle." << "\n\n";
	} else {
		cout << "Point (4.0, 10.0) is not within the circle." << "\n\n";
	}




	return 0;
}
