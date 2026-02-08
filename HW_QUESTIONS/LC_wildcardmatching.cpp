#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:

    bool isMatchHelper(string &s, int si, string &p, int pi){
        //base case
        if(si == s.size() && pi == p.size()){
            return true;
        }

        if(si == s.size() && pi < p.size()){
            while(pi < p.size()){
                if(p[pi] != '*') return false;
                pi++;
            }
            return true;
        }

        //single char matches 
        if(s[si] == p[pi] || '?' == p[pi]){
            return isMatchHelper(s, si+1, p, pi+1);
        }

        //if * is encountered
        if(p[pi] == '*'){
            // treat '*' as empty or null
            bool case1 = isMatchHelper(s, si, p,pi+1);
            // treat '*' as single or multiple characters
            bool case2 = isMatchHelper(s, si+1, p, pi);
            return case1 || case2;
        }
        // if characters do not match
        return false;
    }
    bool isMatch(string s, string p) {
        int si = 0; //ith index for each strings
        int pi = 0;

        return isMatchHelper(s, si, p, pi);
    }
};