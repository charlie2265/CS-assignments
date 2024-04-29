/******************************************************************************
Charlie Ritter 

CS162 Priestley SP '24 
Week 2 Lab 1

Word of the day Random
*******************************************************************************/
#include <iostream>
#include<string>

using namespace std;


int main()
{

    int arr[100] {88, 77};
    
    cout << arr << endl;
    
    cout << (arr + 1) << endl;
     
    cout << *(arr + 1) << endl;
    
    cout << arr[1] << endl;
    
    int *ptr {};
    
    cout << "Ptr: " << ptr << endl;
    
    int b = 18;
    
    ptr = &b;
    
    cout << ptr << endl;
    
    cout << *ptr << endl;
    
    *ptr = 19;
    
    cout << *ptr << endl;
    
    cout << b << endl;
    
    int c {777};
    
    ptr = &c;
    
    *ptr = 999;
    
    cout << c << endl;
    
    ptr = new int {45};
    
    cout << ptr << endl;
    
    cout << *ptr << endl;
    
    // must delete or have a memory leak
    
    *ptr = 0;
    delete ptr; // free memory where 45 had been
    ptr = nullptr;
    
    ptr = new int {111};
    
    cout << *ptr << endl;
    
    int size = 1000;
    
    ptr = new int[size] {77, 88};
    
    cout << ptr[1] << endl;
    
    
    
    return 0;
}
    
    
    
    
    
    
    
    
    
    
    // const int
    //     Q_FIELDS = 18,
    //     Q_SOURCES = 18,
    //     Q_DATES = 15,
        
    // string heading[Q_FIELDS];
    // string data[Q_SOURCES * Q_DATES][FIELS];
    
    // // getline(data[idx][col], ',');
    
    