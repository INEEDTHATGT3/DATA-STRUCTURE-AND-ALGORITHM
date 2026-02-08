// CPPREFRENCE: https://en.cppreference.com/
// CPLUSPLUS: https://www.cplusplus.com/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    // create vector
    vector<int> arr;

    int ans = (sizeof(arr)/sizeof(int));
    cout << ans << endl; // size of vector in bytes

    cout << arr.size() << endl; // size of vector
    cout << arr.capacity() << endl; // capacity of vector

    //insert elements into vector
    arr.push_back(10);
    arr.push_back(20);

    //remove last element
    arr.pop_back();

    //print elements of vector
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    //ways to intialize a vector
    int n ;
    cout << "\nEnter the number of elements you want to add to the vector: ";
    cin >> n;

    vector<int> arr2(n ,-101); // create vector of size 5 with all elements initialized to 100
    cout << "Size of arr2: " << arr2.size() << endl;
    cout << "Capacity of arr2: " << arr2.capacity() << endl;
    

    vector<int> arr3{1, 2, 3, 4, 5}; // create vector with elements

    for(int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }

    cout << "vector arr3 is empty: " << arr3.empty() << endl; // check if vector is empty
    
}