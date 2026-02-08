#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void storeInOrder(TreeNode* root, vector<int> &inorder){
        //base case
        if(root==NULL){
            return;
        }

        //LNR
        storeInOrder(root->left, inorder);
        inorder.push_back(root->val);
        storeInOrder(root->right, inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        storeInOrder(root, inorder);

        // find target 2 pointer approach
        int start = 0;
        int end = inorder.size()-1;

        while(start < end){
            int sum = inorder[start]+ inorder[end];
            if(sum == k){
                return true;
            }
            else if(sum>k){
                end--;
            }
            else if(sum<k){
                start++;
            }
        }
        return false;
    }
};