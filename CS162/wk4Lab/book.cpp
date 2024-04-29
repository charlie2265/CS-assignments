 #include <iostream>
 #include <string>
 using namespace std;


struct Product{
    string description;
    int partNum;
    double cost;
};

struct Measurement{
    int miles;
    long meters;
};

struct Destination{
    string city;
    Measurement distance;
};


 int main()
 {

    Destination trip;

    trip.city = "Tupelo";
    trip.distance.miles = 375;
    trip.distance.meters = 603,375;

    



    Product arr[100];

    for(int idx = 0; idx < 100; ++idx){
        arr[idx].description = "";
        arr[idx].partNum = 0;
        arr[idx].cost = 0;
    }

    arr[0].description = "Claw Hammer";
    arr[0].partNum = 547;
    arr[0].cost = 8.29;

    for(int idx = 0; idx < 100; ++idx){
        cout << arr[idx].description << endl;
        cout << arr[idx].partNum << endl;
        cout << arr[idx].cost << endl;

    }


     return 0;\
 }
  
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

struct Complex {
    double a;  // real part
    double b;  // imaginary part

    // Constructor
    Complex(double a = 0.0, double b = 0.0) : a(a), b(b) {}

    // Overload * operator
    Complex operator*(const Complex& rhs) const {
        return Complex(a * rhs.a - b * rhs.b, a * rhs.b + b * rhs.a);
    }
};

// Function to print a complex number
void printComplex(const Complex& c) {
    std::cout << "(" << c.a << ", " << c.b << ")" << std::endl;
}

int main()
{
    Complex c1(3.0, 2.0);  // complex number (3, 2)
    Complex c2(1.0, 7.0);  // complex number (1, 7)

    // Multiply two complex numbers
    Complex result = c1 * c2;

    // Print the result
    printComplex(result);



    return 0;
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 // This program uses nested structures.
    //  // Define a structure variable to hold info about the manager.
    //  Place residence;           // Nested structure
//  // The Date structure holds data about a date.
//  struct Date
//  {
//      int month;
//      int day;
//      int year;
//  };
//  // The Place structure holds a physical address.
//  struct Place
//  {
//      string address;
//      string city;
//      string state;
//      string zip;
//  };
//  // The EmployeeInfo structure holds an employee's data.
//  struct EmployeeInfo
//  {
//      string name;
//      int employeeNumber;
//      Date birthDate;            // Nested structure
//  };
    //  EmployeeInfo manager;
    //  // Get the manager's name and employee number
    //  cout << "Enter the manager's name: ";
    //  getline(cin, manager.name);
    //  cout << "Enter the manager's employee number: ";
    //  cin >> manager.employeeNumber;
    //  // Get the manager's birth date
    //  cout << "Now enter the manager's date of birth.\n";
    //  cout << "Month (up to 2 digits): ";
    //  cin >> manager.birthDate.month;
    //  cout << "Day (up to 2 digits): ";
    //  cin >> manager.birthDate.day;
    //  cout << "Year: ";
    //  cin >> manager.birthDate.year;
    //  cin.ignore();  // Skip the remaining newline character
    //  // Get the manager's residence information
    //  cout << "Enter the manager's street address: ";
    //  getline(cin, manager.residence.address);
    //  cout << "City: ";
    //  getline(cin, manager.residence.city);
    //  cout << "State: ";
    //  getline(cin, manager.residence.state);
    //  cout << "ZIP Code: ";
    //  getline(cin, manager.residence.zip);
    //  // Display the information just entered
    //  cout << "\nHere is the manager's information:\n";
    //  cout << manager.name << endl;
    //  cout << "Employee number " << manager.employeeNumber << endl;
    //  cout << "Date of birth: ";
    //  cout << manager.birthDate.month << "-";
    //  cout << manager.birthDate.day << "-";
    //  cout << manager.birthDate.year << endl;
    //  cout << "Place of residence:\n";
    //  cout << manager.residence.address << endl;
    //  cout << manager.residence.city << ", ";
    //  cout << manager.residence.state << " ";
    //  cout << manager.residence.zip << endl;