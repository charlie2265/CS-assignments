/******************************************************************************
Charlie Ritter
cs161 Priestley Spring 2024
Week 6 cpp

sources: Text (Gaddis),charliewk6.cpp, wk6Lab1.cpp, wk6Lab2.cpp, wk7Lab1.cpp, wk7Lab2.cpp
*******************************************************************************/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const string STU_FILE = "C:\\Users\\critter\\OneDrive - Mt. Hood Community College\\MHCC\\Spring24\\CS162\\wk7Lab\\students.dat";
const int SIZE = 4;


// define a class to store a student record 
class Student {
    private:
        static int counter;
        int id;
        char studentName[50];
        char hometown[20];
        char major[20];
        float gpa = 0.00;

    public:
    Student(): id{++counter}, studentName{""}, hometown{""}, major{""}, gpa{0} {};

    // include a method to write the class to the console screen (or to any ostream destination, such as the cin object or a sequential file)
    void outP(ostream& ops) const;

    // include a method to write the class to a random access binary file
    void WriteFile(const string& file, Student* entries, int size);

    // getter method to give access to the id member.
    const int GetId() const {return id; }
    const char* GetStuName() const {return studentName;} // maybe wont need?
    // setter method to update the student name
    void SetStuName(const char* update){
        strncpy_s(studentName, update, sizeof(studentName) -1);
    }
    // constructor with arguments char arguments using strncpy(source, dest, size)
    Student(const char* arg_student, const char* arg_hometown, const char* arg_major, float arg_gpa);
    friend ostream & operator<<(ostream&, Student);
    
};


// prototypes
Student GetId(const string& file, Student* arr);
Student editStudent(const string& file);
bool menu(Student* arr);

int main(){

// declare an array of this class in a file (ID, student name, major, GPA, city of residence)
Student entries[SIZE] = {
                        {"Marge Simpson", "Portland", "Computer Science", 3.5},
                        {"Ned Flanders", "Portland", "Computer Science", 3.5},
                        {"Apu Nahasapeemapetilon", "Portland", "Computer Science", 3.5},
                        {"Seymour Skinner", "Portland", "Computer Science", 3.5}
                        };

//function calls
entries[2].outP(cout << endl);
entries[0].WriteFile(STU_FILE, entries, SIZE);
GetId(STU_FILE, entries);
menu(entries);



    return 0;
}


// constructor with arguments char arguments using strncpy(source, dest, size)
int Student::counter = 1000;
Student::Student(const char* arg_student, const char* arg_hometown, const char* arg_major, float arg_gpa): id{++counter}{            // const int* arg_id,  const float* arg_gpa
        // id = arg_id;
        gpa = arg_gpa;
        strncpy_s(studentName, arg_student, sizeof(studentName) -1 );
        strncpy_s(hometown, arg_hometown, sizeof(hometown) -1 );
        strncpy_s(major, arg_major, sizeof(major) -1 );
    }


// takes ostream as argument and returns nothing
// Display struct data overloading ostream
void Student::outP(ostream& ops) const {
            ops << left << setw(15) << "ID: " << setw(15) << id << endl
                << setw(15) << "Student Name: " << setw(15) << studentName << endl
                << setw(15) << "Home Town: " << setw(15) << hometown << endl
                << setw(15) << "Major: " << setw(15) << major << endl
                << setw(15) << "GPA: " << setw(15) << gpa << endl;
        };



// function attempts to open a file called students.dat if the file is not found to open creates a new file.
// takes string file and Student array as arguments and returns nothing.
void Student::WriteFile(const string& file, Student* entries, int size){
    Student students; // temp object to hold student data from file

    fstream ofile;

    ofile.open(file, ios::out | ios::binary);

    if(ofile.is_open()){
        ofile.write(reinterpret_cast<char*>(entries), 4 * sizeof(Student));
        ofile.close();
    }
    
    // read into array of students
    cout << "file contents \n";
    ofile.open(file, ios::in | ios:: binary);
    if(ofile.is_open()){
        while(ofile.read(reinterpret_cast<char*>(&students), sizeof(Student) )){
            // students.outP(cout);
        }

        ofile.close();
    }
}


Student GetId(const string& file, Student* arr){
    Student query;
    int id;     // user input
    int result = 0; // set index
    int idx = 0;    
    bool found = false; // flag

    cout << "Enter ID: ";
    cin >> id;

    // search array for student by ID
    cout << "From array\n";
    for(int idx = 0; idx < sizeof(Student); ++idx){
        if (id == arr[idx].GetId()){
            result = idx;
            arr[idx].outP(cout);
            found = true;
            break;
        }
    }
        if(!found)
            cout << "Not found \n";
    

    fstream rfile;
    
    rfile.open(file, ios:: in | ios::binary);
    // 
    rfile.seekg( result * sizeof(Student));
    rfile.read(reinterpret_cast<char*> (&query), result * sizeof(Student));
    rfile.close();
    
    cout << "\nFrom file\n"<<endl;
    query.outP(cout);

    return Student();
}

// serach for student by ID and edit student name
// takes string file as argument and returns a Student object.
Student editStudent(const string& file){
    Student query;
    bool found = false;
    int id;
    string updated;
    cin.ignore();
    
    cout << "Enter student ID of student you would like to edit: ";
    cin >> id;

    fstream rfile;

    
    rfile.open(file, ios::in | ios::out | ios::binary);
    // compare id to query object id
    while(rfile.read(reinterpret_cast<char*> (&query), sizeof(Student))){
        if(id == query.GetId()){
            found = true;
            query.outP(cout);
            cout << endl;

        
        cout << "Enter New name: ";
        
        getline(cin, updated);

        // update student name
        query.SetStuName(updated.c_str());
        // set position in file
        double position = static_cast<double>(sizeof(Student));
        rfile.seekp(position, ios::cur);
        // write query object to file
        rfile.write(reinterpret_cast<char*>(&query), sizeof(Student));
        
        cout << "\nUpdated\n";
        query.outP(cout);
        }
        break;
    }

    if(!found)
            cout << "Not found \n";
    rfile.close();

    return Student();
}


// function to display menu options
// takes Student array as argument and returns a boolean
bool menu(Student* arr){
    char choice;

    cout << "Choose an option: \n"
         << "1. Display all students\n"
         << "2. Search for student by ID\n"
         << "3. Edit student Name\n"
         << "q. Quit\n";
    cin >> choice;

    switch(choice){
        case '1':
            for(int idx = 0; idx < 3; ++idx){
                arr[idx].outP(cout << "\n");
            }
            break;
        case '2':
            GetId(STU_FILE, arr);
            break;
        case '3':
            editStudent(STU_FILE);
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





// #define a class to store a student record 
// #include a method to write the class to the console screen (or to any ostream destination, such as the cin object or a sequential file)
// #declare an array of this class in a file (ID, student name, major, GPA, city of residence)
// #If the data file does not already exist, then:
// #populate at least four entries in the array with sample data
// #write the data to a random access binary file
// #close the file
// #Open the file as random access and read the student information into the array of students
// #Prompt the user to enter a student ID
// #Search the array for the student and display the student information on the screen in a nice format
// #ALSO
// #Calculate where in the file the student with this ID can be found and go directly there and get the student info in a temporary object variable (not the array)
// #Display this student's information to the user
// #You have demonstrated that by relying only on the ID and index, you can randomly access a file and retrieve the needed data
// Provide a menu for the user containing at least three options
// Implement these three options as program features using classes 
// For example, you might ask the user to choose to edit the object to change one of its values, display a list of all the objects, or display squares of the object(s).
// If you want to let the user edit the object, the newly-assigned value would need to be passed to a member function that would set or update 
// the private data member. For example, a public inline member function void update_id(char* new_id[]) { strncpy(id, new_id, 11); } would permit 
// the main or another function to change a private data member through a member function call.
// Your program should use these features from Chapter 14:
// #Instance and static member variables (a static member in the constructor can create a sequential student ID #)
// Friend(s) of your class (a good example is operator<<)
// Copy constructor
// Operator overloading