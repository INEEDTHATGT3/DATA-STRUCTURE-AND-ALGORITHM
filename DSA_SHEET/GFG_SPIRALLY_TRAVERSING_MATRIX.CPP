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
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<int> result;
        int top = 0, bottom = n-1;
        int left = 0, right = m-1;

        while(top <= bottom && left <= right){
            // 1. move right 
            for(int i = left; i <= right; i++){
                result.push_back(mat[top][i]);
            }
            top++;

            //2. down 
            for(int i=top; i<=bottom; i++){
                result.push_back(mat[i][right]);
            }
            right--;

            //3. left (check edge if row still exists)
            if(top<=bottom){
                for(int i=right; i>=left;i--){
                    result.push_back(mat[bottom][i]);
                }
                bottom--;
            }

            //4. up (check edge if column still exists)
            if(left<=right){
                for(int i=bottom; i >= top; i-- ){
                    result.push_back(mat[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};