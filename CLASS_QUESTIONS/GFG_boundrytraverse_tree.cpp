#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    
    void printLeftBoundry(Node* root, vector<int>& ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            return;
        }
        ans.push_back(root->data);
        if(root->left != NULL){
            printLeftBoundry(root->left, ans);
        }
        else{
            printLeftBoundry(root->right, ans);
        }
    }

    void printLeafBoundry(Node* root, vector<int>& ans){
        if(root== NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        printLeafBoundry(root->left, ans);
        printLeafBoundry(root->right, ans);
    }

    void printRightBoundry(Node* root, vector<int>& ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            return;
        }
        if(root->right != NULL){
            printRightBoundry(root->right, ans);
        }
        else{
            printRightBoundry(root->left, ans);
        }
        ans.push_back(root->data);
    }

    void boundryTraversalUtil(Node* root, vector<int>& ans){
        if(root == NULL){
            return;
        }
        ans.push_back(root->data);
        printLeftBoundry(root->left, ans);
        printLeafBoundry(root->left, ans);
        printLeafBoundry(root->right, ans);
        printRightBoundry(root->right, ans);
    }

    vector<int> boundaryTraversal(Node *root) {
        // code here
       vector<int> ans;
       boundryTraversalUtil(root, ans);
       return ans;
    }
};