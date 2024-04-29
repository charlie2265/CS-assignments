/******************************************************************************
Charlie Ritter 

CS162 Priestley SP '24 
Week 1 Program 1

This program will generate a file with prime numbers from 2 - 1000 (1 is not a
prime) and display them to the console.
isPrime() will take a file and an integer as arguments and return true if the
number is prime.
displayFile() will take a file as an argument and display the contents to the
console.


Sources: textbook (Gaddis) cs161wk5prime.cpp by Charlie Ritter
*******************************************************************************/
#include <cmath>
#include <fstream> 
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath> // for math functions like sqrt()
using namespace std;

const string PRIME = "primeNum.txt";                               
const int MAXVAL = 1000; // Max value to check to.

//Prototypes 
bool isPrime(string file, int val);
void displayFile(string file);

int main()
{

isPrime(PRIME, MAXVAL);
displayFile(PRIME);

    
    return 0;

}


// function to create a file with the prime numbers from 2 -1000
// takes the file and the upper limit constant as arguments
// to return true when prime evaluates to true
bool isPrime(string file, int val){
    bool isprime {};  // Set boolean

int 
    checknum = {},
    counter = {}, // count rows
    root = {} ;  // store sqrt()
    
ofstream outputfile;  //Declare output stream variable
ifstream infile;      //Declare input stream variable

outputfile.open(PRIME);  //create output file using string constant.

// Loop min through max setting is prime to true and store the sqrt() in root.
cout << "Welcome to The Prime Number Generator! \n";
for (int num = 2; num <= MAXVAL; ++num ){
    isprime = true;
    root = sqrt(num);

   //when conditions from parent loop evaluate true; isprime and pnum is less than or equal to sqrt of num.  
    for( int pnum = 2; isprime && pnum <= root; ++pnum) //pnum checks factors
        if (num % pnum == 0)
            isprime = false;

            // when is prime evaluates to true write to file
            if(isprime) 
            {
                //write to file with formatting
                outputfile << setw(4) << num << " ";
                counter ++;

                if(counter % 10 == 0)
                outputfile << endl;

        }
}

// a message with the file name, and how many prime numbers were written to it. 
    cout << "A file with "<<  counter << " prime numbers has been created in: \n" << PRIME<< endl;

    // close the file.
    outputfile.close();

    return isprime;

}

// Function to execute file to output contents to console
// Takes the file as an argument with no return value. 
void displayFile(string file){

// variable to store each line as a string
string read;
    // open file with primes in it
    ifstream ifile(file);

    // check if file is open and use getline to put each line in the variable. 
    if(ifile.is_open()){
        while (getline(ifile, read)){
            //display to console.
            cout << read << endl;
        }
        ifile.close();
    } else 
        cout << "Error opening file." << endl;
}


