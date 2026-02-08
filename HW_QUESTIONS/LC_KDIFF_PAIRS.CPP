#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:

    // function to perform binary search
    int binarySearch(vector<int>&nums, int start, int target){
        int end = nums.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target > nums[mid]){
                start = mid +1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
    
    int findPairs(vector<int>& nums, int k) {
        
         sort(nums.begin(), nums.end());
         set<pair<int, int>> ans;

        //method 1: using set
        // int i=0, j=1;
        // while(j< nums.size()){
        //     int diff = nums[j]- nums[i];
        //     if(diff == k){
        //         ans.insert({nums[i], nums[j]});
        //         j++, i++;
        //     }
        //     else if(diff > k){
        //         i++;
        //     }
        //     else{
        //         j++;
        //     }
        //     if(i == j){
        //         j++;
        //     }
        // }
        // return ans.size();

        // method 2: applying binary search concept
        for(int i =0; i< nums.size(); i++){
            if(binarySearch(nums, i+1, nums[i]+ k) != -1){
                ans.insert({nums[i], nums[i]+ k});
            }
        }
        return ans.size();
    }
};