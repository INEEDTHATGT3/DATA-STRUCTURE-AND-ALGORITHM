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
    Node *left, *right;
};

class Solution {
  public:

    void storeInOrderTraversal(Node* root, vector<int> &inOrder){
        //base case
        if(root==NULL){
            return;
        }

        //LNR
        storeInOrderTraversal(root->left, inOrder);
        inOrder.push_back(root->data);
        storeInOrderTraversal(root->right, inOrder);
    }

    void replaceusingPostOrder(Node* root, vector<int> &inOrder, int &index){
        if(root == NULL){
            return;
        }
        //LRN
        replaceusingPostOrder(root->left, inOrder, index);
        replaceusingPostOrder(root->right, inOrder, index);
        root->data = inOrder[index];
        index++;
    }
    void convertToMaxHeapUtil(Node* root) {
        // Your code goes here
        //step 1 store inorder
        vector<int> inOrder;
        storeInOrderTraversal(root, inOrder);
        //step 2 sort the inorder traversal
        //replace node values with sorted inorder values, using post order traversal
        int index = 0;
        replaceusingPostOrder(root, inOrder, index);
    }
};
