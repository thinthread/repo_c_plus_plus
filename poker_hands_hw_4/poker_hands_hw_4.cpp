/* Stephanie - Assignment 4 - Poker Hands
    
    - no face cards
    - 7 functions inlcuding main
    - 6 of the functions are to process the different HAND TYPES
        - 5 cards to be pulled
        
        - HAND TYPES:
            - high card            - there are no matching cards & not a straight 
            - pair                 - two of the cards are identical
            - two pair             - two different pairs
            - three of a kind      - three matching cards
            - straight             - card values can be arranged in chronilogical order
            - full house           - a pair and three of a kind
            - four of a kind       - four matching cards
                        
            * high card is a defualt else card type - no need for a funciton
    
*/

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// function prototypes - arranged by order of calls in main()
bool containsFourOfaKind(int hand[]);        // four matching cards
bool containsFullHouse(int hand[]);         // a pair and three of a kind
bool containsStraight(int hand[]);          // card values can be arranged in chronilogical order
bool containsThreeOfaKind(int hand[]);      // three matching cards
bool containstwoPair(int hand[]);           // two different pairs
bool containsPair(int hand[]);              // two of the cards are identical


int main()
{
    int hand[5];   // declare and intisialize array, size 5 cards 
    
    cout << "Enter five numeric cards, no face cards. user 2-9." << endl;
    for(int i = 0; i < 5; i++)
    {
        cout <<"Card " << i + 1 << ": ";    // cout and display/count number of cards entered
        cin >> hand[i];                     // grab user input and add to array at index possion i
    }
    
    // call to each function, use map<>
    // 1st fail fast - look for 4 of a kind match first                                  - 4 of a kind
    // 2nd           - look for a pair and  3 of a kind                                  - full house 
    // 3rd           - look for cards that can be arranged in chronilogical order        - straight hand 
    // 4th           - look for cards set 3 of a kind                                    - 3 of a kind 
    // 5th           - look for 2 sets of 2 matching pairs                               - 2 sets of 2 matching cards
    // 6th           - look for a pair                                                   - 2 of a kind 
    // 7th else/default - high card 
    
    if (containsFourOfaKind(hand)){              
        cout << "Four of a kind!" << endl;
        
    } else if (containsFullHouse(hand)){         
        cout << "Full House!" << endl;
    
        
    } else if (containsStraight(hand)){
        cout << "Strait!" << endl;
        
    } else if (containsThreeOfaKind(hand)){
        cout << "Three of a kind!" << endl;
        
    } else if (containstwoPair(hand)){
        cout << "Two Pairs!" << endl;
        
    } else if (containsPair(hand)){
        cout << "Pair!" << endl;
    } else {
        cout << "High Card!" << endl;
    }
    
    return 0;
}

// 4 of a kind  - look for 4 of a kind match first
bool containsFourOfaKind(int hand[]){
    map<int, int> countCards;
    
    for (int i = 0; i < 5; i++){
        countCards[hand[i]]++;              // nested array, advance 1 index posion of the countCard array
    }
    
    for (auto pair: countCards){
        if (pair.second == 4){          // check for 4 of a kind
            return true;
        }
    }
    return false;
} 

// full house  - look for a pair(2) and  3 of a kind
bool containsFullHouse(int hand[]){
    map<int, int> countCards;
    
    bool three = false, two = false; // set default values on bools as false, if condition is met assign as true 
    
    for (int i = 0; i < 5; i++){
        countCards[hand[i]]++;
    }
    
    for (auto pair : countCards){        // iterate through counts array at hand sub i  
        if (pair.second == 3){      // look for 3 of a kind match 
            three = true;
        }
        
        if (pair.second == 2){      // look for 2 of a kind/pair match
            two = true;
        }
    }
    return three && two;
}

// straight  - look for cards that can be arranged in chronilogical order
bool containsStraight(int hand[]){
    sort(hand, hand + 5);    // use sort funciton to sort array hand, 
                            // sort() elements of the original array in place
                            // modifies oridigal array directly
    
    for (int i = 0; i < 4 ; i++){
        if ( hand[i + 1] != hand[i] + 1){
            return false;
        }
    }
    return true;
}

// three of a kind  - look for cards set 3 of a kind 
bool containsThreeOfaKind(int hand[]){
    map<int, int> countCards;
    
    for (int i = 0; i < 5; i++){
        countCards[hand[i]]++;
    }
    
    for (auto pair : countCards){       // iterate through countCards array at hand sub i
        if (pair.second == 3){      //look for 3 of a kind match
            return true;
        }
    }
    return false;
}

// 2 pairs  - 2 sets of 2 matching cards 
bool containstwoPair(int hand[]){
    map<int, int> countCards;
    
    int countPairs = 0;     // couter variable to track 2 mmatching pairs. so 2 of set of matches
    
    for (int i = 0; i < 5; i++){
         countCards[hand[i]]++;
    }
    for (auto pair : countCards){
        if (pair.second == 2){  // check for 2 pairs
            countPairs ++;  // incrament pairs when found
        }
    }
    return countPairs == 2;
}

// a pair   - 2 of a kind 
bool containsPair(int hand[]){
    map<int, int> countCards;
    
    for (int i = 0; i < 5; i++){
        countCards[hand[i]]++;       
    }
    
    for (auto pair : countCards){
        if (pair.second == 2){      // check for a pair
            return true;
        }
    }
    return false;
}