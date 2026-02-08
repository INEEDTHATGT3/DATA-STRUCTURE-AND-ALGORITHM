#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

int main(){
    int a = 5;
    cout << "address of a: " << &a << endl; //prints address of a
    int *ptr = &a; // ptr is a pointer to a of type int
    cout << *ptr << endl; // prints value of a using pointer
    cout << "address of ptr: " << &ptr << endl; // prints address of ptr
    cout << "value of ptr: " << ptr << endl; // prints address of a using pointer
    cout << "value at address of ptr: " << *(&ptr) << endl; // prints value at address of ptr (address of a)
    
    char ch = 'b';
    char* c = &ch; // c is a pointer to ch of type char
    double dtr = 3.14;
    double* d = &dtr; // d is a pointer to dtr of type double

    cout << sizeof(ptr) << endl; // prints size of ptr (int*)
    cout << sizeof(c) << endl; // prints size of c (char*)
    cout << sizeof(d) << endl; // prints size of d (double*)

    // bad practice
    int* ptr2;
    cout << *ptr2 << endl; // segmentation fault, ptr2 is uninitialized
    cout << ptr2 << endl; // this will also cause a segmentation fault if ptr2 is dereferenced 
    int *ptr3 = nullptr; // ptr3 is a null pointer, it points to nothing

    // pointer copy
    int *ptr4 = ptr; // ptr4 is a copy of ptr, both point to same address
}