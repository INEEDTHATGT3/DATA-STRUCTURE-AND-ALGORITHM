#include<iostream>
#include<string>
#include<limits.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        // int integer = atoi(s.c_str()); // convert string to c-style string and then to integer
        // return integer; 
        int num=0, i=0, sign=1; //+ve
        // remove leading whitespaces
        while(s[i]== ' '){
            i++;
        }

        //check for sign
        if(i < s.size() && (s[i] == '-' || s[i] == '+')){
            sign = (s[i] == '-') ? -1 : 1;
            ++i;
        }

        // check for digits
        while(i<s.size() && isdigit(s[i])){
            if(num > INT_MAX/10 || (num == INT_MAX / 10 && s[i] > '7')){
                return sign == -1 ? INT_MIN : INT_MAX; // handle overflow
            }

            num = num * 10 + (s[i]- '0');
            ++i;
        }

        return num*sign;
    }
};