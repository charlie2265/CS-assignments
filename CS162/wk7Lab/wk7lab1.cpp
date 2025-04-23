
/******************************************************************************

Charlie Ritter
cs161 Priestley Spring 2024
Week 7 lab1  cpp
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
        Product(): serial {++counter}, sku {""}, desc {""}, price {0}, qty {0} {};
        Product(const Product& source); 
        Product(char arg_sku[], char arg_desc[], double arg_price, int arg_qty);
        int get_serial(){return serial;}
        char* get_desc(){return desc;}
        void output(ostream& os, char ori = 'V');

};

int Product::counter = 1000;

Product::Product(const Product& source): serial {++counter},  price {source.price}, qty {source.qty} {
    strcpy(sku, source.sku);
    strcpy(desc, source.desc);
};

Product::Product(char arg_sku[], char arg_desc[], double arg_price, int arg_qty): serial{++counter}, price{arg_price}, qty{arg_qty}{
    strcpy(sku, arg_sku);
    strcpy(desc, arg_desc);
  
};

void Product::output(ostream& os, char ori = 'V'){

}

int main ()
{
    Product p1 {"RB", "Raisin Bran", 6.99, 100};
    Product p2(p1);

    cout << p1.get_serial() << p1.get_desc() <<endl;
    cout << p1.get_serial() << p2.get_desc() << endl;

    return 0;
}