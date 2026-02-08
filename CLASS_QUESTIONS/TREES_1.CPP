#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
     int data;
     Node* left;
     Node* right;

     Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
     }
};

//it returns root node of created 
Node* createTree(){
    cout << "enter data: " << endl;
    int data;
   cin >> data;

    if(data == -1){
       return NULL;
    }

        //create node
        Node* root = new Node(data);
        //create left subtree
        cout << "enter data for left: " << root->data << endl;
        root->left = createTree();
        //create right subtree
        cout << "enter data for right: " << root->data << endl;
        root->right = createTree();
        return root;
    }

    void preOrderTraversal(Node* root){
        //base case
        if(root == NULL){
            return ;
        }
        //nlr
        //N
        cout << root->data << " ";
        //L
        preOrderTraversal(root->left);
        //R
        preOrderTraversal(root->right);
     }

    void inorderTraversal(Node* root){
        //lnr
        //base case
        if(root == NULL){
            return;
        }

        //L
        inorderTraversal(root->left);
        //N
        cout << root->data << " ";
        //r 
        inorderTraversal(root->right);
     }

void postOrderTraversal(Node* root){
        //lrn
        //base case
        if(root == NULL){
            return;
        }
        //L
        postOrderTraversal(root->left);
        //R
        postOrderTraversal(root->right);
        //N
        cout << root->data << " ";
    }

void levelOrderTraversal(Node* root){
        queue<Node*> q;
        q.push(root);
        q.push(NULL); //level marker

        //asli traversal start karte hai
        while(q.empty()>1){
            Node* front = q.front();
            q.pop();
            if(front == NULL){
                cout << endl;
                if(!q.empty()){
                q.push(NULL);
                }
            }
            else{
            cout << front->data << " ";

            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            }
        }
    }
}

     int main(){
        Node* root = createTree();
        cout << root->data << endl;

        return 0;
     }