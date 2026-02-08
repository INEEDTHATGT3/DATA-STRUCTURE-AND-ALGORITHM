#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
using namespace std;

class Solution {
public:

    int solveusingRecursion(string text1, string text2, int i, int j){
        //basecase
        if(i>=text1.length()){
            return 0;
        }
        if(j >= text2.length()){
            return 0;
        }

        //recursive call
        int ans=0;
        if(text1[i] == text2[j]){
            ans = 1+ solveusingRecursion(text1, text2, i+1, j+1);
        }
        else{
            ans=0+max(solveusingRecursion(text1, text2, i, j+1), solveusingRecursion(text1, text2, i+1, j));
        }
        return ans;
    }

    int solveusingMem(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){
        //basecase
        if(i>=text1.length()){
            return 0;
        }
        if(j >= text2.length()){
            return 0;
        }

        //check if ans already exists
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        //recursive call
        int ans=0;
        if(text1[i] == text2[j]){
            ans = 1+ solveusingMem(text1, text2, i+1, j+1, dp);
        }
        else{
            ans=0+max(solveusingMem(text1, text2, i, j+1, dp), solveusingMem(text1, text2, i+1, j,dp));
        }
        return ans;
    }

    int solveUsingTab(string &text1, string &text2){
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1,0));

        for(int i_index=text1.length()-1; i_index>=0; i_index--){
            for(int j_index=text2.length()-1; j_index>=0; j_index--){
                int ans=0;
                if(text1[i_index] == text2[j_index]){
                    ans = 1+dp[i_index+1][j_index+1];
                }
                else{
                    ans = 0+max(dp[i_index][j_index+1], dp[i_index+1][j_index]);
                }
            }
        }
        return dp[0][0];
    }

    int solveUsingTabSO(string &text1, string &text2){
        vector<int> curr(text1.length()+1,0);
        vector<int> next(text1.length()+1,0);

        for(int j_index=text2.length()-1; j_index>=0; j_index--){
        for(int i_index=text1.length()-1; i_index>=0; i_index--)
            {
                int ans=0;
                if(text1[i_index] == text2[j_index]){
                    ans = 1+next[i_index+1];
                }
                else{
                    ans = 0+max(next[i_index], curr[i_index+1]);
                }
                curr[i_index]= ans;
            }
            //shifting
            next = curr;
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1,-1));
        int ans= solveUsingTabSO(text1, text2);
        return ans;
    }
};