/*
    Stephanie
    Assignment 3 - number guesser
    
    Main part of Assignment
        - program guesses user's number frpm 1-100
        - prompt user for input l,h,c
        - guess user number and ask for input
        - check for valid inputs
        - keep guessing till user enters c for correct
        - ask user if they want to play again, (y ,n)
    
    Extra credit
        - swap out getMidpoint() for getRandomMidpoint()
        - seed rand() via srand() and time() in main()
    
*/
#include <iostream>
#include <cstdlib> // library for rand(), srand()
#include <ctime>   // library to use time() method to seed srand()

using namespace std;

// this function takes in 2 int parameters and calculates random midpoint between those 2 ints,
// return value to function call 
int getRandomMidpoint(int low, int high)
{
    return low + rand() % (high - low + 1);
}response

// this funciton takes in an int value returned to it from getMidpoint(),
// call this int guess, as in the number guessed by our program
// check with user if guess is high, low or correct (h/l/c)
// return user 
char getUserResponseGuess(int guess)
{
    char userResponse;
    
    cout << "Is it " << guess << "? (h/l/c) ";
    
    cin >> userResponse;
    return userResponse;
}

// play one guessing game
// while true keep guessing, until user says guess is correct 
void playOneGame()
{
    int low = 1, high = 100; // start low at 1 and high at 100
    char userResponse;    

    // keep guessing till guess is correct
    // continue calling getMidpoint() and getUserResponse() till, 'c' is entered
    while(true)
    {
        int guess = getRandomMidpoint(low, high);
        userResponse = getUserResponseGuess(guess);
        
        if (userResponse == 'C' || userResponse == 'c') {    
            cout << "Great!  I guessed your number." << endl;
            break;
            
        } else if (userResponse == 'H' || userResponse == 'h') {
            low = guess + 1;             // guess too low, increase lower bound guess number
            if (userResponse == 'H' || userResponse == 'h' && guess == 100) {
                cout << "I can only guess up to 100.\n";
                break;
            }
            
        } else if (userResponse == 'L' || userResponse == 'l') {
            high = guess - 1;              // guess too high, decrease upper bound guess number
            if (userResponse == 'L' || userResponse == 'l' && guess == 1) {
                cout << "I can only guess as low as 1.\n";
                break;
            }
        
        } else {
            cout << "OOPS! Please enter a valid input 'h', 'l' or 'c'. " << endl;
        }
    }
}

// Ask user if they want to play again
// return bool value
bool shouldPlayAgain()
{
    char userResponse;
    cout << "Do you want to play again (y/n): " << endl;
    cin >> userResponse;
    
    if (userResponse == 'Y' || userResponse == 'y') { 
        return true;
        
    } else if (userResponse == 'N' || userResponse == 'n') {
      return false;

    } else {
        cout << "OOPS! Please enter a valid input 'y' or 'n'. " << endl;
    
        return shouldPlayAgain();
    }
}

int main()
{
    // seed random number generator
    srand(static_cast<unsigned>(time(0)));
            
    cout << "Lets play a number guessing game! \n";
    cout << "\n";
    cout << "Think of a number between 1 and 100.\n";
    cout << "If I guess your number correctly enter 'c', \n";
    cout << "if your number is higher enter 'h', \n";
    cout << "if your number is lower enter 'l'. \n";
    cout << "\n";
    cout << "Let's get started!!!" << endl;
    cout << "\n";
    cout << "\n";
        

    do {
        
        playOneGame();
    
    } while (shouldPlayAgain());

  

    return 0;
}