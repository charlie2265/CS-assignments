/******************************************************************************

Charlie Ritter
cs161 Priestley Spring 2024
Week 8 lab1  cpp
I will not electronically copy this into my weekly program

*******************************************************************************/
#include<cstring>
#include<iomanip>
#include <iostream>

using namespace std;

class Firm
{
    protected:
    public:     //temp use private getters n setters in program
        char company_name[31];
        char city[21];
        
    public:
        Firm(); //default constructor
        Firm(const Firm& f) { strncpy_s(company_name, f.company_name, sizeof(company_name) -1) ;}  // copy constructor
        // parameterized constructor
        // getters n setters
        // match the feild name preceded by get or set
        char* get_city(){return city;}
        void set_city(const char arg_city[]) {
            strncpy_s(city, arg_city, strlen(arg_city));
            }
        void display(){cout << "co. Name: " << company_name << endl << "    City: " << city << endl; }
};

class Client: public Firm
{
    protected:
    public:
        char region;
    public:
    void display()
    {
        cout << "Client Information: " << endl;
        Firm::display();
        cout << "Region: " << region << endl;

    }
};

class Vendor: public Firm
{
    protected:
    public:
        int quality;
};

int main()
{



    return 0;
}