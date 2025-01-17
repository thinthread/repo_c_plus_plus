/*	Stephanie - Assignment 11 - Number Guesser class

	This program is a number guesser game where the program guesses the 
	user input
		- use class structures to create the foundation for variables and methods
		

*/

#include <iostream>
#include "NumberGuesser.hpp"
using namespace std;


int main(){
	char playAgain;
	do{

		// instantiate NumberGuesser class object, range 1 - 100
		NumberGuesser guesser(1, 100);

		cout << "Think of a number between 1 and 100," << endl;

		bool guessedNum = false;
		while(!guessedNum){
			// program's guess
			int programGuess = guesser.getCurrentGuess();

			// get user input response
			cout << "Is the number " << programGuess << "? (h/l/c): ";
			char userResponse;
			cin >> userResponse;

			// adjust range or exit loop based on user response
			if(userResponse == 'h'){
				guesser.higher();
			}else if (userResponse == 'l'){
				guesser.lower();
			}else if (userResponse == 'c'){
				guessedNum = true;
				cout << "You picked " << programGuess << "? Great pick." << endl;

			}else{
				cout << "Invalid input, Please enter 'h', 'l', or 'c'," << endl;
			}
		}

		// prompt user, play again?
		cout << "Do you want to play again? (y/n): ";
		cin >> playAgain;
	} while (playAgain == 'y');
	cout << "Goodbye." << endl;

	return 0;
}



/* Sample output

[sboyett2@hills assignment_11_number_guesser_class]$ g++ main.cpp NumberGuesser.cpp NumberGuesser.hpp
[sboyett2@hills assignment_11_number_guesser_class]$ ./a.out
Think of a number between 1 and 100,
Is the number 50? (h/l/c): h
Is the number 75? (h/l/c): h
Is the number 88? (h/l/c): h
Is the number 94? (h/l/c): h
Is the number 97? (h/l/c): h
Is the number 99? (h/l/c): h
Is the number 100? (h/l/c): c
You picked 100? Great pick.
Do you want to play again? (y/n): y
Think of a number between 1 and 100,
Is the number 50? (h/l/c): 1
Invalid input, Please enter 'h', 'l', or 'c',
Is the number 50? (h/l/c): l
Is the number 25? (h/l/c): l
Is the number 12? (h/l/c): l
Is the number 6? (h/l/c): l
Is the number 3? (h/l/c): l
Is the number 1? (h/l/c): c
You picked 1? Great pick.
Do you want to play again? (y/n): n
Goodbye.

*/