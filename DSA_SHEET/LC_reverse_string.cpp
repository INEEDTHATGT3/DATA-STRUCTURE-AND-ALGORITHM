#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
#include<limits.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = (int)s.size()-1;
        while(start < end){
            swap(s[start] , s[end]);
            start++;
            end--;
        }
    }
};