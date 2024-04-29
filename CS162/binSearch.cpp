// Exercise: Implement a function that performs a linear search on an array.

#include <iostream>
#include <vector>

// Function prototype
int linearSearch(const std::vector<int>& arr, int target);

int main() {
    // Test case 1:
    std::vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target1 = 5;
    // Expected output: 4
    std::cout << "Index of " << target1 << " in arr1: " << linearSearch(arr1, target1) << std::endl;

    // Test case 2:
    std::vector<int> arr2 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target2 = 25;
    // Expected output: -1
    std::cout << "Index of " << target2 << " in arr2: " << linearSearch(arr2, target2) << std::endl;

    return 0;
}

// Function definition
int linearSearch(const std::vector<int>& arr, int target) {
    // Your code here
}
