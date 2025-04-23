/******************************************************************************

Charlie Ritter
cs161 Priestley Spring 2024
Week 6 lab2  cpp
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
        friend Point Square(const Point& p2);

        // Implement a friend function that overloads the * operator to multiply a double left operand by a Point right operand.
        // Hint: Point operator*(double d, const Point &p) { return p * d; }
        friend Point operator*(double d, const Point& p2){
            Point product;
            product.x = d * p2.x;
            product.y = d * p2.y;
            return product;
        }

    // Implement a member function that returns a bool: true if the argument matches the
            // Point object's x value and false otherwise. (Keep this in mind for the Week 6 Program.)
    // Hint: bool match(double value) { return x == value }
    bool match(double xmatch){
        return x == xmatch;
           
    }

    // Implement a member function that overloads the + operator to add two points.
    // Hint: Point operator+(const Point other) { return Point( x + other.x, y + other.y);
    Point operator+(const Point& p2){
        Point sum;
            sum.x = p2.x + x; 
            sum.y = p2.y + y;
        return sum;
    }

    // Implement a member function that overloads the * operator to multiply a Point left operand by a double right operand.
    // Hint: Point operator*(double d) { return Point( x * d, y * d); }
    Point operator*(double a){
        Point product;
        product.x = a * x;
        product.y = a * y;

        return product;
    }
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

Point addy(Point a, Point b){
    Point c;
    c = a + b;
    cout << "The sum of points A and B are:  ";
    c.output(cout);
    cout << endl;
    return c;
}

Point prod(Point a){
    Point c;
    double d = 2;
    c = a * d;
    cout << "Point " << a << " multiplied by 2 is: ";
    c.output(cout);
    cout << endl;
    return c;
}

Point fprod(Point a){
    Point c;
    double d = 2;
    c = d * a;
    cout << "friend Overload function did this: ";
    c.output(cout);
    cout << endl;
    return c;
}

// Implement a non-member friend function called Square that returns the square of a
// Point by squaring each of its operands but does not modify the argument passed to it.
// Hint: Point Square(const Point &p) { return Point( p.x * p.x, p.y * p.y); }
Point Square(const Point& p2){
    return Point(p2.x * p2.x, p2.y * p2.y);
}
// Implement a non-member non-friend function called DispPair that displays a pair of Points 
// with the word " and " between them (all to the console).
void DispPair(Point& p1, Point& p2){
    
    p1.output(cout);
    cout << " and ";
    p2.output(cout);

}

int main()
{
    Point a(1, 1);
    Point b(5, 10);
    double e = 1;

    cout << "Point b is ";
    b.output(cout);
    cout << endl;

    cout << "Point A is " << a << " and Point B is " << b << endl;
    bool matches = a.match(e);
    cout << matches << endl;
    addy(a,b);
    prod(b);
    fprod(b);
        


    return 0;
}