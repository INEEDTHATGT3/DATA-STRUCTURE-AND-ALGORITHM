#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void incrementArray(int arr[], int size) {
    arr[0] = arr[0] + 10; // Increment the first element of the array

    printArray(arr, size); // Print the array after incrementing
}

bool find(int arr[], int size, int key) {
    // linear search
    
    for(int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return true; // If the key is found, return true
            break;
        }
    }
    return false; // If the key is not found, return false
    // return false; // This line is redundant since the function will always return before reaching here
}

int main() {
    int arr[] = {5 , 6}; // Declare and initialize an array of integers
    int size = 2;
    incrementArray(arr, size); // Call the function to increment the first element of the array
    printArray(arr, 2); // Print the array after incrementing
    
    // Print the elements of the array
    for (int i = 0; i < 2; i++) {
        cout << "Element at index " << i << ": " << arr[i] << endl;
    }

    cout << arr << endl; // Print the address of the array
    cout << &arr[0] << endl; // Print the address of the first element of the array
    cout << &arr << endl; // Print the address of the array (same as above)
    
    // array intialization
    // static array initialization
    int brr[] = {1, 2, 3, 4, 5}; // Declare and initialize another array
    int crr[10] = {1, 2, 3, 4, 5}; // Declare and initialize another array with fixed size
    // error 
    // int drr[2] = {1, 2, 3, 4, 5}; // This will cause an error because the size is not sufficient for the initialization
    cout << brr[3] << endl; // Print the fourth element of brr
    cout << crr[7] << endl; // Print the eighth element of crr (which is uninitialized and may contain garbage value)
    
    int drr[5];
    cout << "enter input value for drr: "<< endl;
    for (int i = 0; i < 5; i++) {
        cin >> drr[i]; // Read values into the drr array
    }
    cout << "Elements of drr: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << 2 * drr[i] << " "; // Print the elements of drr
    }
    memset(drr, 0, sizeof(drr)); // Reset the drr array to zero
    for (int i = 0; i < 5; i++) {
        cout << drr[i] << " "; // Print the elements of drr after reset
    }

    cout << sizeof(drr) << endl; // Print the size of the drr array in bytes

    // linear search
    // Function to find a key in an array

    int err[5] = {1, 2, 3, 7, 8};
    int size = 5;
    cout << "enter the key to search: "<< endl;
    int key;
    cin >> key; // Read the key to search in the array

    if(find(err, size, key)) {
        cout << "Key found in the array." << endl; // If the key is found, print a message
    } else {
        cout << "Key not found in the array." << endl; // If the key is not found, print a message
    }

    // count 0's and 1's in an array
    int arr1[] = {0, 1, 0, 1, 0, 1, 0, 1};
    int size = 8;
    int count0 = 0, count1 = 0;

    for (int i = 0; i < size; i++) {
        if (arr1[i] == 0) {
            count0++; // Increment count0 if the element is 0
        } 
        if (arr1[i] == 1) {
            count1++; // Increment count1 if the element is 1
        }
    }
    cout << "Count of 0's: " << count0 << endl; // Print the count of 0's
    cout << "Count of 1's: " << count1 << endl; // Print the count of 1's
    // count 0's and 1's in an array using a single loop

    // maximum number in an array lly minimum number in an array
    int arr2[] = {177, 28, 309, 498, 57};
    int size2 = 5;
    int maxnum = INT_MIN; // Initialize maxNum to the smallest possible integer
    
    for(int i = 0; i < size2; i++) {
        if (arr2[i] > maxnum) {
            maxnum = arr2[i]; // Update maxNum if the current element is greater
        }
    }

    // extremes print in array
    int arr2[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    int size2 = 8;

    int start = 0; // Initialize start index
    int end = size2 - 1; // Initialize end index
    cout << "Array elements in extremes: ";
    while (start <= end) { // Loop until start index is less than or equal to end index
        if (start > end)
            break; // Exit the loop if start index exceeds end index{
        if (start == end) {
            cout << arr2[start] << " "; // Print the middle element if start equals end
        }
        else {
        cout << arr2[start] << " ";
        cout << arr2[end] << " "; 
        } 
        start++; // Move to the next element from the start
        end--; // Move to the previous element from the end 
        // but in odd case we will print the middle element only once
    }

    // reverse an array
    while(start <= end){
        swap(arr2[start], arr2[end]); // Swap the elements at start and end indices
        start++; // Move to the next element from the start
        end--; // Move to the previous element from the end 
    }

    return 0;
}