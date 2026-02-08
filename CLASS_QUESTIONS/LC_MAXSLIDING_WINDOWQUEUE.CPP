#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        
        //first window traverse
        for(int i=0; i<k; i++){
            //chote element remove kardo
            while(!q.empty() &&nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            //inserting index, so that we can check window element
            q.push_back(i);
        }
        //store answer for first window
        ans.push_back(nums[q.front()]);

        //remaining window ko process 
        for(int i=k; i<nums.size(); i++){
            //out of window element ko remove kardiya
            if(!q.empty() && i-q.front() >= k){
                q.pop_front();
            }
            // firse current element ke lie chote element remove kardo
            while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            //inserting index, so that we can checkout of window element
            q.push_back(i);

            //current window ka answer store karna 
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};