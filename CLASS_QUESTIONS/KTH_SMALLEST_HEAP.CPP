#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq;
        //first k element ko process kara
        for(int i=0; i<k; i++){
            int element = arr[i];
            pq.push(element);
        }
        int n = arr.size();
        //remaining element ko tabhi insert karege jab vo root se chotta hoga
        for(int i=k; i<n; i++){
            int element = arr[i];
            if(element <pq.top()){
                pq.pop();
                pq.push(element);
            }
        }
        int ans = pq.top();
        return ans;
    }
};