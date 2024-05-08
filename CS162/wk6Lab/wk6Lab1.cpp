/******************************************************************************

Charlie Ritter
cs161 Priestley Spring 2024
Week 6 lab1  cpp
Working with classes. 

Static
*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Point {
    private:            //access specifier
        double x;
        double y;
    
    public:             // access specifier
        Point();
        Point(double, double);
        ~Point();
        void output(ostream&);
        friend ostream& operator<<(ostream& os, Point p);
};

Point::Point(){
    x = 0.0;
    y = 0.0;
}

Point::Point(double arg_x, double arg_y){
    x = arg_x;
    y = arg_y;
}

Point::~Point(){
    x = 0.0;
    y = 0.0;
}
void Point::output(ostream& os){
    os << '(' << x << ", " << y << ')';
};

ostream& operator<<(ostream& os, Point p){
    //os << '(' << x << ", " << y << ')';
    p.output(os);
    return os;
}


int main()
{
    Point a;
    Point b(5, 10);

    cout << "Point b is ";
    b.output(cout);
    cout << endl;

    cout << "Point a is " << a << " and Point b is " << b;
        


    return 0;
}