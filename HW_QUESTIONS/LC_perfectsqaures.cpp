#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

class Solution {
public:
    int numSquareHelper(int n){
         //base case
        if(n == 0) return 1;
        
        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        while(i <= end){
            int perfectSquare = i*i;
            int numberofPerfectSquares = 1 + numSquareHelper(n - perfectSquare);
            if(numberofPerfectSquares < ans){
                ans = numberofPerfectSquares;
            }
            ++i;
        }
        return ans;
    }

    int numSquares(int n) {
        return numSquareHelper(n) - 1;
       
    }
};