#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
#include<limits.h>
using namespace std;

class node{
    public:
    int data;
    int row;
    int col;

    node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<node*, vector<node*>, compare> minHeap;
        int k = nums.size();
        for(int i=0; i<k; i++){
            int element = nums[i][0];
            maxi = max(maxi, element);
            mini = min(mini, element);

            minHeap.push(new node(element, i, 0));
        }

        int ansStart = mini;
        int ansEnd = maxi;

        while(!minHeap.empty()){
            node* top = minHeap.top();
            int topElement = top->data;
            int topRow = top->row;
            int topCol = top->col;
            minHeap.pop();

            //mini updated
            mini = topElement;
            //check for ans
            int currRange = maxi-mini;
            int ansRange = ansEnd-ansStart;
            if(maxi-mini < ansEnd - ansStart){
                ansStart = mini;
                ansEnd = maxi;
            }

            //check for new element in same list
            if(topCol + 1 < nums[topRow].size()){
                node* newNode = new node(nums[topRow][topCol +1], topRow,topCol+1);
                minHeap.push(newNode);
                //update maxi 
                if(newNode->data > maxi){
                    maxi = newNode->data;
                }
            }
            else{
                //there is no element in the samearray
                break;
            }
         }
         vector<int> ans;
         ans.push_back(ansStart);
         ans.push_back(ansEnd);
         return ans;
        
    }
};