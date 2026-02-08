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
    int solveUsingRecursion(string &word1, string &word2, int i, int j){
        // base case
        if(i==word1.length()){
            return word2.length()-j;
        }
        if(j==word2.length()){
            return word1.length()-i;
        }

        int ans =0;
        if(word1[i] == word2[j]){
            ans = 0+ solveUsingRecursion(word1,word2,i+1,j+1);
        }
        else{
            int replace = 1+ solveUsingRecursion(word1, word2, i+1, j+1);
            int insert = 1+ solveUsingRecursion(word1, word2, i,j+1);
            int remove = 1+solveUsingRecursion(word1, word2, i+1,j);
            ans = min(insert, min(remove,replace));
        }
        return ans;
    }

    int solveUsingMem(string &word1, string &word2, int i, int j, vector<vector<int>> &dp){

        // base case
        if(i==word1.length()){
            return word2.length()-j;
        }
        if(j==word2.length()){
            return word1.length()-i;
        }

        int ans =0;
        if(word1[i] == word2[j]){
            ans = 0+ solveUsingMem(word1,word2,i+1,j+1, dp);
        }
        else{
            int replace = 1+ solveUsingMem(word1, word2, i+1, j+1,dp);
            int insert = 1+ solveUsingMem(word1, word2, i,j+1,dp);
            int remove = 1+solveUsingMem(word1, word2, i+1,j,dp);
            ans = min(insert, min(remove,replace));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveUsingTab(string &word1, string &word2){
       vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, -1)); 

       //base case amalysis -> ans insertion
       for(int col=2; col<word2.length(); col++){
        dp[word1.length()][col] = word2.length()-col;
       }
       for(int row=0; row<=word1.length(); row++){
        dp[row][word2.length()] = word1.length()-row;
       }

       for(int i_index=word1.length()-1; i_index >= 0; i_index--){
        for(int j_index=word2.length()-1; j_index>=0; j_index--){
            int ans = 0;
            if(word1[i_index] == word2[j_index]){
                ans=0+dp[i_index+1][j_index+1];
            }
            else{
                int replace = 1+ dp[i_index+1][j_index+1];
                int insert = 1+dp[i_index][j_index+1];
                int remove = 1+dp[i_index+1][j_index];
                ans = min(insert,min(remove,replace));
            }
            dp[i_index][j_index] = ans;
        }
       }
       return dp[0][0];
    }

    int solveUsingTabSO(string &word1, string &word2){
       //vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, -1)); 
        vector<int> curr(word1.length()+1, 0);
        vector<int> next(word1.length()+1,0);

       //base case amalysis -> ans insertion

       //for(int col=2; col<=word2.length(); col++){
        //dp[word1.length()][col] = word2.length()-col;
       //}
       for(int row=0; row<=word1.length(); row++){
        next[row]= word1.length()-row;
       }

        for(int j_index=word2.length()-1; j_index>=0; j_index--){
            //hr naye column k last dabbe me ans insert karo
            curr[word1.length()]=word2.length()-j_index;
            //most important line
            for(int i_index=word1.length()-1; i_index >= 0; i_index--){
            int ans = 0;
            if(word1[i_index] == word2[j_index]){
                ans=0+next[i_index+1];
            }
            else{
                int replace = 1+ next[i_index+1];
                int insert = 1+next[i_index];
                int remove = 1+curr[i_index+1];
                ans = min(insert,min(remove,replace));
            }
            curr[i_index] = ans;
        }
        //shifting 
        next=curr;
       }
       return next[0];
    }

    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        int ans = solveUsingTab(word1, word2);
        return ans;
    }
};