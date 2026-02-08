#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    static bool mycomp(string a, string b){
        string t1 = a+b;
        string t2 = b+a;
        return t1>t2;
    }
    string largestNumber(vector<int>& nums) {
    vector<string> snums;
    for(auto n:nums){
        snums.push_back(to_string(n));
        }      
    sort(snums.begin(), snums.end(), mycomp);

    string ans = "";
    for(auto str:snums){
        ans+=str;
    }
    if(ans[0] == '0' && ans.size() -1 == 0)
    return "0";

    return ans;
    }
};