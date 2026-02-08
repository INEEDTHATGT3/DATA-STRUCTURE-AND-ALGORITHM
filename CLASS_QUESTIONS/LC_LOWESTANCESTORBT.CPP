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
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //b.c
        if(root == NULL){
            return NULL;
        }
        if(root->val == p->val || root->val == q->val){
            return root;
        }

        TreeNode* LeftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode* RightAns = lowestCommonAncestor(root-> right, p, q);

        //3 cases
        if(LeftAns== NULL && RightAns == NULL){
            return NULL;
        }
        else if(LeftAns != NULL && RightAns == NULL){
            return LeftAns;
        }
        else if(LeftAns == NULL && RightAns != NULL){
            return RightAns;
        }
        else {
            return root;
        }
    }
};