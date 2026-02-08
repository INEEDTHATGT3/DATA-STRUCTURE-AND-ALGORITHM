#include <iostream>
using namespace std;

int main() {
    int a = 12;
    a = a << 1;
    cout << "Left Shift: " << a << endl; // 24
    // -1 se krne garbage value aaega

    int b = 11;
    b = b >> 1;
    cout << "Right Shift: " << b << endl; // 5
    // -1 se krne garbage value aaega

    int c= 33;
    cout << "Post Increment: " << c++ << endl; // 33
    cout << "After Post Increment: " << c << endl; // 34

    int d = 44;
    cout << "Pre Increment: " << ++d << endl; // 45
    cout << "After Pre Increment: " << d << endl; // 45
    
    // similarly for decrement

    int e = 55;
    int h = ++e + 1;
    cout << "Pre Increment with addition: " << h << endl; // 57
    int f = 66; 
    int g = f++ + 1;
    cout << "Post Increment with addition: " << g << endl; // 67

    int i = 5;
    cout << (++i)*(++i) << endl; // 56
    // Here, both pre-increments are evaluated before multiplication, resulting in 7 * 8 = 56
}