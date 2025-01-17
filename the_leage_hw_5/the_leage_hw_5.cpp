/* Stephanie assignment 5 - the league
    This is a program that records and displays league standings for a baseball league
        Populate arrays with user data - create a function:
            - ask user - enter 5 team names
            - ask user - enter 5 corolated wins to each team
        Sort arrays - create a function: 
            - do so by league standing, highest to lowest
        Print to consol  - create a function:

*/

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;  // global const

// intialize two dimentioanal array, array team names and array win amounts
void initializeArrays(string names[], int wins[], int size){
    for (int i = 0; i < size; i++){
        cout << "Enter team #" << i + 1 << ": ";
        getline(cin,  names[i]); // get team name incuding spaces
        cout << "Enter the wins for team #" << i + 1 << ": ";
        cin >> wins[i];
        cin.ignore(); // ignore \n 
    }
}

void sortData(string names[], int wins[], int size){
    for (int i = 0 ; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){
            if (wins[i] < wins[j]){
                // swap wins
                int tempWins = wins[i];
                wins[i] = wins[j];
                wins[j] = tempWins;
                
                // sawp corresponding team names
                string tempNames = names[i];
                names[i] = names[j];
                names[j] =tempNames;
            }
        }
    }
}

// display leage standing
void displayData(string names[], int wins[], int size){
    cout <<"\n";
    cout << "League Standings:\n";
    for (int i = 0; i <size; i++){
        cout << names[i] << ": " << wins[i] << endl;
    }
}

int main(){
    string teams[SIZE];         // declare array of strings  - size 5
    int wins[SIZE];             // declare array of ints - size 5
    
    // initialize arrays with user  via function call, do first
    initializeArrays(teams, wins, SIZE);
    
    // sort arrays based on wins via function call, do second
    sortData(teams, wins, SIZE);
    
    // display sorted standings via function call, do last
    displayData(teams, wins, SIZE);
    
    
    return 0;
}