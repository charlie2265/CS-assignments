/******************************************************************************

Template function definition

Charlie Ritter
cs161 Priestley Spring 2024
Week 4 lab2.2  cpp

*******************************************************************************/

#include <iostream>
using namespace std;

template <typename T>
    void trade(T& x, T& y)
    {
        T z = x;
        x = y;
        y = z;

    }
int main()
{
    // values to swap  
    cout << "Swap \n";
        int a = 5, b = 10;
        cout << a << " & " << b << endl; 
        
        trade(a, b);
        
        cout << a << " & " << b<< endl;
        
        string name1 = "Joe", name2 = "George";
        
        trade(name1, name2);
        
        cout << name1 << " & " << name2 << endl;
        
        

    return 0;
}

// Complex Number Multiplier
// Point F is (3,5)
// Point G is (7,2)
// The Product of F & G is (prod, prod)
// Enter numbers for two ordered pairs represented as points V & C
// Enter x for V: A
// Please enter a number.
// Enter x for V: 2
// Enter y for V: 3
// Enter x for C: 2
// Enter y for C: 2
// Point V is (2,3) Point C is (2,2)
// The product of point V & C is (prod, prod)