/* stephanie assignment 9 - the league with structs
    
    - this program takes in the number of teams in the league
    - takes in the names of each team in the league
    - number of wins for that team
    - cout the LEAGUE STANDINGS by name in order of highest win 
      to lowest win

    - store data for teams and wins using structs WinRecord
        - struct has 2 fields/members
            - name
            - wins
*/

#include <iostream>
#include <cstring> // import library for strcpy & strcmp
using namespace std;


// struct - stores team data
struct WinRecord{
    int wins;
    char* name;     // dynamically allocated c-string
};

// function prototypes
void intializeData(WinRecord*  standings, int size);
void sortData(WinRecord*  standings, int size);
void displayData(WinRecord* standings, int size);
char* getLine(); // helper function reads c-string dynamically


int main(){
    int numTeams;
    
    // ask user for number of numTeams
    cout << "Please enter the number of teams in the leaugue: ";
    cin >> numTeams;
    cout << "\n";
    
    // Dynamically allocate array of struct WinRecord
    // size of array numTeams
    WinRecord* standings = new WinRecord[numTeams];
    
    // function calls - intializeData, sort & display data
    intializeData(standings, numTeams);
    sortData(standings, numTeams);
    displayData(standings, numTeams);
    
    // prevent memory leak - dealocate for each individual 
    // instance of struct object WinRecord - team name
    for (int i=0; i < numTeams; ++i){
        delete[] standings[i].name;
    }
    
    // prevent memory leak - dealocate Dynamically array of structs
    delete[] standings;
 
return 0;

}


// function - intialize data by getting names & wins from user
void intializeData(WinRecord* standings, int size){
    for (int i=0; i < size; ++i){
        cout << "Please enter the name of team #" << (i + 1) << ": ";
        standings[i].name = getLine();   // helper function that allocates memory
                                        // to member - name of struct WinRecord
        cout << "Please enter the number of wins for " << standings[i].name << ": ";
        cin >>  standings[i].wins;
        cout << "\n";
    }
}

// function - sort array of WinRecord structs by wins, decenting order
void sortData(WinRecord* standings, int size){
    for (int i = 0; i < size - 1; ++i){
        for (int j = i + 1; j < size; ++j){
            if (standings[i].wins < standings[j].wins){
                // swap WinRecord structs
                WinRecord temp = standings[i];
                standings[i] = standings[j];
                standings[j] = temp;
            }
        }
    }
}

// function - display standings - array of struct instances
void displayData(WinRecord* standings, int size){
    
    cout << "\nLEAGUE STANDINGS:\n";
    
    for (int i = 0; i < size; ++i){
        cout << "Team " << standings[i].name << ": " << standings[i].wins << " wins\n";
    }
}

// helper function - read line input into Dynamically allocated c-string
char* getLine(){
    char buffer[1600];             // temp buffer store input
    cin.ignore();                  // clear any remnant newline chars from input buffer
    cin.getline(buffer, 1600);     // read input into buffer
    
    // dynamically allocate memory - exact size of input
    char* inputLine = new char[strlen(buffer) + 1];
    strcpy(inputLine, buffer);    // copy input from buffer to allocated memory
    
    return inputLine;
}







