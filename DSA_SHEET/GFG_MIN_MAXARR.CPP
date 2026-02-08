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
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        // changing array (bad practice)
        // sort(arr.begin(), arr.end());
        // vector<int> ans;
        // ans.push_back(arr[0]);
        // ans.push_back(arr[arr.size()-1]);
        // return ans;

        // without sorting (better approach)
        long long minVal = arr[0];
        long long maxVal = arr[0];

        if(arr.size() == 0){
            return {};
        }
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i] < minVal){
                minVal = arr[i];
            }
            else if(arr[i] > maxVal){
                maxVal = arr[i];
            }
        }

        return {(int)minVal, (int)maxVal};
    }
};