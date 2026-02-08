#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int expandAroundIndex(string s, int left, int right) {
        int count = 0;
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();
        
        for(int i=0; i<n; i++){
        // check for odd length palindrome
        int oddAns = expandAroundIndex(s, i, i);
        count = count + oddAns;
        // check for even length palindrome
        int evenAns = expandAroundIndex(s, i, i+1);
        count = count + evenAns;
        }
        return count;
    }
};
