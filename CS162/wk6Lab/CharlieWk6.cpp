/******************************************************************************
Charlie Ritter
cs161 Priestley Spring 2024
Week 6 cpp

sources: Text (Gaddis), wk6Lab1.cpp, wk6Lab2.cpp, wk7Lab1.cpp, wk7Lab2.cpp
*******************************************************************************/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const string CUST_FILE = "C:\\Users\\critter\\OneDrive - Mt. Hood Community College\\MHCC\\Spring24\\CS162\\wk6Lab\\customers.dat";
const int SIZE = 3;


// define a class to store a customer record
class Customer {
    private:
        char id[15] = "";
        // Company name, or none if retail.
        char company[15] = "";
        char city[15] = "";
        char state[4]="";
        // Customer type 'W' wholesale, 'R' retail. 
        char custType[2]="";

    // include a method to write the class to the console screen (or to any ostream destination, 
    // such as the cout object or a sequential file)
    public:
        // Display struct data overloading ostream
        void outP(ostream& ops) const;
        // constructor with no arguments and initializes the class members in the public section
        Customer(){};
        void WriteFile(const string& file, Customer* entries, int size);
        // member function void update_id(char* new_id[]) { strncpy(id, new_id, 11); } would permit the main or /sizeof(char)
        void editCust(char* updId) { strncpy_s(id, sizeof(id), updId, 16); }
        // getter method to give access to the id member. 
        const char* GetId() const { return id; }

        // constuctor with arguments consisting of the class members
        Customer(const char* arg_id, const char* arg_company, const char* arg_city, const char* arg_state, const char* arg_custType) {
            strncpy_s(id, arg_id, sizeof(id) -1 );
            strncpy_s(company, arg_company, sizeof(company) -1 );
            strncpy_s(city, arg_city, sizeof(city) -1 );
            strncpy_s(state, arg_state, sizeof(state) -1 );
            strncpy_s(custType, arg_custType, sizeof(custType) -1 );
            
};
        
         
};

Customer GetId(const string& file, Customer* arr);
Customer editCust(const string& file);
bool menu(Customer* arr);

int main() {
    Customer entries[3] = {
                         {"jreed", "jcpenny", "Beaverton", "OR", "W"},
                         {"sjones", "none", "Gresham", "OR", "R"},
                         {"gtyler", "none", "Beaverton", "OR", "R"}
                          };

    entries[0].WriteFile(CUST_FILE, entries, SIZE);

    GetId(CUST_FILE, entries);
    menu(entries);

    return 0;
}

// Display struct data overloading ostream
// takes ostream as argument and returns nothing
// Display struct data overloading ostream
void Customer::outP(ostream& ops) const {
            ops << left << setw(15) << "ID: " << setw(15) << id << endl
                << setw(15) << "Company: " << setw(15) << company << endl
                << setw(15) << "City: " << setw(15) << city << endl
                << setw(15) << "State: " << setw(15) << state << endl
                << setw(15) << "Customer Type: " << setw(15) << custType << endl;
        };

// function attempts to open a file if the file is not found creates a new file.
// takes string file and entries array as arguments and returns nothing.
void Customer::WriteFile(const string& file, Customer* entries, int size){
   
    fstream ofile;

    ofile.open(file, ios::out | ios::binary);

    if(ofile.is_open()){
        cout << "It worked" << endl;
        // write array to file
        ofile.write(reinterpret_cast<char*>(entries), 3 * sizeof(Customer));
        ofile.close();
    }

}

// Prompt the user to enter a client ID and search the array for the client and display the client information on the screen
// takes string file and Customer array as arguments and returns a Customer object.
Customer GetId(const string& file, Customer* arr){
    Customer query[1] = {};     // temporary object variable
    char id[15];           // client ID
    int idx = 0;        // index


    cout << "Enter ID: ";
    cin >> setw(15) >> id;
    
    while(idx < 3 && strncmp(id, arr[idx].GetId(), 15) != 0 )
        ++idx;
    if (idx < 3)
        arr[idx].outP(cout);
    else
        cout << "Not found \n";

// Calculate where in the file the client with this ID can be found and go directly there and 
// get the client info in a temporary object variable (not the array)
    fstream rfile; 

    rfile.open(CUST_FILE, ios::in | ios::binary);

    rfile.seekg(idx * sizeof(Customer));    // set position in file
    rfile.read(reinterpret_cast<char*>(query), 1 * sizeof(Customer));       // read file into query object
    rfile.close();

    cout << "\nFrom file\n"<< endl;
    query[0].outP(cout);        // display query object

    

    return Customer();
}

// Search the file for the client and display the client information on the screen and edit the client information
// takes string file as argument and returns a Customer object.
Customer editCust(const string& file) {
    Customer query;     // temporary object variable
    char id[15];       // client ID
    char updated[15];   // updated client ID

    cout << "Enter ID to change: ";
    cin >> id;
    fstream rfile;

    rfile.open(file, ios::in | ios::out | ios::binary); 
    while (rfile.read(reinterpret_cast<char*>(&query), sizeof(Customer))) {     // read file into query object
        if (strcmp(query.GetId(), id) == 0) {                                   // compare id to query object id
            query.outP(cout);                                               // display query object
            cout << "\n";

            cout << "Enter a new ID: ";
            cin >> updated;

            query.editCust(updated);                                    // edit query object
            long ps = -static_cast<long>(sizeof(Customer));             // get position in file
            rfile.seekp(ps, ios :: cur);                                // set position in file

            rfile.write(reinterpret_cast<char*>(&query), sizeof(Customer)); // write query object to file

            cout << "\nUpdated\n";                                   // display updated object
            query.outP(cout);
            break;
        }
        else
            cout << "Not found\n";
    }

    return Customer();
}

// Provide a menu for the user containing at least three options
// Implement these three options as program features using classes
// takes Customer array as argument and returns a boolean.
bool menu(Customer* arr){
    char choice; // menu choice

    cout << "Choose an option: \n"
         << "1. Display all customers\n"
         << "2. Search for customer by ID\n"
         << "3. Edit customer\n"
         << "q. Quit\n";
    cin >> choice;

    switch(choice){
        case '1':
            for(int idx = 0; idx < 3; ++idx){
                arr[idx].outP(cout << "\n");
            }
            break;
        case '2':
            GetId(CUST_FILE, arr);
            break;
        case '3':
            cout << "Edit customer\n";
            editCust(CUST_FILE);
            break;
        case 'q':
        case 'Q':
            return false;
            break;
        default:
            cout << "Invalid choice\n";
            break;
    }
    return true;
}


// get the client info in a temporary object variable (not the array)

    


// Turn in a program that meets the following requirements


// declare an array of this class  in a file (ID, company name, city/state, customer type)

// If the data file does not already exist, then:
// populate at least three entries in the array with sample data
// write the data to a random access binary file
// close the file
// Open the file as random access and read the client information into the array of clients
// Prompt the user to enter a client ID
// Search the array for the client and display the client information on the screen
// ALSO
// Calculate where in the file the client with this ID can be found and go directly there and 
// get the client info in a temporary object variable (not the array)
// Display this information to the user
// You have demonstrated that by relying only on the ID and index, you can randomly access a file 
// and retrieve the needed data
// Provide a menu for the user containing at least three options
// Implement these three options as program features using classes 
// For example, you might ask the user to choose to edit the object to change one of its values,
//  display a list of all the objects, or display squares of the object(s).
// If you want to let the user edit the object, the newly-assigned value would need to be passed 
// to a member function that would set or update the private data member. For example, a public inline 
// member function void update_id(char* new_id[]) { strncpy(id, new_id, 11); } would permit the main or 
// another function to change a private data member through a member function call.