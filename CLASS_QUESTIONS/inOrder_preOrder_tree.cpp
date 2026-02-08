#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
#include<unordered_map>
#include<map>
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

int searchInOrder(int inOrder[], int size, int target){
    for(int i=0; i<size; i++){
        if(inOrder[i] == target){
            return i;
        }
    }
    return -1;
}

void levelOrderTraversal(Node* root){
        queue<Node*> q;
        q.push(root);
        q.push(NULL); //level marker

        //asli traversal start karte hai
        while(!q.empty()){
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
    cout << endl;
}

void createMapping(int inorder[], int size, map<int,int> &valueToIndexMap){
    for(int i=0; i<size; i++){
        int element = inorder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

Node* constructTreeFromPreandInOrder_Traversal(map<int,int> &valueToIndexMap, int preorder[], int inorder[], int &preIndex, int inOrderStart, int inOrderEnd, int size){
    //base case
    if(preIndex >=size || inOrderStart > inOrderEnd){
        return NULL;
    }

    // 1 case solution
    int element = preorder[preIndex];
    preIndex++;
    Node* root = new Node(element);
    // element search in inorder array
    int position = searchInOrder(inorder, size, element); //optimization possible hai map

    //BAAKI recursion sambhal lega
    root->left = constructTreeFromPreandInOrder_Traversal(valueToIndexMap, preorder, inorder, preIndex, inOrderStart, position-1, size);
    root->right = constructTreeFromPreandInOrder_Traversal(valueToIndexMap, preorder, inorder, preIndex, position+1, inOrderEnd, size);
    return root;
}

Node* constructTreeFromPostandInOrder_Traversal(map<int,int> &valueToIndexMap, int postorder[], int inorder[], int &postIndex, int inOrderStart, int inOrderEnd, int size){
    //base case
    if(postIndex < 0 || inOrderStart > inOrderEnd){
        return NULL;
    }

    // 1 case solution
    int element = postorder[postIndex];
    postIndex--;
    Node* root2 = new Node(element);
    // element search in inorder array
    int position = searchInOrder(inorder, size, element); //optimization possible hai map

    //BAAKI recursion sambhal lega
    root2->right = constructTreeFromPostandInOrder_Traversal(valueToIndexMap, postorder, inorder, postIndex, position+1, inOrderEnd, size);
    root2->left = constructTreeFromPostandInOrder_Traversal(valueToIndexMap, postorder, inorder, postIndex, inOrderStart, position-1, size);
    
    return root2;
}

int main(){
    int inorder[] = {10,8,6,2,4,12};
    int inorder2[]= {8,14,6,2,10,4};
    int postorder[] = {8,6,14,4,10,2};
    int preorder[] = {2,8,10,6,4,12};
    int size = 6;

    int preOrderIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = size-1;
    int postIndex = size-1;

    map<int, int> valueToindexMap;
    createMapping(inorder, size, valueToindexMap);

    Node* root = constructTreeFromPreandInOrder_Traversal(valueToindexMap, preorder, inorder, preOrderIndex, inOrderStart, inOrderEnd, size);

    Node* root2 = constructTreeFromPostandInOrder_Traversal(valueToindexMap, postorder, inorder2, postIndex, inOrderStart, inOrderEnd, size);

    cout << "Inorder traversal is: "<< endl;
    levelOrderTraversal(root);
    cout << "inorder traversal of tree 2 is: "<< endl;
    levelOrderTraversal(root2);
    return 0;
}