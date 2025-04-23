/******************************************************************************

Charlie Ritter
cs161 Priestley Spring 2024
Week 9 cpp
sources: Text (Gaddis) and charliewk9.cpp/cs161 
*******************************************************************************/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "tester.h"
using namespace std;

const int MAX = 12; // max size of array

// opens a sample sequential text data file to read (I have provided the file scores.txt)
const string FILENAME = "C:\\Users\\critter\\OneDrive - Mt. Hood Community College\\MHCC\\Spring24\\CS162\\wk9Lab\\scores.txt";

// prtototypes
int loadData(Tester tester[]);



int main () 
{
    Tester tester[MAX] {};
    int size{}; // track number of people
    
    cout << "welcome to the tester program" << endl;

    size = loadData(tester);  // displays all data on screen, one name and number per line, from the array, using a function call 
    
    
    Tester::linSearch(tester, MAX);
    Tester::scoreSort(tester, MAX);
    Tester::scoreSearch(tester, MAX);
    Tester::testerSort(tester,MAX);
    Tester::nameSearch(tester, MAX);
    Tester::highScore(tester, MAX);
    Tester::lowScore(tester, MAX);

    return 0;

}


// Opens file and loads data into array
// the array tester is passed by reference
// returns the number of people read into the array
int loadData(Tester tester[])
{
    // Declare variable to count the data and retain the value to return
    int dataCount{};

    // Use to store names and scores from file to be stored in array
    int score;
    string name;

    // Open the sequential file for input
    fstream infile (FILENAME, ios::in);

    //verify if file was opened successfully
    if(!infile.is_open())
    {
        cout << "Error! file was not found: " << FILENAME << "\n";
        exit(1);
    }

   
   
   // uses a loop to read names and ints into array "tester" of type Tester until it reaches the end of the file
    do
    {
        infile >> name >> score >> ws; // ws - white space

        // cerr << name << score << '\n'; // for debugging

        if(infile)
        {
            tester[dataCount].SetName(name);
            tester[dataCount].SetScore(score);
            tester[dataCount].display(cout);
            ++dataCount;             // the data pairs should be counted as they are read in and the count should be retained

        }

    } while (dataCount < MAX && !infile.eof());

    return dataCount;
}







// Your program's requirements are to write an original program (turn in the program cpp):
// Part 1 
// define a class "Tester" that will store a string name and int score
// data members should be protected
// public accessors (getters) should be provided
// public mutators (setters) should be provided
// it is okay to use string objects this time, because we won't be using a random access file
// opens a sample sequential text data file to read (I have provided the file scores.txt)
// uses a loop to read names and ints into array "tester" of type Tester until it reaches the end of the file OR reaches the maximum size of the array (const MAX = 100)
// the data pairs should be counted as they are read in and the count should be retained (remembered in a variable  'size' or 'data_count') by the program
// (Hint: This means that LoadData returns an int giving the size)
// displays all data on screen, one name and number per line, from the array, using a function call (e.g., to void DisplayAll(Tester arr[], int size)
// demonstrates that it can look up data by name using a linear (sequential) search
// So far the program can earn up to 70% credit
// Part 2
// goes on to sort the array according to the int data member using selection sort, thereby ordering the data in ascending numeric order by score (see Chapter 8)
// displays all data on screen, one name and number per line
// demonstrates that it can look up data by score using a binary search (see Chapter 8)
// prompts user to enter a score
// program finds at least one person with that score and displays their info (okay to display everyone with that score)
// So far the program can earn up to 85% credit
// Part 3
// goes on to sort array according to the string data member using bubble sort, thereby ordering the data alphabetically by name
// demonstrates that it can look up data by name using a binary search
// lists the names of the person(s) with the highest score
// lists the names of the person(s) with the lowest score
// The complete program can earn up to 105% credit! Do your best work.
// Indicate in your header comments whether you completed Parts 1, 2, and/or 3 and the maximum points you think your submission is eligible for
// Imagine if you were reading these scores into a linked list instead of an array to give your thinking a head start for next week's program
// Hints
// Remember to keep your main as short as possible, under 20 statements, just variable declarations and function calls