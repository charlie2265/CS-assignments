/******************************************************************************
Charlie Ritter
cs161 Priestley Spring 2024
Week 8 cpp

sources: Text (Gaddis),charliewk6.cpp, wk6Lab1.cpp, wk6Lab2.cpp, wk7Lab1.cpp, wk7Lab2.cpp
*******************************************************************************/
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// #define a person class to store basic person information
// #include at least two data members in this base class
class Person 
{
    private:
        char name[51];
        char year[31];
    public:
        Person ();
        Person (const Person& p);   // copy constructor 
        Person (const char* arg_name, const char* arg_year);    // parametized constructor
        char* get_name(){return name;}  // getter
        char* get_year(){return year;}  // getter
        
        virtual void display(ostream& out) const;   // display function




};

// define a student class that "is a" person by inheritance
// add additional data members relevant to this derived class
class Student : public Person
{
    protected:
        int id = 0;
        char major[21];

    public:
    // Student (const Student& s);
    Student (const char* arg_name, const char* arg_year,  int arg_id, const char* arg_major);   // parametized constructor
    int get_id(){return id;}    // getter
    char* get_major(){return major;}    // getter
    void set_id(const int id){}   // setter
    void display(ostream& out);  // display function
    
        

};



int main()
{
// Store the user's choice
char choice[30];

// declare an array of four students and populate the array with data from a disk file or hard-coded
Student people[4] {
                    {"Charlie", "Freshman",1003,"Computer Science"},
                    {"Ricky", "Freshman",1004,"Computer Science"},
                    {"Julian", "Freshman",1005,"Computer Science"},
                    {"Bubbles", "Freshman",1006,"Computer Science"}


                };
// Display the student information
for(Student f: people)
    f.display(cout);
cout << "Choose a student: ";
cin >> setw(30) >> choice;

// prompt the user to enter a student id
// display all information about the student or display an error message, "Student not found," as appropriate
for (Student c : people)
    if (strncmp(c.get_name(), choice, sizeof(c.get_name())) == 0)
        c.display(cout);
    else
        cout << "Student not found" << endl;
    return 0;
}


// define copy constructor
Person :: Person (const Person& p)
{
    strncpy_s(name, p.name, sizeof(name) -1);
    strncpy_s(year, p.year, sizeof(year) -1);
}

// define person constructor
Person :: Person(const char* arg_name, const char* arg_year){
    strncpy_s(name, arg_name, sizeof(name) -1);
    strncpy_s(year, arg_year, sizeof(year) -1);

}

// define Student constructor
Student :: Student (const char* arg_name, const char* arg_year,  int arg_id, const char* arg_major)
    :Person (arg_name, arg_year), id(arg_id){
        strncpy_s(major, arg_major, sizeof(major) -1);
        major[sizeof(major) -1] = '\n';
    };

// define display function for person
void Person :: display(ostream& out)const {
    out << left << setw(15) << "Student Name: " << setw(15) << name << endl 
        << setw(15) << "Year of Study: " << year << endl;
     
     }

// define display function for student
void Student :: display(ostream& out) {
    Person::display(out);
    out << left << setw(15) << "ID: " << setw(15) << id << endl
        << setw(15) << "Major: " << setw(15) << major << endl;
    
}











// #define a person class to store basic person information
// #include at least two data members in this base class
// include a method to write the class object to the console screen (or to any ostream destination, such as the cin object or a sequential file)
// define a student class that "is a" person by inheritance
// add additional data members relevant to this derived class
// declare an array of four students and populate the array with data from a disk file or hard-coded
// prompt the user to enter a student id
// display all information about the student or display an error message, "Student not found," as appropriate