/******************************************************************************
Charlie Ritter 

CS162 Priestley SP '24 
Week 1 Lab 2

// Program to read data from a file "data.txt" into a set of arrays (parallel arrays: date, low, high, rain, summary -- which can all be string arrays)
// Random Number Generator to fill an array with random integers
// Program to read data from a file into a set of arrays
// You can simply finish the two programs that we did together in class for full credit or just what we did together for partial credit
// Be sure to attach the .txt text data file, too, because your program requires that file to compile and run
// You are learning to submit everything together so in the future you´ll remember to attach your data file with your program
 
// live lecture word of the day data types

Sources: textbook (Gaddis) 
*******************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
const int MAX = 16; // OR 15 * 18
string const FILENAME = "data.txt";             //"C:\\Users\\critter\\OneDrive - Mt. Hood Community College\\MHCC\\Spring24\\CS162\\wk1Lab\\data.txt";
//finction prototype


int main() {
    // open the file
    ifstream infile(FILENAME);
    // string arrays
    string date[MAX], low[MAX], high[MAX], rain[MAX], summary[MAX], dummy;

    cout << "Hello world!. lets talk weather" << endl;

    if(!infile.is_open()){
        cout << "File error" << endl;
    }
    else 
        cout << "File opened successfully" << endl;
    



    for (int idx = 1; idx < MAX; ++idx) {
        getline(infile, dummy);        
        getline(infile, date[idx], ',');
        getline(infile, low[idx], ',');
        getline(infile, high[idx], ',');
        
        // read the chance of rain here
        getline(infile, rain[idx],  ',');
        getline(infile, summary[idx],  ',');
    }


    infile.close();

    for (int i = 1; i < MAX; ++i){
        cout << date[i] << ":" <<
        low[i] << " to" << high[i]<< " degrees and" << rain[i] << "\% chance of rain. Overall,"
        << summary[i]<< endl;

    }

    return 0;
}



/*
Hello World. let's talk weather
File opened successfully
9/1/2023: 60 to 90 degrees and 10% chance of rain. Overall, mostly sunny.
9/2/2023: 62 to 88 degrees and 20% chance of rain. Overall, partly cloudy.
9/3/2023: 58 to 82 degrees and 40% chance of rain. Overall, scattered showers.
9/4/2023: 55 to 78 degrees and 70% chance of rain. Overall, rainy day.
9/5/2023: 63 to 85 degrees and 15% chance of rain. Overall, sunny intervals.
9/6/2023: 59 to 80 degrees and 25% chance of rain. Overall, scattered clouds.
9/7/2023: 57 to 77 degrees and 50% chance of rain. Overall, showers likely.
9/8/2023: 64 to 88 degrees and 10% chance of rain. Overall, mostly sunny.
9/9/2023: 66 to 92 degrees and 5% chance of rain. Overall, clear skies.
9/10/2023: 61 to 86 degrees and 30% chance of rain. Overall, isolated showers.
9/11/2023: 57 to 78 degrees and 60% chance of rain. Overall, rainy day.
9/12/2023: 62 to 85 degrees and 20% chance of rain. Overall, partly cloudy.
9/13/2023: 68 to 90 degrees and 5% chance of rain. Overall, clear skies.
9/14/2023: 70 to 88 degrees and 0% chance of rain. Overall, sunny day.
9/15/2023: 64 to 82 degrees and 10% chance of rain. Overall, mostly sunny.

*/