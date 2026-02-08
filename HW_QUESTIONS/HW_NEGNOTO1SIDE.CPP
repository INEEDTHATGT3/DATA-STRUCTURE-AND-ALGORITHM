#include <iostream>
using namespace std;

void moveallnegtooneside(int*a, int n){
    // dutch national flag problem
    int low = 0, high = n - 1;
    while(low<high){
        if(a[1] < 0){
            low++;
        } else if(a[high] >= 0){
            high--;
        } else {
            // swap elements
            int temp = a[low];
            a[low] = a[high];
            a[high] = temp;
        }
    }
}


int main() {
    int a[] = {1,2,-3,4,-5,6};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Array before moving negatives to one side: ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
   
    moveallnegtooneside(a, n);
    
    // Function to move all negative numbers to one side of the array
    cout << "Array after moving negatives to one side: ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }   
    cout << endl;

    // time complexity: O(n)
    // space complexity: O(1)
    return 0;
}