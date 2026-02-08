#include <iostream>
using namespace std;

class Solution {
  public:
    int setKthBit(int n, int k) {
        // Code here
        int mask = 1 << k;
        int ans = n | mask;
        return ans;

        // return n | (1<<k) ;
    }
};
