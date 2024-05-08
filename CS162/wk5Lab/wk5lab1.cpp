/******************************************************************************

Charlie Ritter
cs161 Priestley Spring 2024
Week 5 lab1  cpp
Working with binary files and structs. 


*******************************************************************************/
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const string FILENAME = "C:\\Users\\critter\\OneDrive - Mt. Hood Community College\\MHCC\\Spring24\\CS162\\wk5Lab\\students.dat";

struct Student
{
    char last[15] = "";
    char first[15] = "";
    int age = 0;

    void output() { cout << setw(17) << last << left << first << setw(4) << age << endl; };

};

int main()
{
    // array of structs
    Student students[3] = {{"Jones", "Chris", 65},
                            {"Gonzalez", "Maria", 21},
                            {"Ritter", "Charlie", 37}
                            };
    // Declare empty Student array named people
    Student people[3];


    Student single;
    char first[15];

    int idx;

    cout << "size of student: " << sizeof(Student) << endl;
    fstream rfile;  // Random access file to store / retrieve data
    //open with file access flags
    rfile.open(FILENAME, ios::out | ios::binary);
    // write students array to file
    rfile.write(reinterpret_cast<char*>(&students), 3 * sizeof(Student));
    rfile.close();

    // read from file to  peaople[] array and display. 
    rfile.open(FILENAME, ios::in | ios::binary);
        rfile.read(reinterpret_cast<char*>(&people), 3 * sizeof(Student));
        rfile.close();
    for(int i = 0; i < 3; ++i){
        people[i].output();
    }

    // search file by first name and display if found 
    rfile.open(FILENAME, ios::in | ios::binary);
    cout << "\nChoose a first name: ";

    cin >> setw(15) >> first;
    
    idx = 0;

    while (idx < 3 && strncmp(first, students[idx].first, 15) != 0)
        ++idx;
    
    //from array
    cout << "From Array" << endl;
    if (idx < 3)
        students[idx].output();
    else
        cout << "Not found! \n";

    //seek
    rfile.seekg(idx * sizeof(Student));
    rfile.read(reinterpret_cast<char*>(&single), 3 * sizeof(Student));
    
    cout << "From file"<< endl;
    single.output();



    
    
    
    
    return 0;
}