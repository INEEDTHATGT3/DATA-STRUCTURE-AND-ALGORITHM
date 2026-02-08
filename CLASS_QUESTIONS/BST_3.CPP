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

    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insertIntoBST(Node* &root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    // it is not first node
    if(data > root->data){
        //right part
        root->right = insertIntoBST(root->right, data);
    }
    else{
        //left part
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void createBST(Node* &root){
    cout<< "enter data: " << endl;
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cout<< "enter data: " << endl;
        cin >> data;
    }

}

void levelOrdertraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right); 
            }
        }
    }
}

void preOrder(Node* root){
    //NLR
    if(root == NULL){
        return;
    }

    cout<< root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    //LNR
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<< root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root){
    //LRN
    if(root == NULL){
        return;
    }

    preOrder(root->left);
    preOrder(root->right);
    cout<< root->data << " ";
}

int minValue(Node* root){
    if(root == NULL){
        cout << "tree empty" << endl;
        return -1;
    }
    
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

int maxValue(Node* root){
    if(root == NULL){
        cout << " tree empty: " << endl;
        return -1;
    }

    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

Node* maxValueNode(Node* root){
    if(root == NULL){
        return NULL;
    }

    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

bool searchInBST(Node* root, int target){
    // base case
    if(root == NULL){
        return false;
    }
    //solved 1 case
    if(root->data == target){
        return true;
    }

    // recursive case
    bool leftAns = false;
    bool rightAns = false;

    if(target > root-> data){
        // right part
        rightAns = searchInBST(root->right, target);
    }
    else{
        //left part 
        leftAns = searchInBST(root->left, target); 
    }
    return leftAns || rightAns;
}

Node* deleteFromBST(Node* root, int target){
    // target ko dhudho
    // target ko delete karo
    if(root == NULL){
        return NULL;
    }

    if(root->data == target){
        //ab delete karrege
        //4 cases
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //2nd case -> left non null and right null
        else if(root->left != NULL && root->right == NULL){
            Node* childSubTree = root->left;
            delete root;
            return childSubTree;
        }

        //3rd case -> left null , right non null
        else if(root->left == NULL && root->right != NULL){
            Node* childSubTree = root->right;
            delete root;
            return childSubTree;
        }

        //4th case both non null
        else{
            //a -> left ki max
            Node* maxi = maxValueNode(root->left);
            //replacement
            root->data = maxi->data;
            //delete actual maxi
            root->left = deleteFromBST(root->left, maxi->data);
            return root;
        }
    }
    else if(root->data > target){
        //left mai chalo
        root->left = deleteFromBST(root->left, target);
    }
    else{
        //right me jao
        root->right =  deleteFromBST(root-> right, target);
    }
    return root;
}

Node* bstFromInOrder(int inorder[], int s, int e){
    //base case
    if(s > e){
        return NULL;
    }

    // 1 case hum solve karege
    int mid = (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

    //baaki recursion
    root->left = bstFromInOrder(inorder, s, mid-1);
    root->right = bstFromInOrder(inorder, mid+1, e);

    return root;
}

void convertIntoSortedDLL(Node* root, Node* &head){
    //base case
    if(root==NULL){
        return;
    }

    //right subtree into LL
    convertIntoSortedDLL(root->right, head);
    //attach root node
    root->right = head;

    if(head != NULL){
        head->left = root;
    }

    //update head
    head = root;

    //;eft subtree into LL
    convertIntoSortedDLL(root->left, head);
}

void printLinkedList(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp->right;
    }
    cout << endl;
}

Node* sortedLLIntoBST(Node* &head, int n){
    //base case
    if(n <= 0 || head == NULL){
        return NULL;
    }

    //left subtree formed
    Node* leftSubtree = sortedLLIntoBST(head, n-1-n/2);
    //head at mid
    Node* root = head;
    root->left = leftSubtree;

    head = head->right;

    //right subtree formed
    root->right = sortedLLIntoBST(head, n/2);
    return root;
}

int main(){
    int inorder[] = {1,2,3,4,5,6,7,8,9};

    cout << "print sorted linked list: " <<endl;

    Node* root = bstFromInOrder(inorder, 0, 8);
    levelOrdertraversal(root);
    Node* head = NULL;
    convertIntoSortedDLL(root, head);
    printLinkedList(head);

    Node* root1 = NULL;
    root1 = sortedLLIntoBST(head,9);
    cout << "level order treversal for root1" << endl;
    levelOrdertraversal(root1);
}
