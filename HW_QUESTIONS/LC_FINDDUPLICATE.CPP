#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // sort(nums.begin(), nums.end());

        // for(int i = 0; i < nums.size() - 1; i++) {
        //     if (nums[i] == nums[i + 1]) {
        //         return nums[i]; // Return the duplicate number
        //     }
        // }
        // return -1; // Return -1 if no duplicate is found

    //     //negative marking method
    //    int ans = -1;
    //      for(int i = 0; i < nums.size(); i++) {
    //         int index = abs(nums[i]); // Get the index corresponding to the value
    //         //alreadyy visited
    //         if(nums[index] < 0) {
    //             ans = index;
    //             break;
    //         }
    //         nums[index] = -nums[index]; // Mark the number as seen by making it negative
    //     }
    //     return ans;
    // }

    //positioning method
    while(nums[0] != nums[nums[0]]) {
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }

};