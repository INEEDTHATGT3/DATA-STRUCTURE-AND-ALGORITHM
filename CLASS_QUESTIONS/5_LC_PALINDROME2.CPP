#include<iostream>
#include<string>
#include<string.h>

using namespace std;

class Solution {
public:

    bool checkPalindrome(string s, int i, int j){
        while(i < j) {
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i =0;
        int j = s.length() -1;

        while(i< j) {
            if(s[i] != s[j]){
                // ya to i ya j remove
                return checkPalindrome(s, i+1, j) || checkPalindrome(s, i, j-1);
            }
                i++;
                j--;
        }
        return true;
    }
};