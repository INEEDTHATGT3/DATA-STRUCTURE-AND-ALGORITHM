#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
#include<limits.h>
#include<climits>
using namespace std;

class Solution {
public:

// normal recursion
    int solveUsingRec(int n){
         //bc
        if(n==0 || n == 1){
            return n;
        }

        //rec relation 
        int ans = solveUsingRec(n-1) + solveUsingRec(n-2);
        return ans;
    }

    //top-down approaach
    //rec + memoisatin approach
    int solveUsingMemo(int n, vector<int> &dp){
         //bc
        if(n==0 || n == 1){
            return n;
        }

        //step 3: if ans already exists
        if(dp[n] != -1){
            return dp[n];
        }

        //rec relation 
        //step 2: store and return using dp array
        dp[n] = solveUsingMemo(n-1, dp) + solveUsingMemo(n-2, dp);
        return dp[n];
    }


    //tabulation method
    // int solveUsingTabulation(int n){
    //     //step 1; create dp array
    //     vector<int> dp(n+1, -1);
    //     //step 2; analyse bc and fill dp array
    //     dp[0] = 0;
    //     if(n==0){
    //         return dp[0];
    //     }
    //     dp[1] = 1;

    //     //step 3 fill remaining dp array 
    //     //size = n+1
    //     //index-> 0 to n ; 0 & 1 already filled
    //     for(int i=2; i<=n; i++){
    //      dp[i] = dp[i-1] + dp[i-2];
    //     }
    //     return dp[n];
    // }

    //optimized space
    int solveUsingTabulation(int n){
        //step 1; create dp array
       // vector<int> dp(n+1, -1);
        //step 2; analyse bc and fill dp array
        int prev = 0;
        if(n==0){
            return 0;
        }
        int curr =1;

        //step 3 fill remaining dp array 
        //size = n+1
        //index-> 0 to n ; 0 & 1 already filled
        int ans;
        for(int index=2; index<=n; index++){
         ans = curr + prev;
         prev = curr;
         curr = ans;
        }
        return ans;
    }

    int fib(int n) {
        // BASE CASE
        //PROCESSING 
        //RECURSIVE RELATION

       //step 1; create dp array
     
       int ans = solveUsingTabulation(n);
       return ans;
    }

};