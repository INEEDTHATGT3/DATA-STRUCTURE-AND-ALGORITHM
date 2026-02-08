#include <iostream>
#include <climits>
using namespace std;

int main() {
    // 2D array declaration and initialization
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // any random element access
    cout << "Element at (1, 2): " << arr[1][2] << endl; // Accessing element at row 1, column 2

    //row-wise printing
    cout << "Row-wise printing:" << endl;
    // Note: This assumes the array is rectangular (3 rows, 4 columns)
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl; // New line after each row
    }

    // column-wise printing
    cout << "Column-wise printing:" << endl;
    // Note: This assumes the array is rectangular (3 rows, 4 columns)
    for (int j = 0; j < 4; j++) {
        for(int i = 0; i < 3; i++) {
            cout << arr[i][j] << " ";
        }
        cout << endl; // New line after each column
    }

    return 0;
}