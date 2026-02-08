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

     int findFirst(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1, res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                res = mid;
                high = mid - 1; // Keep looking on the left
            } else if (arr[mid] < x) low = mid + 1;
            else high = mid - 1;
        }
        return res;
    }

    int findLast(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1, res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                res = mid;
                low = mid + 1; // Keep looking on the right
            } else if (arr[mid] < x) low = mid + 1;
            else high = mid - 1;
        }
        return res;
    }
    vector<int> find(vector<int>& arr, int x) {
        // code here
        // naive approach
        // int start = 0;
        // int end = arr.size()-1;

        // vector<int> ans;

        // for(int start=0; start<arr.size(); start++){
        //     if(arr[start]== x){
        //         ans.push_back(start);
        //         break;
        //     }
        // }
        // for(int end=arr.size()-1; end>=0; end--){
        //     if(arr[end]== x){
        //         ans.push_back(end);
        //         break;
        //     }
        // }
        // if(ans.size()==0){
        //     return {-1, -1};
        // }
        // return ans;

        //optimal using binary search
        int first = findFirst(arr, x);
        if (first == -1) return {-1, -1};
        int last = findLast(arr, x);
        return {first, last};
    }
};