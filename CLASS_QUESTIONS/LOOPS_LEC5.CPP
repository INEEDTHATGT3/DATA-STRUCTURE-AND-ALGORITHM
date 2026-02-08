#include <iostream>
using namespace std;

int main() {
    for(int i=5; i>0; i=i-1){
        cout << i << endl;
    }

    // multiplication table of 2
    for(int i=1; i<=10; i++){
        cout << "2 * " << i << " = " << 2*i << endl;
    }

    // another practice problem
    for(int i=5; (i>=0 && i<=10); i=i+1){
        cout << i << endl;
    }

    // are all three conditons mandatory?
    int i = 0;
    for(; ;){
        if(i<5)
        {
            cout << i << endl;
            i++;
        }
    }
}
