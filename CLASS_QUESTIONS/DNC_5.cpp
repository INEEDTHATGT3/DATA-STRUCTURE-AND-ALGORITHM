#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// class Solution {
// public:

//     void solve(vector<string>& ans ,int n ,int open ,int close, string output){
//         //basecase 
//         if(open == 0 && close == 0){
//             ans.push_back(output);
//             return;
//         }

//         //include open bracket
//         if(open > 0){
//             output.push_back('(');
//             solve(ans, n,open -1, close, output);
//             //backtrack
//             output.pop_back();
//         }

//         //include close bracket
//         if(close > open){
//             output.push_back(')');
//             solve(ans, n, open, close-1, output);
//             //backtrack
//             output.pop_back();
//         }
//     }

//     vector<string> generateParenthesis(int n) {
//         vector<string> ans;
//         int open = n;
//         int close = n;
//         string output = "";
//         solve(ans ,n ,open ,close ,output );
//         return ans;
//     }
// };

class Solution {
public:

    void solve(vector<string>& ans,int index, string output, string digits, vector<string>& mapping){
        // base case
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        // 1 case solve, baaki recursion
        int digit = digits[index] - '0';
        string value = mapping[digit];
        for(int i=0; i<value.length(); i++){
            char ch = value[i];
            output.push_back(ch);
            solve(ans, index+1, output, digits, mapping);
            //backtrack
            output.pop_back();
        }


    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0)
         return ans; 
        int index = 0;
        string output = "";
        vector<string> mapping(10);
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        solve(ans, index, output, digits, mapping);
        return ans;

    }
};