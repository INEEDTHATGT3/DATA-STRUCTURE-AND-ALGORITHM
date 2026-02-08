#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
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

Node* createTree(){
    cout<<" enter the value for node: " << endl;
    int value;
    cin >> value;

    if(value == -1){
        return NULL;
    }

    //create node
    Node* root = new Node(value);
    cout << "enter in left: " << value << endl;
    root->left = createTree();
    cout<<"enter in right: " << value<< endl;
    root->right = createTree();
    return root;
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    cout << endl;

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
            else{
                cout<<temp->data << " ";
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
        }
    }
}

void printLeftView(Node* root, int level, vector<int> &leftView){
    if(root == NULL)
        return;

    if(level == leftView.size()){
        // iska matlab left view ki node milgayi , store kardia
        leftView.push_back(root->data);
    }
    printLeftView(root->left, level+1, leftView);
    printLeftView(root->right, level +1, leftView);
}

void printRightView(Node* root, int level, vector<int> &rightView){
    if(root == NULL)
        return;

    if(level == rightView.size()){
        // iska matlab right view ki node milgayi , store kardia
        rightView.push_back(root->data);
    }
    printRightView(root->right, level +1, rightView);
    printRightView(root->left, level+1, rightView);
}

void printTopView(Node* root){
    map<int,int> hdToNodeMap;

    queue<pair<Node* , int >> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;
        // hd ke liye ans store nhi hua hai to store karlo

        if(hdToNodeMap.find(hd) == hdToNodeMap.end()){
            hdToNodeMap[hd] = frontNode-> data;
        }

        // child ko dekho
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left, hd -1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    cout << "printing top view: " << endl;
    for(auto i: hdToNodeMap){
        cout<< i.second << " ";
    }
}

void printBottomView(Node* root){
    map<int,int> hdToNodeMap;

    queue<pair<Node* , int >> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        //overwrite answers so that deeper nodes can be stored
        hdToNodeMap[hd] = frontNode-> data;

        // child ko dekho
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left, hd -1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    cout << "printing top view: " << endl;
    for(auto i: hdToNodeMap){
        cout<< i.second << " ";
    }
}

int main(){
    Node* root = createTree();
    levelOrderTraversal(root);
   
    vector<int> leftView; //simillarly right view ke liye
    printLeftView(root,0,leftView);
    cout << "printing left view: " << endl;
    for(int i = 0; i<leftView.size(); i++){
        cout << leftView[i] << " ";
    }

    printTopView(root);
    return 0;
}