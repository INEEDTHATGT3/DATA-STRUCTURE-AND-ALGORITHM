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
    void reverseArray(vector<int> &arr) {
        // code here
        // two pointer approach
        int start = 0;
        int end = arr.size()-1;

        while(start < end){
            swap(arr[start], arr[end]);
            start++;
            end--; 
        }
    }
};