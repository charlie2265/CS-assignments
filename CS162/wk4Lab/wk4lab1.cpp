/******************************************************************************
structs-
declare, define, access
overloading operators

Charlie Ritter
cs161 Priestley Spring 2024
Week 4 lab1 cpp

*******************************************************************************/

#include <string>
#include <iostream>
#include <ostream>
using namespace std;

    enum Color {RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET, PINK};

    const string NAMES[] = {"red", "orange", "yellow", "green", "blue", "indigo", "violet", "pink"};

    struct Point;


    struct Point
    {
        double x = 0;
        double y  = 0;

        void output(ostream& os){
            os << '(' << x << ',' << y << ')'; 
        }

    };

    Point operator+(Point p1, Point p2) {
        Point result;
        result.x = p1.x + p2.x;
        result.y = p1.y + p2.y;
        return result;
    }

    // overload the stream operator.  
    ostream& operator<<(ostream& os, Point p) {
        os << "(" << p.x << "," << p.y << ")"; 
        return os;
    }

int main()
{

        Point a {5, 2};
        Point b {7, 9};

        cout << "Point A is ";
        a.output(cout);
        cout << endl;

        cout << "Point B is " << b << endl;

        Color favorite = INDIGO;
    cout << "My favorite color is " << NAMES[favorite] << '.' << endl;

    for (Color c = RED; c <= PINK; c = static_cast<Color>(c + 1)){
        cout << "One color on out palette is " << NAMES[c] << endl;
    }

    return 0;
}