#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canPaint(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    bool canPaint(vector<int>& arr, int k, int time) {
        int painters = 1;
        int currTime = 0;

        for (int i = 0; i < arr.size(); i++) {
            currTime += arr[i];
            if (currTime > time) {
                painters++;
                currTime = arr[i];
            }
            if (painters > k) return false;
        }
        return true;
    }
};