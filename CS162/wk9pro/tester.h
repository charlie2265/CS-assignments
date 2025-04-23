#ifndef TESTER_H
#define TESTER_H
#include <string>

// define a class "Tester" that will store a string name and int score
class Tester {

// data members should be protected
    protected:
        std::string _name;
        int _score();
    public:
    Tester();
    virtual ~Tester();

// public mutators (setters) should be provided    
    void SetName(const std::string& arg_name);
    void SetScore(int arg_score);

// public accessors (getters) should be provided
std::string get_name();
int get_score();


};


#endif












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