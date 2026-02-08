#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int factorial(int n){
     cout << "function is called for n: " << n << endl;
    // base case
    if(n == 1)
        return 1;

    int ans = n * factorial(n-1);
    return ans; 
}

void printCounting(int n){
    //base case (mandotroy but sometimes possible without it)
    if(n == 0){
        return;
    }

    //processing
    cout << n << " ";
    
    //recursive relation (did reverse printing but if processing written below this it will print counting)
    printCounting(n-1);
}

int fib(int n){
    // base case
    if(n == 1){
        // first term
        return 0;
    }
    if(n == 2){
        // second term
        return 1;
    }

    //RR -> f(n) = f(n-1) + f(n-2)
    int ans = fib(n-1) + fib(n-2);
    return ans;
}

int main(){
    int n;
    cout << "enter value of n: " << endl;
    cin >> n;

    int ans = factorial(n);
    printCounting(n);
    int ans2 = fib(n);

    cout << "answer is: " << ans << endl;
    cout << n << "th tem is: " << ans2 << endl;

    return 0;
}