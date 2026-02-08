#include <iostream>
using namespace std;

int main() {
  int a = 4;
  for(int i = 0; i < a; i++) {
    cout << "lipsha " << endl;
    break; // This will exit the loop after the first iteration

    for(int j = 0; j < 5; j++) {
      cout << "hello " << endl;
    }
  }
  cout << "so gyi" << endl;

  for (int i = 0; i < a; i++) {
    cout << "lipsha " << endl;
    continue; // This will skip the rest of the loop body and continue to the next iteration

    for(int j = 0; j < 5; j++) {
      cout << "hello " << endl;
    }
  }
    cout << "so gyi" << endl;

    // variable scoping
    // declaration
    int a;
    // initialization
    int b = 10;
    // updation
    a = 5; // This is an assignment, not a declaration or initialization
    b = b + 1; // This updates the value of b
    // once declared, donot declare again unless you are in a different scope

    // variable shadowing
    int x = 10; // Global variable
    {
        int x = 20; // Local variable, shadows the global variable
        cout << "Local x: " << x << endl; // Outputs 20
    }
    cout << "Global x: " << x << endl; // Outputs 10, the global variable is still accessible
    // int x = 20 is dead inside the block, it is not accessible outside the block
    // variable shadowing is not allowed in the same scope, it will give an error
    // avoid using global variables unless necessary, it can lead to confusion and bugs
    // use const for constants, it is a good practice to use const for constants

    switch (a) {
        case 1:
            cout << "Case 1" << endl;
            break;
        case 2:
            cout << "Case 2" << endl;
            break;
        default:
             cout << "Default case" << endl;
            break;
    }
}