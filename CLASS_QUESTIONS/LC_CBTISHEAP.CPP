#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
#include<limits.h>
#include<climits>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class info {
public:
    int maxVal;
    bool isHeap;
    info() {
        this->maxVal = INT_MIN;
        this->isHeap = true;
    }
    info(int a, bool b) {
        this->maxVal = a;
        this->isHeap = b;
    }
};

class Solution {
public:
    info solve(Node* root) {
        // Base case
        if (root == NULL) {
            info temp;
            temp.maxVal = INT_MIN;
            temp.isHeap = true;
            return temp;
        }
        if (root->left == NULL && root->right == NULL) {
            info temp;
            temp.maxVal = root->data;
            temp.isHeap = true;
            return temp;
        }

        info leftAns = solve(root->left);
        info rightAns = solve(root->right);

        info ans;
        // Check current node's heap property and if children subtrees are heaps
        if (root->data > leftAns.maxVal && root->data > rightAns.maxVal && leftAns.isHeap && rightAns.isHeap) {
            ans.maxVal = root->data;
            ans.isHeap = true;
            return ans;
        } else {
            ans.maxVal = std::max(root->data, std::max(leftAns.maxVal, rightAns.maxVal));
            ans.isHeap = false;
            return ans;
        }
    }

    bool levelorderTraversal(Node* root){
        queue<Node*> q;
        q.push(root);
        bool nullFound = false;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();

            if(front == NULL){
                nullFound = true;
            }
            else {
                if(nullFound){
                    return false;
                }
                q.push(front->left);
                q.push(front->right);
        }    
    }
    return true;
    }

    // void countNodes(Node* root, int &count){
    //     if(root == NULL){
    //         return;
    //     }
    //     count++;
    //     countNodes(root->left, count);
    //     countNodes(root->right, count);
    // }
    // Function to check if a binary tree is complete
    // bool isCompleteBinaryTree(Node* root) {
    //     int totalNodes = 0;
    //     countNodes(root, totalNodes);
    //     int lastNode = 0;
    //     levelorderTraversal(root, lastNode);
    //     if(lastNode > totalNodes){
    //         return false;
    //     }
    //     else{
    //         return true;
    //     }
    // }

    bool isHeap(Node* tree) {
        if (tree == NULL) {
            return true; // An empty tree is considered a heap
        }

        // Step 1: Check the heap property (parent > children)
        info heapPropertyCheck = solve(tree);
        if (!heapPropertyCheck.isHeap) {
            return false;
        }

        // Step 2: Check if the binary tree is complete
        return levelorderTraversal(tree);
    }
};