#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std; 

void update(int *a, int *b) {
   
    /*make ta point to the same temp address as a 
    making a copy of the pointer is useless because modifying 
    the copy modifes the value at the address 
    int *ta; 
    ta = a;  */   

    /*cout << " *ta: " << *ta  << endl; 
    cout << " *a: " << *a << endl;

    cout << " ta: " << ta << endl; 
    cout << " a: " << a << endl;

    cout << " &ta: " << &ta << endl;  
    cout << " &a: " << &a << endl;*/

    int ta, tb; 
    ta = *a + *b; 
    tb = abs(*a - *b); 
       
    //since a & b are pointers, a basically holds the address 
    //the var ta...same as b.
    //printing a or b will print out an address...*(with cout) 
    //printf seems to give a different output
    /*
    a = &ta; 
    b = &tb; 
    */

    //this changes the value at the address to what we want
    //it doesn't throw a syntax error because *a is a value 
    //of the same type as tb. they are both ints 
    *a = ta; 
    *b = tb; 

  
}

int main() { 
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}