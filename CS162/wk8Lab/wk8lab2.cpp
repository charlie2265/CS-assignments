/******************************************************************************

Charlie Ritter
cs161 Priestley Spring 2024
Week 8 lab2  cpp
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
        Firm (const char* arg_companyName, const char* arg_city);
        // getters n setters
        // match the feild name preceded by get or set
        char* get_city(){return city;}
        void set_city(const char arg_city[]) {
            strncpy_s(city, arg_city, strlen(arg_city));
            }
        virtual void display(){cout << "co. Name: " << company_name << endl << "    City: " << city << endl; }
};

class Client: public Firm
{
    protected:
    public:
        char region;
    public:
        Client(const char* arg_companyName, const char* arg_city, char arg_region);
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
        int quality; // 1 to 10 scale (10 is best)
        Vendor(const char* arg_companyName, const char* arg_city, int arg_quality);
};

int main()
{
    Client client[4] {
                        {"Nike", "Beaverton", 'W'},
                        {"Adidas", "Beaverton", 'W'},
                        {"Daimler", "Beaverton", 'W'},
                        {"Patagonia", "Beaverton", 'W'}

                      };
    char choice[30];
    cout << "Inheritance Program" << endl << endl;

    cout << "Choose one of the following client firms: ";
    for(Client c: client)
        cout << c.company_name << ' ';
    cout << endl;
    cout << "Your choice: ";

    cin >> setw(30) >> choice;

    for (Client c : client)
        if (strncmp(c.company_name, choice, sizeof(c.company_name)) == 0)
            c.display();

    Vendor vendor {"Coca-cola", "Atlanta", 2};
    vendor.display();
    
    cout << endl << "Run-Time Polymorphism" << endl;

    Firm* f;

    f = &vendor;
    // f= &client[2];
    // f = new Firm;

    f->display();


    return 0;
}

Firm :: Firm (const char* arg_companyName, const char* arg_city){
    strncpy_s(company_name, arg_companyName, sizeof(company_name) -1);
    strncpy_s(city, arg_city, sizeof(city) -1);
    
}

Client::Client(const char* arg_companyName, const char* arg_city, char arg_region)
    : Firm(arg_companyName, arg_city), region(arg_region){}

Vendor :: Vendor(const char* arg_companyName, const char* arg_city, int arg_quality)
    :Firm(arg_companyName, arg_city), quality(arg_quality){}


