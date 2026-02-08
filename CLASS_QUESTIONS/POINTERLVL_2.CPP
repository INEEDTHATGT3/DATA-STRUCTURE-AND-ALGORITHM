#include <iostream>
#include <vector>
using namespace std;

void solve(int arr[]){
    cout << "size inside solve function: " << sizeof(arr) << endl; // size of pointer in bytes
    cout << "arr: "<< arr << endl; // address of the first element
    cout << "&arr: " << &arr << endl; // address of the pointer
    arr[0] = 10;
}

int main(){
    int arr[10] = {1, 2, 4, 5};
    cout << "size inside main function: " << sizeof(arr) << endl; // size of array in bytes
    cout << arr << endl;
    cout << &arr << endl;
    int *p = arr; // pointer to first element of the array
    // arr = arr + 2; // because we are trying to change value in symbol table
    p = p + 2; 

    cout << p << endl; // address of the first element
    cout << arr << endl;
    cout << &arr << endl;
    cout << &arr[0] << endl;

    cout << arr[0] << endl; //value of first element
    cout << *p << endl;
    cout << *arr << endl;

    cout << *(arr + 1)<< endl; // value of second element
    cout << *(p + 1) << endl;
    cout << arr[1] << endl;
    cout << *(arr)+ 1 << endl;
    cout << *arr + 1 << endl;

    cout << &p << endl; // address of the pointer p

    char ch[10] = "hello";
    char *c = ch; // pointer to first element of character array

    cout << c << endl; // prints string "hello"
    cout << &c << endl; // address of pointer c
    cout << *c << endl; // prints first character "h"
    
    cout << ch << endl; // hello
    cout << &ch << endl; // address of character array
    cout << ch[0] << endl; // h
    cout << *ch << endl; // h
    cout << ch+3 << endl; // prints "lo" (address of 4th character)

    // char ch = 'k';
    // char *c1 = &ch; 
    // cout << c1 << endl; //k + garbage value

    char *c1 = "hello";
    cout << c1 << endl; // hello

    // printing array inside main
    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }cout << endl;
    cout << endl << endl << "now calling solve function" << endl;

    solve(arr); 
    cout << "wapas main function mai aagye h" << endl;
}