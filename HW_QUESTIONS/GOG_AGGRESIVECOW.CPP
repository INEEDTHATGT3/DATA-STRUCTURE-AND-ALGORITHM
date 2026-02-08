#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
  public:

    bool isPossible(vector<int> &stalls, int n, int k, int mid){
        int cows = 1 ; //start with 1 cow
        int pos = stalls[0]; //1st cow at 1st stall
        for(int i =1; i<n; i++){
            if(stalls[i] - pos >= mid){
                cows++; // place next cow
                pos = stalls[i]; // update position of last placed cow
            }
            if(cows == k){
                return true; // if we have placed all cows
            }
        }
        return false; // if we couldn't place all cows
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int start = 0;
        int end = stalls[n-1]- stalls[0];
        int ans = -1;

        while(start <= end){
            int mid = start + (end- start)/2;
            if(isPossible(stalls, n, k, mid)){
                ans = mid; // found a possible solution
                start = mid +1; // try for larger distance
            }
            else{
                end = mid - 1; // try for smaller distance
            }
        }
        return ans;
    }
};