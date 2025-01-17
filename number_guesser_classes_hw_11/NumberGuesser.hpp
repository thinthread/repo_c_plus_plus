#ifndef NUMBERGUESSER_HPP
#define NUMBERGUESSER_HPP


class NumberGuesser{
	private:
		int lowerBound;		// lower bound, current
		int upperBound; 	// upper bound, current
		int originalLower;	// lower bound original var, to reset
		int originalUpper;	// upper bound original var, to reset

	public:
		// constructors  - like a main controlling funciton - gate keeper to member functions
		NumberGuesser(); 						// default parametors
		NumberGuesser(int lower, int upper);	// required parametors list

		// member funcitons - like a helper function under constructors (function)
		void higher();					// adjust lowerBound up if too low
		void lower();					// adjsut uperBound down if too high
		int getCurrentGuess() const; 	// get the midpoint of range
		void reset();					// reset to original range			
};

#endif