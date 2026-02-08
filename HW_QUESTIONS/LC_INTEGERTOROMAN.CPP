#include<iostream>
#include<string>
#include<limits.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string romansymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        int romanvalues[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        string ans= "";

        for(int i=0; i<13; i++){
            while(num >= romanvalues[i]){
                ans += romansymbols[i];
                num -= romanvalues[i];
            }
        }
        return ans;
    }
};
