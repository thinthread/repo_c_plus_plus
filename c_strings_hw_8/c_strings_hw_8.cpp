/* Stephanie - Assignment 8 C-strings

	This program takes a null terminated c-string 
	(meaning char array with valid null-terminated datat) and 
	a target char:

	it will do the following where applicaple:
		- find the index of char in c-string 
		 	- return index of found char
		 	- else if not fount return -1
		- revers original c-string 
				- in place
				- cout c-string ?
		- replace target char with a replacement char
		 		- return a count of target char replaced if found
		 		- else return 0
		- find sub-c-string of given c-string, 
				- return the starting index of sub-c-string if found
				- retun -1 if sub-c-string not found
		- is palindrome
				- return true if argument c-string is palindrome
				- return false if not palindrom found

	required to use:
		must use C-Strings (null-terminated arrays of chars)

	may use:
		strlen(), strcmp(), and strncpy() 

	not accepted:
		use C++ string objects

	functions signatures:
		int lastIndexOf(char *s, char target);
			
		void reverse(char *s);

		int replace(char *s, char target, char replacementChar);

		int findSubstring(char *s, char substring[]);

		bool isPalindrome(char *s);
*/

#include <iostream>
// #include <cstring>
using namespace std;

// funciton takes in c-string and target char, 
// search for target char, 
// if found return index position of target char
// if not found return -1
// '\0' end of c-sting null diliniatore 
int lastIndexOf(char *s, char target){
	int lastcharIndex = -1;    // set value to last index, return if target char not found
							   // else asign value of i 

	// '\0' natural end of c-string s
	for (int i = 0 ; s[i] != '\0'; ++i){
		if(s[i] == target){
			lastcharIndex = i;
		}
	}
	return lastcharIndex;
}


// takes in c-string 
// reverse c-string in place, changing actual string
// find the length of string
// iterate through c-string and swap(), swap() is part of the standard library
void reverse(char *s){
	int cStringLength = strlen(s);

	for(int i = 0; i < cStringLength /2; ++i){
		// swap chars from each end to other end of c-string
		char temp = s[i];                // store index position of i in tempp variable
		s[i] = s[cStringLength -1 -i];    // store last index value at s[i], move in reverse
		s[cStringLength -1 -i] = temp;   // store temp variable value at end of c-string   
	}

	// for (int i - 0; i < cStringLength / 2; ++i){
	// 	swap(s[i], s[cStringLength -1 -i]);
	// }

}

// takes in c-string and target char
// finds al ocurrances of target char and replaces it using replacementChar
// returns nunber of occurences of target char if found
// else return 0, does not change original c-string
int replace(char *s, char target, char replacementChar){
	int countTargetChar = 0;

	for (int i = 0; s[i] != '0'; ++i){
		if (s[i] == target){
			s[i] = replacementChar;
			++ countTargetChar;
		}

	}
	return countTargetChar;
}



// find sub-c-string of given c-string, 
// return the starting index of sub-c-string if found
// retun -1 if sub-c-string not found
// '\0' null char denotes end of c-string
int findSubstring(char *s, char substring[]){
	for (int i = 0; s[i] != '\0'; ++i){
		int j = 0;   	// j to track index of c-substring
		while(s[i + j] != '\0' && substring[j] != '\0' && s[i+j] == substring[j]){
			j++;		
		}

	 if (substring[j] =='\0'){
	    return i;
	
	    }   
	 }
    return -1;
    }




// return true if c-string argument is palindrome
// return false if c-string not palindrome
bool isPalindrome(char *s){
    int cStringLength = 0;
    
    while(s[cStringLength] != '\0'){
        cStringLength++;     // count up to the null char caracter to find csrting length
                            
    for ( int i = 0; i < cStringLength / 2; ++i){
        if (s[i] != s[cStringLength - i - 1]){
            return false;
            }
        
        }
        
    }
    return true;
}



int main(){
    
	// 1)  c-string "Giants"
	cout << "Function - lastIndexOf(): " << "\n";
	char cString1[] = "Giants"; 
	cout << "Original cstring: " << cString1 << "\n";
	cout << "Last index of target char: " << lastIndexOf(cString1, 'a') << "\n\n";
	
    // 2)  c-string "radar"
    cout << "Function - reverse(): " << "\n";
    char cString2[] = "flower";
    cout << "Original cstring: " << cString2 << "\n";
    reverse(cString2);
    cout << "Revered cstring: " << cString2 << "\n\n";
	
    // 3)  cstring "go giants"
    cout << "Function - replace(): " << "\n";
    char cstring3[] = "go giants";
    cout << "Original string: " << cstring3 << "\n";
	cout << "Replacement char count: " << replace(cstring3, 'g', 'G') <<"\n";
	cout << "Cstring after char replacement: " << cstring3 << "\n\n";
	
    // 4)  cstring "Skyscraper"
    cout << "Function - findSubstring(): " << "\n";
    char cstring4[] = "Skyscraper";
    char csubstringstring4[] = "ysc";
    cout << "Original cstring: " << cstring4 << "\n";
	cout << "Start index of " << csubstringstring4 << " c-substring: " << findSubstring(cstring4, csubstringstring4) << "\n\n";
	
	
    // 5) cstring "radar"
    cout << "Function - isPalindrome(): " << "\n";
    char cstring5[] ="radar";
    cout << "Original cstring: " << cstring5 << "\n";
	cout <<"Is palindrome:  " << (isPalindrome(cstring5) ? "true" : "false") << "\n";

	return 0;
}