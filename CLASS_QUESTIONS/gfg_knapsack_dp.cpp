#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
using namespace std;

class Solution {
  public:
  
    int solveUsingRecursion(int W, vector<int> &wt, vector<int> &val, int index, int n){
        //base case
        if(index == n-1){
            if(wt[index] <= W){
                return val[index];
            }
            else{
                return 0;
            }
        }

        //inc / exc
        int include = 0;
        if(wt[index] <= W){
            include = val[index] + solveUsingRecursion(W-wt[index], wt, val, index+1, n);
        }
        int exclude = 0+ solveUsingRecursion(W, wt, val, index+1, n);
        int ans = max(include, exclude);
        return ans;
    }

    int solveUsingMem(int W, vector<int> &wt, vector<int> &val, int index, int n,vector<vector<int>> &dp ){
        //base case
        if(index == n-1){
            if(wt[index] <= W){
                return val[index];
            }
            else{
                return 0;
            }
        }

        if(dp[W][index] != -1){
            return dp[W][index];
        }

        //inc / exc
        int include = 0;
        if(wt[index] <= W){
            include = val[index] + solveUsingMem(W-wt[index], wt, val, index+1, n, dp);
        }
        int exclude = 0+ solveUsingMem(W, wt, val, index+1, n, dp);
        dp[W][index] = max(include, exclude);
        return dp[W][index];
    }

    int solveUsingTab(int W, int wt[], int val[], int n){
        vector<vector<int> > dp(W+1, vector<int>(n+1, -1));

        for(int row=0; row<=W; row++){
            dp[row][n] = 0;
        }

        for(int i=0; i<=W; i++){
            for(int j=n-1; j>=0; j++){
                int include = 0;
                if(wt[j] <= i){
                    include = val[j] + dp[i-wt[j]][j+1]; 
                }
                int exclude = 0+ dp[i][j+1];
                dp[i][j] = max(include, exclude);
            }
        }
        return dp[W][0];
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int index = 0;
        int n = val.size();

        vector<vector<int> > dp(W+1, vector<int> (n+1, -1));

        int ans = solveUsingMem(W, wt, val, index,n, dp);
        return ans;
    }
};