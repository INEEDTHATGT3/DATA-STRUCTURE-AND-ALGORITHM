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
    int solveUsingRec(int n, int x, int y, int z, vector<int> &dp, vector<bool> &computed) {
        if (n == 0) return 0;
        if (n < 0) return INT_MIN;

        if (computed[n]) {
            return dp[n];
        }

        // Initialize with a very small value to represent impossible state
        int opt1 = solveUsingRec(n - x, x, y, z, dp, computed);
        int opt2 = solveUsingRec(n - y, x, y, z, dp, computed);
        int opt3 = solveUsingRec(n - z, x, y, z, dp, computed);

        // Only add 1 if the path is valid (not INT_MIN)
        int res = INT_MIN;
        if (opt1 != INT_MIN) res = max(res, 1 + opt1);
        if (opt2 != INT_MIN) res = max(res, 1 + opt2);
        if (opt3 != INT_MIN) res = max(res, 1 + opt3);

        dp[n] = res;
        computed[n] = true;
        return dp[n];
    }

    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int> dp(n + 1, INT_MIN);
        vector<bool> computed(n + 1, false);
        
        int ans = solveUsingRec(n, x, y, z, dp, computed);
        
        // If ans is still INT_MIN, it means no valid cuts were found.
        // According to problem constraints, return 0 in such cases.
        return (ans < 0) ? 0 : ans;
    }
};
