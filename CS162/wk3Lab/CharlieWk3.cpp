/******************************************************************************
Movie Trivia Game

Specifications:
- Should have at least 6 questions
- Should keep track of the number of correct answers
- Should display the number of correct answers at the end of the game
- Multiple choice questions\
- Each question represents a space on the game board
- Spaces are kept in an array
- Prizes are kept in a parallel array
- a correct answer awards a point.
- a wrong answer does not award a point.
- 3 random outcomes will be popcorn, soda, and nachos (prizes).

Charlie Ritter
cs161 Priestley Spring 2024
Week 3 Program cpp
Sources: Text (Gaddis),
CS161 Winter wk3 Program (Me, Charlie). https://stackoverflow.com/questions/15485418/c-reading-from-a-file-if-condition-with-fail-or-try-catch,

*******************************************************************************/
#include <fstream>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

// Element sizes for arrays declared as constans
const int 
    SIZE = 11, //rows
    COLS = 3; // colums

// path to files. 
const string 
    WELCOME = "C:\\Users\\critter\\OneDrive - Mt. Hood Community College\\MHCC\\Spring24\\CS162\\wk3Lab\\welcome.txt",
    QUESTIONS = "C:\\Users\\critter\\OneDrive - Mt. Hood Community College\\MHCC\\Spring24\\CS162\\wk3Lab\\questions.txt",
    CHOICES = "C:\\Users\\critter\\OneDrive - Mt. Hood Community College\\MHCC\\Spring24\\CS162\\wk3Lab\\answers.txt",
    PRIZES = "C:\\Users\\critter\\OneDrive - Mt. Hood Community College\\MHCC\\Spring24\\CS162\\wk3Lab\\snax.txt";

// Function Prototypes
// Last peice 
string welcome(string welfile);
// - Read questions from a file
bool fromQsFile(string qfile, string arr[], int SIZE);
bool fromSFile(string sfile, string arr[], int SIZE);
bool fromCFile(string cfile, string harr[], string arr[][COLS], int SIZE);

//Ask questions
string askQuestions(string harr[], string arr[][COLS],string qarr[], int SIZE);
//User input
string userInput(string harr[], string arr[][COLS], string qarr[], int SIZE);


//Determine answers
//Assign points
//Assign random prize
//Overall standing


int main(){
    string
        answerKey[SIZE],
        selection[SIZE][COLS], // Holds the multiple choice selections
        header[COLS],           // Holds the choice Identifiers
        qarray[SIZE],           // Holds the trivia questions
        snacks[SIZE];           // Holds the prizes - theater snacks

// Function calls
fromQsFile(QUESTIONS, qarray, SIZE);
fromSFile(PRIZES, snacks, SIZE);
fromCFile(CHOICES, header, selection, SIZE);


askQuestions(header, selection, qarray, SIZE);




    return 0;
}

// Function to display welcome message game description from 
//a text file. takes the path to the file and returns a string
// that is displayed to the user. 
string welcome(string welfile){

    string message;
    
    return message;
}


// Function to read trivia questions from a file to a string array
// Takes the questions file, the string array, and the allocated array size as 
// parameters. Returns true if the file opens reads to the array and closes successfully. 
bool fromQsFile(string qfile, string arr[], int SIZE){
    ifstream ifile(qfile);
    if (ifile.fail()){
        cerr << "error opening " << qfile << endl;
        return false; 
    }
    //  ifile.open(qfile);

     for(int idx = 0; idx < SIZE; ++idx){     
        getline(ifile, arr[idx]);
        
        //error check during reading
        if(ifile.fail()){
            cerr << "error reading " << qfile  << endl;
            return false;
        }

        if(ifile.eof())
            break;
     }

     ifile.close();

    return true;
}

// Function to read prize snacks from a file to a string array
// Takes the snax file, the string array, and the allocated array size as 
// parameters. Returns true if the file opens, reads to the array, and closes successfully
bool fromSFile(string sfile, string arr[], int SIZE){
    ifstream ifile(sfile);

    if(ifile.fail()){
        cerr << "Error opening: " << sfile << endl;
        return false;
    }

    for(int idx = 0; idx < SIZE; ++idx){
        getline(ifile, arr[idx]);

        // error check during reading
        if(ifile.fail()){
            cerr << "Error reading: " << sfile << endl;
            return false;
        }

        if (ifile.eof())
            break;
    }


    ifile.close();

    return true;
}

// Function to read multiple choice questions to a header array with the 
// choice letter and a 2d array with corresponding possible answers. 
// Take the CHOICES file, an array, and a 2d array with column size, and row size
// as arguments and returns true if the file successfully opens and reads to the arrays. 
bool fromCFile(string cfile, string harr[], string arr[][COLS], int SIZE){
    ifstream ifile(cfile);

    if(ifile.fail()){
        cerr << "Error opening: " << cfile << endl;
        return false;
    }

    // put top row in header array
    for(int idx = 0; idx < 4; ++idx){
        getline(ifile, harr[idx], ' ');

        if(ifile.fail()){
        cerr << "Error reading to header: " << cfile << endl;
        return false;
    
        }
    }
      for(int idx = 0; idx < SIZE; ++idx){
        
        for(int col = 0; col < COLS; ++col){
            getline(ifile, arr[idx][col]);

        // cout << arr[idx][col] << endl;
        //     if(ifile.fail()){
        //         cerr << "Error reading choices: " << cfile << endl;
        //         return false;
        // }
    }

}

    ifile.close();

    return true;
}

string userInput(string harr[], string arr[][COLS], string qarr[], int SIZE){
    string answer; //hold user input
    
    cout << "Enter Answer: ";
    cin >> answer;

    return answer;
}


// Function that displays question from question array and choices with header from 
// selection and header array. 
string askQuestions(string harr[], string arr[][COLS], string qarr[], int SIZE) {
    string input;
    int i = 0;

    do {
        cout << qarr[i] << endl; // Display the question from qarr
        for(int hdr = 0; hdr < COLS; ++hdr){
            cout << harr[hdr]; // Display the header array
        }
        // cout << endl;

        for (int j = 0; j < SIZE; ++j) {
            // Display the corresponding choices
            for (int k = 0; k < COLS; ++k) {
                cout << arr[j][k] << endl;
            }
            cout << "Enter your answer: ";
            cin >> input;
        }

        i++;
    } while (i < SIZE);

    return input;
}



 /*
 psudocode for askQuestions() function{
    display first question from the first element of qarr
        increment to next element after input.
    display the header array 
    display first row of arr[][] 
        increment to next after input
    take user input and repeat above until the end of qarr

    return input.
}
    */
        
// for(int idx = 0; idx < SIZE; idx++ ){
//         cout << harr[idx]; 
//     }
//     for (int idx = 0; idx < SIZE; ++idx){

//         for(int col = 0; col < COLS; ++col ){
//             cout << arr[idx][col] << endl;
//             // askQuestions(harr, arr, qarr, SIZE);
//         }
//     }

    
    // for(int idx = 0; idx < SIZE; ++idx){
    //     cout << arr[idx] << endl;
    // }
        
















/*
input a first name
design a game board with 4 to 6+ spaces 
introduce the game to the player (use their name once)
each turn, the player should advance one space
each space should have a description
each space should have a consequence, positive or negative, tracked by a variable
random outcomes should be built into the game
consider prizes, points, life, damage, etc. and/or other positive and/or negative metrics
spaces have unique characteristics and the game exhibits variety
At the end of the game, summarize the status variables concerning how the player did in the game
Technical requirements:
Comments, including extensive opening comments about progam
Uses parallel arrays
Uses strings
Uses char
Uses if/else
Choose appropriately from among cin, getline, and various related input options
Uses switch statement
Uses character checking from <cctype> (Chapter 10) to control  input
Uses manipulators from <iomanip> to control output (e.g., setw, setfill, setprecision, etc.)
Grading (up to 105% max.)
Meets requirements and specifications, all bullets above, 60%
Has consequential user interaction, +5% per space
Has more than four fully-functional gameboard spaces, +5% each
Reads arrays from a file, +15% (e.g., game descriptions can come from a file instead of being hard coded)
Array(s) are dynamically allocated (and deleted), +5% (not each)
Declare your own "max grade" score in the program's opening comments using the above rubric
*/