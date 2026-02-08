#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
#include<limits.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class NodeData{
    public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;
    
    NodeData(){
        size = 0;
        minVal = 0;
        maxVal = 0;
        validBST = false;
    }
    
    NodeData(int s, int minV, int maxV, bool valid){
        size = s;
        minVal = minV;
        maxVal = maxV;
        validBST = valid;
    }
};

class Solution {
  public:

    NodeData largestBst(Node *root, int &ans){
        //base case

        if(root == NULL){
            NodeData temp(0, INT_MAX, INT_MIN, true);
            return temp;
        }

        NodeData leftAns = largestBst(root->left, ans);
        NodeData rightAns = largestBst(root->right, ans);
        
        //checking starts here 
        NodeData currNodeAns;

        currNodeAns.size = leftAns.size + rightAns.size +1;

        currNodeAns.maxVal = max(root->data, rightAns.maxVal);
        currNodeAns.minVal = min(root->data, leftAns.minVal);

        if(leftAns.validBST && rightAns.validBST && (root->data > leftAns.maxVal && root->data < rightAns.minVal)){
            currNodeAns.validBST = true;
        }
        else{
            currNodeAns.validBST = false;
        }

        if(currNodeAns.validBST){
            ans = max(ans, currNodeAns.size);
        }

        return currNodeAns;
    }
};