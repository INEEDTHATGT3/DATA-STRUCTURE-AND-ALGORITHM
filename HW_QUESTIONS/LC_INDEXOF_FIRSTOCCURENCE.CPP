#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for(int i=0; i <= n-m; i++){
            for(int j=0; j<m; j++){
                if(needle[j] != haystack[i+j]){
                    break; // if characters do not match, break inner loop
                }
                if(j == m-1){
                    return i; // if we reach end of needle, return i
                }
            }
        }
        return -1; //if haystack does not contain needle, return -1
    }
};