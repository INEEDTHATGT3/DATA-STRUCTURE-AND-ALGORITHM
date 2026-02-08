#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
using namespace std;

class Solution {
public:
int solveUsingTabSO(string &a, string &s){
        vector<int> curr(a.length()+1,0);
        vector<int> next(a.length()+1,0);

        for(int j_index=s.length()-1; j_index>=0; j_index--){
        for(int i_index=s.length()-1; i_index>=0; i_index--)
            {
                int ans=0;
                if(a[i_index] == s[j_index]){
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

    int longestPalindromeSubseq(string s) {
        string a =s;
        reverse(a.begin(),a.end());
        int ans= solveUsingTabSO(a,s);
        return ans;
    }
};