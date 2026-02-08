#include <iostream>
#include <vector>
#include <climits>                                                               
using namespace std;

void transpose(int arr[][3], int rows, int cols) {
    cout << "Transposed 2D Array: " << endl;
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++) {
            cout << arr[j][i] << " "; // Print transposed element
        }
        cout << endl; // New line after each row
    }
}

void print2DArray(int arr[][3], int rows, int cols) {
    cout << "2D Array: " << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << arr[i][j] << " "; // Print each element
        }
        cout << endl; // New line after each row
    }
}

int getmin(int arr[][3], int rows, int cols) {
    int minElement = INT_MAX; // Initialize to the smallest possible integer
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(arr[i][j] < minElement) {
                minElement = arr[i][j]; // Update maxElement if a larger element is found
            }
        }
    }
    return minElement; // Return the maximum element found
}

int getmax(int arr[][3], int rows, int cols) {
    int maxElement = INT_MIN; // Initialize to the smallest possible integer
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(arr[i][j] > maxElement) {
                maxElement = arr[i][j]; // Update maxElement if a larger element is found
            }
        }
    }
    return maxElement; // Return the maximum element found
}

bool Findkey(int arr[][3], int rows, int cols, int key) {   
    for(int i = 0; i < rows; i++) {                                         
        for(int j = 0; j < cols; j++) { 
            if(arr[i][j] == key) {
                cout << "Element " << key << " found at position (" << i << ", " << j << ")" << endl;
                return true; // Return true if the key is found
            }
        }
    }
    return false; // Return false if the key is not found
}

void printRowSum(int arr[][3], int rows, int cols) {
    cout << "Row sums: " << endl;
    for(int i = 0; i < rows; i++) {
        int sum = 0;
        for(int j = 0; j < cols; j++) {
            sum =sum + arr[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << sum << endl;
    }
}

int main() {
    // row sum printing
    int arr[3][3];
    int rows = 3, cols = 3;

    //inputting elements in the 2D array
    cout << "Enter elements of 2D array: " << endl; 
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }
    // printing row wise
    cout << "Enter elements of 2D array: " << endl; 
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl; // New line after each row
    }

    printRowSum(arr, rows, cols);

    // finding key in 2D array
    int key;
    cout << "Enter key to find in 2D array: ";  
    cin >> key;
    cout << Findkey(arr,3,3, key);

    // finding max element in 2D array
    cout << "Maximum element in the 2D array is: " << getmax(arr, rows, cols) << endl;
    // finding min element in 2D array
    cout << "Minimum element in the 2D array is: " << getmin(arr, rows, cols) << endl;

    //using vector of vectors to create a 2D array
    vector<vector<int>> vec2D = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "2D Array using vector of vectors: " << endl;
    for(const auto& row : vec2D) {
        for(int elem : row) {
            cout << elem << " ";
        }
        cout << endl; // New line after each row
    }

    //other intialization methods
    vector<vector<int> > arr2;
    vector<int> a{1, 2, 3}; // vector with elements
    vector<int> b{2, 3, 9}; // vector of size 5 with all elements initialized to -101 
    vector<int> c{1, 3 , 7};
    
    arr2.push_back(a); // push vector a into arr2
    arr2.push_back(b); // push vector b into arr2 
    arr2.push_back(c); // push vector c into arr2

    cout << "2D Array using vector of vectors with push_back: " << endl;
    for(int i = 0; i<arr2.size(); i++) {
        for(int j = 0; j < arr2[0].size(); j++) {
            cout << arr2[i][j] << " "; // Print each element
        }
        cout << endl; // New line after each row
    }
}