#include <iostream>
using namespace std;

int main(){
    bool a = true;
    bool b = false; 

    cout << "Boolean Operations:" << endl;
    cout << (~a) << endl; // Logical NOT
    cout << (a & b) << endl ; // Logical AND
    cout << (a | b) << endl ; // Logical OR
    cout << (a ^ b) << endl ; // Logical XOR
    cout << (!a) << endl ; // Logical NOT
    cout << (a && b) << endl; // Short-circuit AND
    cout << (a || b) << endl; // Short-circuit OR
    cout << (a == b) << endl; // Equality
    cout << (a != b) << endl; // Inequality

}