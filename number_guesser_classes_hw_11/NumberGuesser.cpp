
#include "NumberGuesser.hpp"

// default constructor - not actually really needed here 
NumberGuesser::NumberGuesser(): lowerBound(1), upperBound(100), originalLower(1), originalUpper(100){}

// constructor w/ parameters
NumberGuesser::NumberGuesser(int lower, int upper)
	: lowerBound(lower), upperBound(upper), originalLower(lower), originalUpper(upper) {}

// adjust range up if too low
void NumberGuesser::higher(){	
	lowerBound = getCurrentGuess() + 1; 	// update lowerBound
}

// adjust range down if too high
void NumberGuesser::lower(){
	upperBound = getCurrentGuess() - 1;		// update uppperBound
}

// get midpoint of current range
int NumberGuesser::getCurrentGuess() const {
	return (upperBound + lowerBound) / 2; 	// calc midpoint 
}

// reset range to original value
void NumberGuesser::reset() {
	lowerBound = originalLower;
	upperBound = originalUpper; 
}
