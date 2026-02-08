#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    int solveUsingRec(vector<int> &nums, int index){
        //base case
        if(index >= nums.size()){
            return 0;
        }

        //sol for 1 case
        int robAmt1 = nums[index] + solveUsingRec(nums, index+2);
        int robAmt2 = 0 + solveUsingRec(nums, index+1);

        return max(robAmt1, robAmt2);
    }

    int solveUsingMem(vector<int> &nums, int index, vector<int> &dp) {
        // Base case: If index is out of bounds, no money can be robbed
        if (index >= nums.size()) {
            return 0;
        }

        // Memoization check
        if (dp[index] != -1) {
            return dp[index];
        }

        // Option 1: Rob current house and skip the next one
        int robAmt1 = nums[index] + solveUsingMem(nums, index + 2, dp);
        
        // Option 2: Skip current house and move to the next one
        int robAmt2 = 0 + solveUsingMem(nums, index + 1, dp);

        // Store and return the maximum of both choices
        return dp[index] = max(robAmt1, robAmt2);
    }

    int solveUsingMem(vector<int> &nums, int index, vector<int> &dp) {
        // Base case: If index is out of bounds, no money can be robbed
        if (index >= nums.size()) {
            return 0;
        }

        // Memoization check
        if (dp[index] != -1) {
            return dp[index];
        }

        // Option 1: Rob current house and skip the next one
        int robAmt1 = nums[index] + solveUsingMem(nums, index + 2, dp);
        
        // Option 2: Skip current house and move to the next one
        int robAmt2 = 0 + solveUsingMem(nums, index + 1, dp);

        // Store and return the maximum of both choices
        return dp[index] = max(robAmt1, robAmt2);
    }


    int solveUsingTablulation(vector<int> &nums, int index, vector<int> &dp) {
        int n = nums.size();
        // step 1
        vector<int> dp(n, 0);
         if (n == 0) return 0;
        if (n == 1) return nums[0];
        //step 2
        dp[n-1] = nums[n-1]; //jo bhi paise pade hai wohi ans

        for(int index = n-2; index=0; index--){
            int tempAns = 0;
            if(index+2 < n){
                tempAns = dp[index+2]; //check if not going outofbound
            }
            int robAmt1 = nums[index] + dp[index+2];
            int robAmt2 = 0 + dp[index+1];
            dp[index] = max(robAmt1, robAmt2);
        }
        return dp[0];

    }

    int solveUsingTablulationSO(vector<int> &nums) {
        int n = nums.size();
        
        // Edge cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // prev represents dp[i+1] (the house immediately to the right)
        // next represents dp[i+2] (the house two steps to the right)
        int prev = nums[n-1]; 
        int next = 0;
        int curr = 0;

        // Start from the second to last house and move backwards
        for (int index = n - 2; index >= 0; index--) {
            
            // Option 1: Rob current house + skip next (use 'next' which is i+2)
            int robAmt1 = nums[index] + next;
            
            // Option 2: Skip current house (use 'prev' which is i+1)
            int robAmt2 = 0 + prev;
            
            curr = max(robAmt1, robAmt2);

            // Shift variables for the next iteration (moving left)
            next = prev;
            prev = curr;
        }
        
        // After the loop finishes, 'prev' holds the result for index 0
        return prev;
    }

    int rob(vector<int>& nums) {
        return solveUsingTablulationSO(nums);
    }
};
