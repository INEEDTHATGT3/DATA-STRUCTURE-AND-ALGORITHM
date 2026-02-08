#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
#include<limits.h>
using namespace std;

class info{
    public:
    int data; // element value
    int row; // which array it is form
    int col; // index of array
    info(int val, int r, int c){
        data = val;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(const info& a, const info& b){
        return a.data > b.data;
    }// custom comparator
};

class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        int k = mat.size();
        int n = mat[0].size();

        priority_queue<info, vector<info>, compare> minHeap;
        // har array ka first element daldiya minHeap mai
        for(int i=0; i<k; i++){
            minHeap.push(info(mat[i][0], i, 0));
        }
        vector<int> ans;

        // minHeap ka front ans mai daldo
        while(!minHeap.empty()){
            info temp = minHeap.top();
            int topElement = temp.data;
            int topRow = temp.row;
            int topCol = temp.col;
            minHeap.pop();

            ans.push_back(topElement);

            if(topCol + 1 < n){
                minHeap.push(info(mat[topRow][topCol + 1], topRow, topCol + 1));
            }
        }
        return ans;
    }
};