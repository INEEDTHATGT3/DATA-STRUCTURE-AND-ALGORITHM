#include <iostream>
#include <vector>
using namespace std;

void findmissing(int *a, int n){
   /* //visited method
    for(int i = 0; i < n; i++){
        int index = abs(a[i]); // Get the index corresponding to the value
        if (a[index-1] > 0) {
            a[index-1] *= -1; // Mark the number as seen by making it negative
        }
    }

    for(int i = 0; i < n; i++){
        if (a[i] > 0) {
            cout << i + 1 << " "; // Print the missing number
    }
}*/

// sorting +swapping method
    int i = 0;
    while (i < n) {
        int index = a[i] - 1; // Get the index corresponding to the value
        if (a[i] != a[index]) {
            swap(a[i], a[index]); // Swap the current element with the element at its correct position
        } else {
            ++i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            cout << i + 1 << " "; // Print the missing number
        }
    }
}

int main() {
 int n;
 int a[] = {1, 2, 3, 3, 4};
 n = sizeof(a) / sizeof(a[0]);
 findmissing(a, n);
return 0;
}