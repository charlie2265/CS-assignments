/******************************************************************************
Charlie Ritter
cs161 Priestley Spring 2024
Week 4 program cpp

This program will take ordered pairs such as a point on a graph or on 
the complex number plane and perform multiplication to them.  

Public
Sources: Text (Gaddis), Week 4 lab1 cpp (Priestley), https://math.libretexts.org/Bookshelves/Precalculus/Precalculus_1e_(OpenStax)/03%3A_Polynomial_and_Rational_Functions/3.01%3A_Complex_Numbers
*******************************************************************************/
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

// struct to represent complex numbers.
struct Pair
{
    // represents the real number 
    double a = 0;
    // holds imaginary number
    double b = 0;
    
    // member function template output for complex number to display as an ordered pair (na, nb).
    // takes an output stream to write values to. 
    void outP(ostream& ops){
        ops << '(' << a << ',' << b << ')';
    }
};

// overloading * operator to perform multiplication to two ordered pairs. 
// takes two instances of Pair as arguments. 
// returns another instance product.
Pair operator * ( Pair p1, Pair p2){            
    Pair product;
    product.a = p1.a * p2.a - p1.b * p2.b;   //[a1 * a2] - [b1 * b2],  
    product.b = p1.a * p2.b + p1.b * p2.a;  // [a1 * b2] + [b1 * a2] ), which is a complex number
    return product;
}


//function prototypes
Pair complexDisp(Pair f, Pair g);
Pair complexProd(Pair f, Pair g);
Pair complexManip(Pair v, Pair c);


int main()
{
    // instances of Pair object initializing the member variables.
    Pair f {3, 5};
    Pair g {7, 2};
    Pair v, c;      // Entered by user during complexManip() call

     
    cout << " Complex Number Multiplier (CNM)" << endl;

    // function calls
    complexDisp(f, g);
    complexProd(f, g);
    complexManip(v, c);

    return 0;
}

// Pair function that displays the values of the member variables
// takes the Pair objects f & g as parameters and returns the Pair object.
// essentially returns (nothing) like a void function. 
Pair complexDisp(Pair f, Pair g){
    
    cout << "Point F is "; 
    f.outP(cout);   // use memeber function to display values
    cout << endl;

    cout << "Point G is ";
    g.outP(cout);
    cout << endl;

    // Return a default-initialized Pair object
    return Pair();
}

// Performs complex multiplication to the member valuse of the Pair struct
// takes Pair objects f & g as parameters and returns the product.
Pair complexProd(Pair f, Pair g){

    Pair product;

    product = f * g;

    cout << "The Product of F & G is ";
    product.outP(cout);
    cout << endl;

    return product;
}

// Takes values for number pairs from the user, perfoms complex number multiplication
// and displays the product. Takes unintialized Pair objects v & c to take user input
// returns the product. 
Pair complexManip(Pair v, Pair c){

    Pair product;
    string dummy;

    cout << "Enter x value for point V: ";

    while (!(cin >> v.a))
    {
        cout << "Please enter a number: ";
        cin.clear();
        getline(cin, dummy);
    }
    
    cout << "Enter y value for point V: ";
    while (!(cin >> v.b))
    {
        cout << "Please enter a number: ";
        cin.clear();
        getline(cin, dummy);
    }
    
    cout << "Enter x value for point C: ";
    while (!(cin >> c.a))
    {
        cout << "Please enter a number: ";
        cin.clear();
        getline(cin, dummy);
    }
    
    cout << "Enter y value for point C: ";
    while (!(cin >> c.b))
    {
        cout << "Please enter a number: ";
        cin.clear();
        getline(cin, dummy);
    }
    
    cout << "Point V is ";
    v.outP(cout);
    cout << " Point C is ";
    c.outP(cout);
    cout << endl;

    product = v * c;
    cout << "The product of point V & C is ";
    product.outP(cout);
    cout << endl;

    return product;
}
    


    









// Turn in a program that meets the following requirements
// Define a struct to store a complex number on the complex number plane
// Overload the * operator to perform a dot product of two complex numbers
// (a1, b1) * (a2, b2)   =  ( [a1 * a2] - [b1 * b2],  [a1 * b2] + [b1 * a2] ), which is a complex number -- think FOIL as with a binomial
// In simpler form, the product can be written as (a1a2 - b1b2, a1b2 + b1a2) where multiplication is being implied
// Stated for you using alternative notation
// (a, b) * (c, d) = (ac-bd,  ad+bc)
// demonstrate the functionality of these features through I/O

/*
Sure, I'd be happy to explain!

A **complex number** is a number that can be expressed in the form **a + bi**, where **a** and **b** are real numbers, and **i** is the imaginary unit, which satisfies the equation **i² = -1**. In this expression, **a** is the real part and **b** is the imaginary part of the complex number.

The **complex number plane** (also known as the Argand plane) is a geometric representation of these numbers. It's similar to the Cartesian plane we use for real numbers, but it has a real axis (horizontal axis) and an imaginary axis (vertical axis).

Here's how a complex number **z = a + bi** is represented on the complex plane:

- The **real part 'a'** corresponds to the x-coordinate on the horizontal axis.
- The **imaginary part 'b'** corresponds to the y-coordinate on the vertical axis.

So, the complex number **z** is represented as a point **(a, b)** on the plane.

This representation allows us to visualize operations on complex numbers, such as addition, subtraction, multiplication, and division, as geometric transformations in the plane. It's a powerful tool in fields like engineering, physics, and computer science where complex numbers are used. 

I hope this helps! Let me know if you have any other questions. 😊

*/