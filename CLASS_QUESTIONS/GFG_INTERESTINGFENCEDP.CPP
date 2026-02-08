#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
using namespace std;

class Solution {
  public:
  int solveUsingRecursion(int n, int k){
    //base case
    if(n == 1){
        return k;
    }
    if(n == 2){
        return (k+ k*(k-1));
    }

    int ans = (solveUsingRecursion(n-1, k) + solveUsingRecursion(n-2,k))*(k-1);
    return ans;
    }

    int solveUsingMem(int n, int k, vector<int> &dp){
    //base case
    if(n == 1){
        return k;
    }
    if(n == 2){
        return (k+ k*(k-1));
    }

    //a;ready exist
    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = (solveUsingMem(n-1, k, dp) + solveUsingMem(n-2,k, dp))*(k-1);
    return dp[n];
    }

    int solveUsingTab(int n, int k){
        vector<int> dp(n+1, -1);
        dp[1] = k;
        dp[2] = k + k*(k-1);

        for(int i=3; i<=n; i++){
            dp[n] = (dp[n-1] + dp[n-2])*(k-1);
        }
        return dp[n];
    }

    int solveUsingTabSO(int n, int k){
        vector<int> dp(n+1, -1);
        int prev2 = k;
        int prev1 = k+k*(k-1);
        int curr;

        for(int i=3; i<=n; i++){
            curr = (prev1 + prev2)*(k-1);
            //shift
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }

    int countWays(int n, int k) {
        // code here
        vector<int> dp(n+1, -1);
        int ans = solveUsingTabSO(n,k);
        return ans;
    }
};