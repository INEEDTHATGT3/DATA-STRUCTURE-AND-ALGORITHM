#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void util(int* p){
    *p = *p+1 ; // this modifies local copy of p, not the original pointer
    cout << p << endl; // prints the address of next integer in memory
}

void solve(int** z){
    **z = **z + 1; // this modifies the original value of a 
    *z = *z + 1; // local z incremented not original also address of p is changed
    z = z + 1; // z changed only                                                                 
}

void passByRefrence(int& num){
    num ++;
}

void solve2(int* z){
    *z++;
}

int main(){
    int a = 5;
    int* p = &a;
    int** q = &p;

    cout << a << endl;
    util(p); // this will change value of a to 6
    cout << a << endl;

    solve(q); 

    cout << a << endl; // a = 6;
    passByRefrence(a); // a = 7;

    cout << a << endl; // a= 7;
    solve2(&a); // address of a is passed , a= 8;

    cout << &a << endl;
    cout << a << endl;
    cout << p << endl;
    cout << &p << endl;
    cout << *p << endl;
    cout << q << endl;
    cout << &q << endl;
    cout << *q << endl;
    cout << **q << endl;
}