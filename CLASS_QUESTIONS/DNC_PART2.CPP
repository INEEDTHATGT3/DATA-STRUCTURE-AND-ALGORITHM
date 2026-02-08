#include<iostream>
#include<algorithm>
using namespace std;

int partition(int arr[], int s, int e){
    //step 1: choose pivotelement
    int pivotIndex = s;
    int pivotElement = arr[s];

    //step 2: find right position for pivot element and place it there
    int count = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pivotElement){
            count++;
        }
    }

    //jab main loop se bahar hua, toh mere pass pivot ki right position ka index ready hai
    int rightIndex = s + count;
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex = rightIndex;
    
    //step 3: left me chote and right me bade
    int i = s;
    int j = e;

    while( i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivotElement){
            i++;
        }
        while (arr [j] > pivotElement){
            j--;
        }

        //2 cases -> A -> we found element to swap, B -> no need to swap
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    //base case
    if(s >= e){
        return;
    }
    // partition logic, return pivotIndex
    int p = partition(arr, s, e);

    //recursive calls
    //pivot element -> left
    quickSort(arr, s, p-1);

    //pivot element -> right
    quickSort(arr, p+1, e);
}

void printPermutation(string& str, int i){
    //base case
    if(i >= str.length()){
        cout << str << " ";
        return;
    }

    //swapping 
    for(int j=i; j<str.length(); j++){
        //swap
        swap(str[i], str[j]);
        //rec call
        printPermutation(str , i+1);
        // backtracking - to recreate previous state
        swap(str[i], str[j]);
    }
}

int main(){
    int arr[]= {8,1,3,4,20,50,30,30};
    int n = sizeof(arr)/sizeof(arr[0]);

    int s = 0;
    int e = n-1;
    quickSort(arr, s, e);
     
    for(int i =0; i<n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    // permutation question 
    string str = "abc";
    int i = 0;
    printPermutation(str,i);

    return 0;
}