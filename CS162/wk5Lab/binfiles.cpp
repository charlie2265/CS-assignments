/******************************************************************************

using binary files

*******************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const string FILEF = "C:\\Users\\critter\\OneDrive - Mt. Hood Community College\\MHCC\\Spring24\\CS162\\wk5Lab\\file.dat";


//open file for writing
// return true
bool openFile(ofstream&, string);
//write a string to file
void writeToFile(ofstream&, string);

int main()
{
    ofstream fout;


    bool result = openFile(fout, FILEF);

    if (result == true){
        writeToFile(fout, "Hello, world!");
    }
    else{
        cout << "Error! File failed to open!\n";
    }

    // pause the program
    cin.ignore();
    cin.get();
    

    return 0;
}

bool openFile(ofstream& fout, string fileName){

    fout.open(fileName);

    if(fout.is_open())
        return true;
    else    
        return false;
}

void writeToFile(ofstream& fout, string str)
{
    fout << str;
    fout.close();
}





// create, write to, and read from binary files passed through functions. 

    // void writeArray(int* a, int size){

    //     fstream fout(FILEF, ios::out | ios::binary);
    //     fout.write(reinterpret_cast<char*>(a), size * sizeof(int));
    //     fout.close();
    // }

    // void readArray(int* a, int size){
        
    //     fstream fout(FILEF, ios::in | ios::binary);
    //     fout.read(reinterpret_cast<char*>(a), size * sizeof(int));
    //     fout.close();

    // }
    // const int SIZE = 10;

    // int a[] = {1, 0, 2, 8, 6, 5, 0, 9, 7, 3};
    // int b[SIZE];

    // writeArray(a, SIZE);
    // readArray(b, SIZE);
    // for(int i : b)
    //         cout << i << " ";

    // Same as below with an array.
    // fstream fout;

    // fout.open(FILEF, ios::binary | ios::out);
    // if(fout){

    //     int a[] = {8, 6, 7, 5, 3, 0, 9,};
    //     // no & for the (a) argument. it is an array and is a pointer. so it is already pointing to the memory address. 
    //     fout.write(reinterpret_cast<char*>(a), sizeof(a));
    //     fout.close();
    // }
    // else
    //     cout << "Error!\n";

    // fout.open(FILEF, ios::binary | ios::in);

    // int b[7] = {};
    // fout.read(reinterpret_cast<char*>(b), sizeof(b));
    // fout.close();
    // for(int i : b)
    //     cout << i << " ";
    // cout << endl;



    //
    // exercise to open / create binary file read and write two variables an unsigned short and a char:

    // fstream fout;

    // unsigned short x = 8675;
    // char c = 'A';

    // fout.open(FILEF, ios::out | ios::binary);

    // if(fout){
    //     // write value of x to binary file, reinterpret type as char pointing to memory address of x, second parameter is 
    //     // the size of value of x data type. 
    //     fout.write(reinterpret_cast<char*>(&x), sizeof(unsigned short));
    //     // with a char type no cast needed still need to pass memory address as first parameter &c
    //     fout.write(&c, sizeof(char));
    //     fout.close();
    // }
    // else 
    //     cout << "error opening file \n";

    // fout.open(FILEF, ios::in | ios::binary);
    // if(fout){
    //     // unsigngend var 4 byte
    //     unsigned short y = 0;
    //     char f = 0;
    //     // read from binary file to unsigned short y; interperet as char type by pointing to memory address
    //     // of y. 
    //     fout.read(reinterpret_cast<char*>(&y), sizeof(unsigned short));
    //     // already a char type no casting.
    //     fout.read(&f, sizeof(char));
    //     fout.close();
    //     //proof
    //     cout << y << endl;
    //     cout << f << endl;
    // }