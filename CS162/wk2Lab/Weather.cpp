#include <fstream>
#include <iostream>
#include <string>
using namespace std;
const string FILENAME = "C:\\Users\\critter\\OneDrive - Mt. Hood Community College\\MHCC\\Spring24\\CS162\\wk2Lab\\data.txt";  //"data.txt";             ;
const int
        MAX = 271,
        FIELDS = 18,
        Q_SOURCES = 18,
        Q_DATES = 15;


string fromFile(string Filename, string header[], string arr[270][18], int FIELDS,int MAX);
string sourceSelect(string arr[270][18]);
string dateSelect(string arr[270][18]);
string getWeather(string header[], string arr[270][18]);

int main() {
//  Create a 2D array to store the rows containing the selected weather source.
string 
    weather[MAX][18] = {},
    header[FIELDS];

fromFile(FILENAME, header, weather, FIELDS, MAX);
sourceSelect(weather);
for(int idx = 0; idx < MAX; idx++){
    for(int jdx = 0; jdx < FIELDS; jdx++)
    cout << weather[idx][FIELDS];
}



        return 0;
    
    }

    
string fromFile(string Filename, string header[], string arr[270][18], int FIELDS, int MAX){

    string dummy;
    string welcome = "Welcome to WeatherPUD, where you get the weather you want, the way you want it.\n\n";
    ifstream infile(FILENAME);

    // put first row of data into header array
    for (int idx = 0; idx < FIELDS; ++idx){
        getline(infile, header[idx], ',');
    // display the header
    }
        // cout << header[18];

    
    // put the rest of the data into the 2d array
    for (int idx = 0; idx < MAX; ++idx) {

        for (int col = 0; col < FIELDS; ++col){
            getline(infile, arr[idx][col], ',');
        }
    }
cout << welcome;
        // cout << arr[idx][18];

    return welcome;
}


string sourceSelect(string arr[270][18]){
    string source;

    // display menu of sources
    cout << "Select a weather source\n";
    cout << "0) AccuWeather       1) BBC Weather             2) Climatic Research Unit (CRU) \n";
    cout << "3) KATU              4) KEX                     5) KGW\n";
    cout << "6) KOIN              7) KOPB                    8) KBPS\n";
    cout << "9) KPTV              10) KXL                    11) National Weather Service\n";
    cout << "12) NPR              13) The Weather Channel    14) Weather Underground\n";
    cout << "15) Weather.com      16) Weather.gov            17) WeatherWizard\n";

    // cin >> source;

    // for (int i = 0; i < 270; i += 15){
    //     for (int j = 0; j < 18; j++)
    //         cout << arr[i][18];
        
    // }

    
    
    
    

    return source;
}







// string heading[Q_FIELDS];
    // string data[Q_SOURCES * Q_DATES][FIELS];
    
    // // getline(data[idx][col], ',');
//  Repeat steps 4-6 until all rows have been processed.
//  Close the data file.
//  Perform any further operations on the 2D array as needed.


/*
Welcome user
prompt for weather source
0) AccuWeather       1) BBC Weather             2) Climatic Research Unit (CRU) 
3) KATU              4) KEX                     5) KGW
6) KOIN              7) KOPB                    8) KBPS
9) KPTV              10) KXL                    11) National Weather Service
12) NPR              13) The Weather Channel    14) Weather Underground
15) Weather.com      16) Weather.gov            17) WeatherWizard

each source has 15 days of weather reports. sorted in ascending order by date in the data file. 

based on selection, put all rows containing the selection value in the source column, in a 2d array. 



*/



