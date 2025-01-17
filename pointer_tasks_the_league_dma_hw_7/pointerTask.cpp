#include <iostream>
using namespace std;


/* 11. Write a function with the following signature: void noNegatives(int *x). 
  The function should accept the address of an int variable. If the value of this integer is negative then 
  it should set it to zero.  Note: you should declare the noNegatives function BEFORE main, not inside of main.
*/ 
void noNegatives(int* x){
    if(*x < 0){
        *x = 0;
    }
}


/* 21. Write a function named ‘swap’ that accepts two integer pointers as arguments, 
and then swaps the two integers that the pointers point to.  
This function must be pass by pointer, i.e. int *, not pass by reference, i.e. int &.  
Note: you should declare the swap function BEFORE main, not inside of main.
*/
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main()
{
// 1. Create two integer variables named x and y
		int x, y;
		
// 2. Create an int pointer named p1
		int* p1;
		
// 3. Store the address of x in p1
		p1 = &x;
		
// 4. Use p1 to set the value of x to 99
		*p1 = 99;
		
// 5. Using cout and x, display the value of x
		cout << "Value of x: " << x << endl;
		
// 6. Using cout and the pointer p1, display the value of x
		cout << "Value of x via p1 pointer: " << *p1 << endl;
		
// 7. Store the address of y into p1
		p1 = &y;
		
// 8. Use p1 to set the value of y to -300
		*p1 = -300;
		
// 9. Create two new variables: an int named temp, and an int pointer named p2
		int temp;
		int* p2;
		
// 10. Use temp, p1, and p2 to swap the values in x and y (this will take a few statements)
		temp = *p1; // *temp gets the value of -300, assigned in question 8.
		//cout << "Temp gets the value it point to stored in p1:   " << temp << endl;
		p1 = &x; // NOW p1 -  gets the addess location of x wich is 99
		//cout << "P1 swap is now the address walue of x:   " << *p1 << endl;
		p2 = &temp; // p2 gets the address of temp witch has the value of y which is -300	
		//cout << "P2 swap is now the address value of temp which has the value orginally given to Y:  " << *p2 << endl;
        
// 12. Call the function twice: once with the address of x as the argument, and once with the address of y

        noNegatives(&x);
        noNegatives(&y);

// 13. Use p2 to display the values in x and y (this will require both assignment statements and cout statements)
        p2 = &x;
        cout << "p2 gets the value of x: " << *p2 << endl;
        p2 = &y;
        cout << "p2 now gets the value of y: " << *p2 << endl;
        
// 14. Create an int array with two elements. The array should be named ‘a’
        int a[2];
        
// 15. Use p2 to initialize the first element of a with the value of x
        p2 = &a[0];
        *p2 = x;
        //cout << "x: " << x << endl;
        //cout << "p2 pointer has the value of x: " << *p2 << endl;
        //cout << "array at index posision 0: " << a[0] << endl;
        
// 16. Use p2 to initialize the second element of a with the value of y
        p2 = &a[1];
        *p2 = y;
        
// 17. Using cout, display the address of the first element in a
        cout << "Address of a[0]: " << &a[0] << endl;

// 18. Using cout, display the address of the second element in a
        cout << "Address of a[1]: " << &a[1] << endl;
        cout << "value af a[1]: " << *p2 << endl;
    
// 19. Use p1, p2, and temp to swap the values in the two elements of array ‘a’. 
// (first point p1 at a[0], then point p2 at a[1]. 
// After this the swapping steps should look very similar to step 10.)        
        p1 = &a[0]; // value 99
        //cout << "p1 @ a[0]: " << *p1 << endl;
        p2 = &a[1];
        //cout << "p2 @ a[1]: " << *p2 << endl;
        temp = *p1; 
        *p1 = *p2;
        *p2 = temp;
        
// 20. Display the values of the two elements. (The first element should be 99, the second 0).
        cout << "array, a[1]: " << a[1] << " , array, a[0]: " << a[0] << endl;
        
// 22. Call your swap function with the addresses of x and y, then print their values. 
// (x should be 99, y should be 0).
        swap(&x, &y);
        cout << "After swap, x: " << x << ", y: " << y << endl;

// 23. Call your swap function with the address of the two elements in array ‘a’, 
// then print their values. (a[0] should be 0, a[1] should be 99)
        swap(&a[0], &a[1]);
        cout << "After swap, a[0]: " << a[0] << ", a[1]: " << a[1] << endl;
        
	return 0;
}