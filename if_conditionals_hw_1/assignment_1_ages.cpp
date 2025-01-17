#include <iostream>
using namespace std;
int main()
{
    /* - This program takes in age input from the user,
       - then decides if the user is a: child, teen, adult or retiress
    */
    
    int userAge;
    
    
    // Prompt user & store user's age input to a variable for later comparision
    cout << "Lets see what class of age you fall under.\n";
    cout << "Please enter your age, no negative imputes will be accepted: " << endl;
    
    cin >> userAge;
    
    
    /* - Here we defines what determines the classification of each age bracket 
       - Check for valid inputs, no negative imputs
    
       - FAIL FAST - check if user is less than 0
       
       - child: min  0 - max 12 years
       - teen:  min 13 - max 17 years
       - adult: min 18 - max 64 years
       - retiree: min 65 
    */
   
    
   if(userAge < 0){                               // fail fast, first check for negative number 
       cout << "Error! Age must be at least 0!\n";
   }else if (userAge > -1 && userAge < 13){       // child check
       cout << "You are a child." << endl;
   }else if (userAge > 12 && userAge < 18){       // teen check
       cout << "You are a teen." << endl;
   }else if (userAge > 17 && userAge < 65){       // adult check
       cout << "You are an adult." << endl;
   }else{                                        // retiree check, default respone  
       cout << "You are a retiree." << endl;     // if any number less than 65 was entered
   }
 
   
    return 0;
}