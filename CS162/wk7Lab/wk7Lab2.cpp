
/******************************************************************************

Charlie Ritter
cs161 Priestley Spring 2024
Week 7 lab2  cpp
Working with classes. 

Static
*******************************************************************************/
#include <cstring>
#include <cctype>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const string FILEF = "C:\\Users\\critter\\OneDrive - Mt. Hood Community College\\MHCC\\Spring24\\CS162\\wk5Lab\\Products.dat";

class Product {
    private:
        static int counter;
        int serial;
        char sku[16];
        char desc[31];
        double price;
        int qty;
    public:
    // constructor with no arguments and initializes the class members in the public section
        Product(): serial {++counter}, sku {""}, desc {""}, price {0}, qty {0} {};

        // copy constructor
        Product(const Product& source); 

        // constructor with arguments consisting of the class members
        Product(const char arg_sku[], const char arg_desc[], double arg_price, int arg_qty);
        int get_serial(){return serial;}
        char* get_desc(){return desc;}
        // Display struct data overloading ostream
        void output(ostream& os, char ori = 'V');
        operator double() {return price;}
        // overloading the << operator with a friend function
        friend ostream& operator<<(ostream&, Product);

};

int Product::counter = 1000;

Product::Product(const Product& source): serial {++counter},  price {source.price}, qty {source.qty} {
    strncpy_s(sku, source.sku, sizeof(sku) - 1);
    strncpy_s(desc, source.desc, sizeof(desc) - 1);
};
// constructor with arguments consisting of the class members
Product::Product(const char arg_sku[], const char arg_desc[], double arg_price, int arg_qty): serial{++counter}, price{arg_price}, qty{arg_qty}{
    strncpy_s(sku, arg_sku, sizeof(sku) - 1);
    strncpy_s(desc, arg_desc, sizeof(desc) - 1);
  
};

// Display struct data overloading ostream
void Product::output(ostream& os, char ori){
    ori = toupper(ori);

    if (ori == 'V') {
        os << setw(15) << "Serial #: " << serial << endl;
        os << setw(15) << "SKU: " << sku << endl;
        os << setw(15) << "Description: " << desc << endl;
        os << setw(15) << "Price: " << setprecision(2) << fixed << price << endl;
        os << setw(15) << "On hand: " << qty << endl;
        os << endl;
    }

    else {
        os << setw (10) << serial << ' ';
        os << setw (15) << sku << ' ' << setw(30) << desc << ' ';
        os << setw(9) << setprecision(2) << fixed << price << ' ';
        os << setw(9) << qty << endl;

    }
        
}

ostream& operator<<(ostream& os, Product p){
    p.output(os, 'V');
    return os;

}


int main ()
{
    double x = 0.0;
    Product p1 {"RB", "Raisin Bran", 6.99, 100};
    Product p2(p1);

    // cout << p1.get_serial() << p2.get_desc() << endl;
    // cout << p1.get_serial() << p1.get_desc() <<endl;

    p1.output(cout);
    p2.output(cout);

    p1.output(cout, 'H'); // horizontal output
    p2.output(cout, 'H'); // horizontal output

    x = p1;

    cout << "x is " << x << endl;
    cout << p1;


    return 0;
}