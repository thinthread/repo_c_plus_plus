/*
    Stephanie Boyettte
    02 graded discussion - looping

       - program that tracks assignment grades
       - ask user for number of assignments
       - printout total scored & mean - average points scored
       - score is from 0 to 100 
*/

    #include <iostream>
    using namespace std;


    int main()
    {
    int numAssignments = 0,  assignmentScore,  totalScored = 0, meanAvergeScore;

    cout << "Please enter the number of your assignments: " << endl;
    cin >> numAssignments;
    
    // check for valid imput of number of assignments
    while(numAssignments < 1){
        cout << "OOPS! Please enter a valid number of assigments.\n";
        cout << "There must be at least one assignment." << endl;
        cin >> numAssignments;
    }

    for (int i = 0; i < numAssignments; i++){
        cout << "Please enter a grade for this assigment.\n";
        cout << "The grade must be no less than 0 and at most 100: " << endl;
        
        cin >> assignmentScore;
        
        
        // check for invalid imput of points scored 
        // is assignmentGrade less than 0 or assignmentGrade greater 100
        while(assignmentScore < 0 || assignmentScore > 100){
            cout << "OOPS! Please enter a valid score for this assigment.\n";
            cout << "The score must be no less than 0 and at most 100: " << endl;
            cin >> assignmentScore;
        }
        
        totalScored += assignmentScore;
        
    }

    // print out total scored
    cout << "Total scored: " << totalScored << endl;
    meanAvergeScore = totalScored/numAssignments;
    // print out average scored
    cout << "Mean averge scored: " <<  meanAvergeScore << endl;

    /*  - convert average score to letter grade
        - print out letter grade
        - make sure grade is at least 0 and at most 100
        - 90 or higher A
        - 80 or higher B
        - 70 or higher C
        - 60 or higher D
        - less than 60 F
    */

    if (meanAvergeScore >= 90){
        cout << "Student letter grade is A." << endl;
    }else if (meanAvergeScore >= 80){
        cout << "Student letter grade is B." << endl;
    }else if (meanAvergeScore >= 70){
        cout << "Student letter grade is C." << endl;
    }else if (meanAvergeScore >= 60){
        cout << "Student letter grade is D." << endl;
    }else{
        cout << "Student letter grade is F" << endl;
    }

    
    return 0;
}