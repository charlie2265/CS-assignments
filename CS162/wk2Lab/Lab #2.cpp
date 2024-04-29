/******************************************************************************
Charlie Ritter 

CS162 Priestley SP '24 
Week 2 Lab 2

Word of the day Random
*******************************************************************************/
#include <iostream>
#include<string>

using namespace std;
const int SIZE = 10;

int main(){

int *ptr = nullptr;

ptr = new int[SIZE];

// just lookin'
cout << *ptr + 100 << endl << endl;

// fill the array 1 -10
for(int idx = 1; idx <= SIZE; idx++){
    ptr[idx] = idx;
cout << ptr[idx] << endl;

}

delete[] ptr;
ptr = nullptr;


    return 0;
}











// Write an small experimental lab program that declares a pointer variable, assigns a value to a 'size' variable, 
// allocates dynamic memory for an array, then uses familiar [subscript] notation to assign and display a few values 
// in the array. Then wrap things up with a delete[] ptr and ptr = nullptr pair of statements.
// Submit cpp file for this second pointer program as Lab #2. 