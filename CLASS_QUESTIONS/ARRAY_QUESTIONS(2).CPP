#include<iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

int findunique(vector<int> arr) {
    int unique = 0;
    for(int i = 0; i < arr.size(); i++) {
        unique =unique ^ arr[i]; // XOR operation
    }
    return unique;
}

int main() {
    // finding unique elements in an array
    int n;
    cout << "Enter size of array: "<< endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements of array: " << endl;
    for(int i = 0; i < arr.size() ; i++) {
        cin >> arr[i];
    }

    int uniqueelement = findunique(arr);

    cout << "Unique element in the array is: " << uniqueelement << endl;

    // union of two arrays
    int arr[] = {1, 2, 3, 4, 5};
    int sizearr = 5;
    int arr2[] = {4, 5, 6, 7, 8};
    int sizearr2 = 5;

    vector<int> unionarr;

    //push elements of first array into unionarr
    for(int i = 0; i < sizearr; i++) {
        unionarr.push_back(arr[i]);
    }
    //push elements of second array into unionarr 
        for(int j = 0; j < unionarr.size(); j++) {
             unionarr.push_back(arr2[j]);
            }

    cout << "Union of two arrays is: ";
    for(int i = 0; i < unionarr.size(); i++) {
        cout << unionarr[i] << " ";
    }

    // intersection of two arrays
    vector<int> brr{1, 2, 3, 4, 5};
    vector<int> brr2{4, 5, 6};

    vector<int> intersectionbrr;

    for(int i = 0; i < brr.size(); i++) {
        int element = brr[i];
        // check if element is present in brr2
        for(int j = 0; j < brr2.size(); j++) {
            if(element == brr2[j]) {
                brr2[j] = INT_MIN; // mark as visited
                // to avoid duplicates in intersection
                }
                intersectionbrr.push_back(brr[i]);
            }
        }

    cout << "\nIntersection of two arrays is: ";
    for(auto value : intersectionbrr) {
        cout << value << " ";
    }

    //HOMEWORK; {UNION WITH DUPLICATES}

    // PAIR SUM
    vector<int> pairarr{1, 2, 3, 4, 5};
    int sum = 5;

    //printing all pairs of elements in the array
    //outer loop will traverse for each element
    for(int i = 0; i < pairarr.size(); i++) {
        int element = pairarr[i];
        
        //inner loop will traverse for each element after the outer loop element
        for(int j = i + 1; j < pairarr.size(); j++) {
            cout << "(" << pairarr[i] << ", " << pairarr[j] << ")" << endl;
            // for sum 
            if (element + pairarr[j] == 5) {
                cout << "Pair with sum 5 is: (" << element << ", " << pairarr[j] << ")" << endl;
            }
        }
    }

    //triplet sum
    vector<int> tripletarr{1, 2, 3, 4, 5};
    int tripletSum = 6;

    //printing all triplets of elements in the array
    for(int i = 0; i < tripletarr.size(); i++) {
        int element1= tripletarr[i];
        
        //inner loop will traverse for each element after the outer loop element
        for(int j = i + 1; j < tripletarr.size(); j++) {
            int element2 = tripletarr[j];
            for(int k = j + 1; k < tripletarr.size(); k++) {
                int element3 = tripletarr[k];
                cout << "(" << tripletarr[i] << ", " << tripletarr[j] << ", " << tripletarr[k] << ")" << endl;
                // for sum 
                if (element1 + element2 + element3 == tripletSum) {
                    cout << "Triplet with sum 6 is: (" << element1 << ", " << element2 << ", " << element3 << ")" << endl;
                }
            }
        }
    }

    //sort 0's & 1's
    vector<int> sortarr{0, 1, 0, 1, 0, 1, 0, 1};
    int start = 0;
    int end = sortarr.size() - 1;
    int i = 0;
    while(i <= end) {
        if(sortarr[i] == 0) {
            // swap from left to right
            swap(sortarr[i], sortarr[start]);
            start++;
            i++;
        } else {
            // swap from right to left
            swap(sortarr[i], sortarr[end]);
            end--;
        }
    }

    // printing sorted array
    for(auto value : sortarr) {
        cout << value << " ";
    }
    
    return 0;
}
