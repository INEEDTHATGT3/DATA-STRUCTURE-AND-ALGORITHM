#include <iostream>
#include <cmath>
using namespace std;

class Solution {
  public:
    int powMod(int x, int n, int M) {
        // code here
        if (M == 1) return 0; // Any number mod 1 is 0
        if (n < 0) return -1; // Not handling negative exponents
        if (x == 0 && n == 0) return 1; // Define 0^0 as 1
        int ans = 1;
        x = x % M; // Update x if it is more than or equal to M
        while (n > 0) {
            if (n & 1) { // If n is odd, multiply x with result
                ans = (1LL * ans * x) % M;
            }
            x = (1LL * x * x) % M; // Change x to x^2
            n >>= 1; // Divide n by 2
        }
        return ans;
    }
};