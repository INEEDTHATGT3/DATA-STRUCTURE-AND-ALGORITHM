#include <iostream>
#include <vector>  
#include <climits>
#include <cmath> 
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0, rem = 0;
        bool isnegative = false;

        if(x <=INT_MIN){
            return 0;
        }
        if(x<0){
                    x = x /10;
        }
        return isnegative ? -ans : ans ;
    }
};