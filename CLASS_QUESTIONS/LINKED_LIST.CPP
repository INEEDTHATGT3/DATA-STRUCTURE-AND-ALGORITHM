#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(){
        this->data =0;
        this->next = NULL;
    }
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data << " ";
        temp = temp ->next;
    }
}

int findLength(node* head){
    int len = 0;
    node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(node* &head,node* &tail, int data){
    //check for empty LL
    if(head == NULL){
        node* newNode = new node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //step 1
    node* newNode = new node(data);
    //step 2
    newNode->next = head;
    //step 3
    head = newNode;
}

void insertAtTail(node* &head,node* &tail, int data){

    //step 1
    node* newNode = new node(data);
    //step 2
    tail->next = newNode;
    //step 3 
    tail = newNode;
}

void insertAtPosition(int data, int position, node* &head, node* &tail){
    if(head == NULL){
        node* newNode = new node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    //step 1 
    if(position == 0){
        insertAtHead(head, tail, data);
        return;
    }
    int len = findLength(head);
    if(position >= len){
        insertAtTail(head, tail, data);
        return;
    }
    int i = 1;
    node* prev = head;
    while(i < position){
        prev = prev->next;
        i++;
    }
    node* curr = prev->next;
    //step 2
    node* newNode = new node(data);

    //step 3
    newNode->next = curr;
    //step 4
    prev->next = newNode;
}

void deleteNode(int position, node* &head, node* &tail){
    if(head == NULL){
        cout << "cannot delete, ll is empty";
        return;
    }

    if(position == 1){
        node* temp = head;
        head = head->next;
        temp->next=NULL;
        delete temp;
    }
    int len = findLength(head);

    // last position deletion
    if(position == len){
        // find prev
        int i = 1;
        node* prev = head;
        while(i < position-1){
            prev = prev -> next;
            i++;
        }
        //step2
        prev->next = NULL;
        //step3
        node* temp = tail;
        //step 4
        tail = prev;
        //step 5
        delete temp;
        return;
    }

    //middle position deletion
    //step 1 find prev and curr
    int i = 1;
    node* prev = head;
    while(i < position-1){
        prev = prev-> next;
        i++;
    }
    node* curr = prev->next;
    //step2
    prev->next = curr-> next;
    //step3
    curr->next = NULL;
    //step 4
    delete curr;
}

node* reverse(node* &prev, node* &curr){
    //base case
    if(curr == NULL){
        //ll REVERSE HO CHUKI
        return prev;
    }

    //1 case solution
    node* forward = curr -> next;
    curr -> next = prev;

    reverse(curr,forward);
}

node* reverseUsingloo(node* head){
    node* prev = NULL;
    node* curr = head;

    while(curr != NULL){
        node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

int main(){
    // for understanding created individually nodes and linked them 
    // node* n1 = new node(10);
    // node* n2 = new node(20);
    // node* n3 = new node(30);
    // node* n4 = new node(40);
    // node* n5 = new node(50);

    // n1->next= n2; 
    // n2->next= n3; 
    // n3->next= n4; 
    // n4->next= n5; 

    // cout << "printing the LL" << endl;
    // print(n1);

    //creating L.L
    node* head = NULL;
    node* tail = NULL;
    insertAtHead(head,tail, 30);
    insertAtHead(head,tail, 50);
    insertAtHead(head,tail, 60);
    insertAtHead(head,tail, 90);
    insertAtTail(head,tail, 100);
    insertAtPosition(101, 3, head, tail);
    
    print(head);

    node* prev = NULL;
    node* curr = head;
    head = reverse(prev,curr);
    cout <<endl;
    print(head);
    cout << endl;

    return 0;
}