#include<fstream>
#include<iostream>
#include<string>

using namespace std;


const string FILENAME = "C:\\Users\\critter\\OneDrive - Mt. Hood Community College\\MHCC\\Spring24\\CS162\\wk2Lab\\data.txt";  //"data.txt"; 
            
const int 
    COLS = 18,
    DATES = 15,
    SOURCES = 18;

struct WeatherData{
    string header[COLS];
    string forcast[SOURCES][DATES][COLS];
    
};

// Function prototypes
WeatherData fromFile (string FILENAME,WeatherData &Data);
WeatherData sourceSelect(WeatherData &Data);


int main()
{
WeatherData weather;

cout << "Welcome to the WeatherPUD \n" << endl;

fromFile(FILENAME, weather);
sourceSelect(weather);


    return 0;
}
    
WeatherData fromFile(string FILENAME, WeatherData &Data){
    string Dispose;
    int count = 0;
    ifstream file(FILENAME);

    //check if file opened successfully
    if(!file){
        cerr << "File not found " << FILENAME << endl;
        exit(1);
    }

    // First row into header array. 
    for(int idx = 0; idx < COLS; ++idx){
        if(idx != COLS - 1)
            getline(file, Data.header[idx], ',') >> ws;
        else
            getline(file, Data.header[idx], '\n');
    }

    // cout header array
    for(int dsp = 0; dsp < COLS; ++dsp){
        // Display header
        // cout << dsp << ":[" << Data.header[dsp] << "]";
    }
    // cout << endl;

    // File contents into 3d array. nested for loops for each dimension - sources(18) sets of dates(15) rows with cols(18) elements*
    for (int i = 0; i < SOURCES; ++i) {
        for (int j = 0; j < DATES; ++j) {
            // number rows
            // cout << ++count;
            for (int k = 0; k < COLS; ++k) {
                if (k != COLS - 1)
                    getline(file, Data.forcast[i][j][k], ',') >> ws;
                else {
                    getline(file, Data.forcast[i][j][k], '\n'); // Use if necessary; otherwise '\n'
                }
                // display forcast array
                // cout << ": "<< "[" << Data.forcast[i][j][k] << "]" << " ";
            }
            // cout << endl;
        }
    }

return Data;
    
}
    
WeatherData sourceSelect(WeatherData &Data){
    int count = 0;

    cout << Data.header[17] << endl;

    for (int i = 0; i < SOURCES; ++i) {
        cout << count++;
        for (int j = 0; j < DATES; ++j) {
            if (j % 3 == 0 && j != 0) {
                cout << endl;
            }
            cout << " [" << Data.forcast[i][j][17] << "]";
        }
        cout << endl;
    }

    return Data;
}
    
    
    
    /* USEFUL CODE FOR STUFF

    // really close to final output
    for (int i = 0; i < SOURCES; ++i) {
        for (int j = 0; j < DATES; ++j) {
            
            for (int k = 0; k < COLS; ++k) {
                
                cout << k << ": " << Data.forcast[i][j][k] << " " << endl;
            }
            cout << endl;
        }
    }


    //display entire file
    for (int dsp = 0; dsp < rows; ++dsp){
        fileDisp = dsp;
        getline(file, fileDisp);
        cout << fileDisp << endl;
    }
    
    */
    