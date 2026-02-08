#include<iostream>
#include<cmath>
using namespace std;

int slowExponentiation(int a,int b){
    int ans = 1;
    for(int i=0; i<b; i++){
        ans *= a;
    }
    return ans;
} // o(b) time complexity

int fastExponentiation(int a, int b){
    int ans =1;
    while(b > 0){
        if(b & 1){
            //odd power
            ans *= a;
        }
        a *= a; // square the base
        b >>= 1; // divide the power by 2
    }
    return ans;
} // o(log b) time complexity