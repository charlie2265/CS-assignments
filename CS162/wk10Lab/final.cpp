#include<iomanip>
#include<iostream>
#include<cmath>
#include <string>
using namespace std;

void phraseIO(char arr[]);
void display(double num);
// function to display the value of tacos
// takes double num by value and returns nothing
void input(double& num);

int main (){
    char phrase[11];
    double tacos = 3.14159;


display(tacos);
phraseIO(phrase);
input(tacos);
    return 0;
            
            
    
}

void phraseIO(char arr[]){
    cout << "Enter Good Job!: ";
    // input the phrase to be stored in char phrase
    cin.getline(arr, 11);
    cout << "You entered: " << arr << endl;

    // count the number of lowercase letters in the phrase
    int count = 0;
    while (arr[0] != '0'){
        
        if (islower(arr[0])) 
            count++;
        arr++;
    }
    cout << "The number of lowercase letters in the phrase is: " << count << endl;
}