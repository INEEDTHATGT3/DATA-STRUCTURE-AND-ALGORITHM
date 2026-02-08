#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
using namespace std;


//  Definition for a binary tree node.
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
    bool solve(TreeNode* root, int targetSum, int sum){
        //base case
        if(root == NULL){
            return false;
        }
        sum += root->val;
        //leaf node
        if(root->left == NULL && root->right == NULL){
            //verify
            if(sum == targetSum){
                return true;
            }
            else{
                return false;
            }
        }
        int leftAns = solve(root->left, targetSum, sum);
        int rightAns = solve(root->right, targetSum, sum);
        return  leftAns|| rightAns;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return solve(root, targetSum, sum);
    }
};