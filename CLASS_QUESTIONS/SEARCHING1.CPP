#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
using namespace std;

int binarysearch(int arr[], int size, int target) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            start = mid + 1; // Search in the right half
        } else {
            end = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

int main() {
    vector<int> arr{2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target= 14;

    int brr[]= {3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    int size2 = sizeof(brr) / sizeof(brr[0]);

    //int indexOfTarget = binarysearch(arr, size, target);
    if (/* indexOfTarget != -1*/ binary_search(arr.begin(), arr.end(), 14) != -1) {
        cout << "Element found at index: " /* << indexOfTarget */<< endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    if (binary_search(brr,brr + size2, 15)) {
        cout << "Element found in brr." << endl;
    } else {
        cout << "Element not found in brr." << endl;
    }
}