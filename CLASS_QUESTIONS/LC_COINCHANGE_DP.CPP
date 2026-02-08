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

    int solveUsingRec(vector<int> &coins, int amount){
        //base case
        if(amount == 0){
            return 0;
        }

        //recursive relation
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            //find ans using ith coin
            //call recursion only for valid amounts ie >=0 wale amounts
            int recKaAns = 0;
            if(amount - coins[i] >= 0){
                recKaAns = solveUsingRec(coins, amount - coins[i]);
                //if a valid answer
                if(recKaAns != INT_MAX){
                    //considering usauge of ith coin
                    int ans = 1+ recKaAns;
                    mini = min(mini, ans);
                }
            }
        } 
        return mini;
    }

    int solveUsingMem(vector<int> &coins, int amount, vector<int> &dp){
        //base case
        if(amount == 0){
            return 0;
        }

        if(dp[amount] != -1){
            return dp[amount];
        }

        //recursive relation
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            //find ans using ith coin
            //call recursion only for valid amounts ie >=0 wale amounts
            int recKaAns = 0;
            if(amount - coins[i] >= 0){
                recKaAns = solveUsingMem(coins, amount - coins[i], dp);
                //if a valid answer
                if(recKaAns != INT_MAX){
                    //considering usauge of ith coin
                    int ans = 1+ recKaAns;
                    mini = min(mini, ans);
                }
            }
        } 
        dp[amount] = mini;
        return dp[amount];
    }

    int solveUsingTabulation(vector<int> &coins, int amount){
        //step 1
        int n = amount;
        vector<int> dp(n+1, INT_MAX);
        //step 2 base case analysis
        dp[0]= 0;
        //for loop
        for(int value = 1; value<= amount; value++){
            int mini = INT_MAX;
            for(int i=0; i<coins.size(); i++){
            //find ans using ith coin
            //call recursion only for valid amounts ie >=0 wale amounts
            if(value - coins[i] >= 0){
                int recKaAns = dp[value - coins[i]]; 
                //if a valid answer
                if(recKaAns != INT_MAX){
                    //considering usauge of ith coin
                    int ans = 1+ recKaAns;
                    mini = min(mini, ans);
                }
            }
        } 
        dp[value] = mini;
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        vector<int> dp(n+1, -1);
        int ans = solveUsingTabulation(coins, amount);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};