// Exercise: Implement a function that performs a linear search on an array.

#include <iostream>
#include <vector>

using namespace std;

// Function prototype
int linearSearch(const std::vector<int>& arr, int target);

int main() {
    // Test case 1:
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target1 = 5;
    // Expected output: 4
    cout << "Index of " << target1 << " in arr1: " << linearSearch(arr1, target1) << std::endl;

    // Test case 2:
    vector<int> arr2 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target2 = 25;
    // Expected output: -1
    cout << "Index of " << target2 << " in arr2: " << linearSearch(arr2, target2) << std::endl;

    return 0;
}

// Function definition
int linearSearch(const vector<int>& arr, int target) {
    int index = 0;
    int n = arr.size();
    bool found = false;

    for (int i = 0; i < n; i++){
        if(arr[i] == x)
        re
    }

}





















// #include <algorithm>
// #include <iomanip>
// #include <iostream>
// #include <string>

// using namespace std;
// const int SIZE = 5;

// //prototype
// int linSearch(int arr[], int size, int value);

// int main()
// {
//     int score[SIZE] = {87, 75, 98, 100, 82};
//     int results;

//     results = linSearch(score, SIZE, 100);
//     // If linSearch returns -1 the value was not found
//     if (results == -1){
//         cout << "Not found" << endl;
//     }

//     else
//     {
//         cout << "Here it is" << (results + 1) << endl;
//     }   



//     return 0;
// }

// int linSearch(int arr[], int size, int value){
//     int index = 0;      // Uses as subscript to search array
//     int positiion = -1; // To record position of search value
//     bool flag = false; // Flag to indicate if value is found

//     while (index < size && ! flag){
//         // If value is found
//         if (arr[index] == value){
//             flag = true;
//             positiion = index;
//         }
//         index++;

//         return positiion;        

//     }



// }