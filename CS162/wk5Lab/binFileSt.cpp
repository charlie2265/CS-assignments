/******************************************************************************

using binary files and structs

*******************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const string FILEF = "C:\\Users\\critter\\OneDrive - Mt. Hood Community College\\MHCC\\Spring24\\CS162\\wk5Lab\\struct.dat";

struct Student{
    char name[50];
    int age;
    float gpa;
};


int main ()
{
    Student stu = {"Hank", 48, 3.58};

    fstream f;
    f.open(FILEF, ios::out | ios::binary);

    if (f.is_open()){
        f.write(reinterpret_cast<char*>(&stu), sizeof(Student));
        f.close();
    }
    else
     cout << "Error!\n";
    
    Student newStu;

    f.open(FILEF, ios::in | ios::binary);
    if(f.is_open()){
        f.read(reinterpret_cast<char*>(&newStu), sizeof(Student));
        f.close();

    }
    else
        cout << "Error!\n";
    
    cout << newStu.name << endl;
    cout << newStu.age << endl;
    cout << newStu.gpa << endl;


    cin.ignore();
    cin.get();

    return 0;
}