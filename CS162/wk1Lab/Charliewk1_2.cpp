/******************************************************************************
Charlie Ritter 

CS162 Priestley SP '24 
Week 1 Program 2
This program will generate an array of random integers and display them to the 
console.
It will then sort the array using the bubble sort algorithm and display the 
sorted array to the console.

Sources: textbook (Gaddis) Bubble Sort, page 476
*******************************************************************************/
#include <algorithm>
#include <iostream>
#include <random>       // Mersenne Twister
using namespace std;

const int 
        MAX_RANGE{100},     // Set constant to the desired maximum range
        QUANTITY {100};          // Specify how many random numbers to generate

int generateRandomInt(int max);
void displayArray(int arr[], int size);
void bubbleSort(int arr[], int size);

int main() {
    
    // declare an array to store random numbers
    int randomValue[QUANTITY];    

    displayArray(randomValue, QUANTITY);
    cout << "\nSorted!" << endl;
    bubbleSort(randomValue, QUANTITY);
    

    return 0;
}


// Function to generate a random integer in the range [0, max - 1]
// Accepts integer parameter to determine maximum value
// Returns an integer from 0 to max – 1, inclusive 
int generateRandomInt(int max) {
    static bool initialized {false};
    static mt19937 generator;  // Mersenne Twister

    // Initialize the random engine if not already done
    if (!initialized) {
        // Use a random device to seed the generator
        random_device rd;
        generator.seed(rd());
        initialized = true;
    }
        
    // Generate random number
    uniform_int_distribution<int> distribution(0, max - 1);

    return distribution(generator);
}
        





// function to generate random numbers and display them and store them in an array
// and display them. takes an array as an argument
void displayArray(int arr[], int size) {
    
    // Display header
    cout << "Random integer(s) between 0 and " << MAX_RANGE - 1 << ": " << endl;
    
    // Generate random numbers and echo to console
    for (int count = 0; count < QUANTITY; ++count) {
        // store random numbers in the array by calling the generateRandomInt function
        arr[count] = generateRandomInt(MAX_RANGE);
        cout << arr[count] << " ";
    }

    cout << endl;
}


// function to sort the array using bubble sort
// takes an array and its size as arguments
void bubbleSort(int arr[], int size) {
    
    // Bubble sort algorithm
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
        
    // Display sorted array
    for(int idx = 0; idx < size; idx++){
        cout << arr[idx] << " " << endl;
    }

}

                





/*
Submit a program that sorts an array using a method from Chapter 8
The program should begin by filling an array with 100 random integers using the program from Week 1Lab 2.
After that, it should display the array on the screen, one value per line.
Then it should sort the array using a function that employs ANY sorting method covered in chapter 8. 
For example, you can choose bubble sort, selection sort, or any sort in Chapter 8. Please include near the 
top of your program sources, cite the textbook, and mention a page number where the sort appears in the book.
You must fully document your program with comments, including the header comments stating the program purpose
and specifications. Then every variable declaration needs to identify the variable's purpose and how it will be 
populated. Functions have three lines: purpose, arguments, and significance of return value, plus additional 
lines is there are side effects (output, changing variables or state).
*/