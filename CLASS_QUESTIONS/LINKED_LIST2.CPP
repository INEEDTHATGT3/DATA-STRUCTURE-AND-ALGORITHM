#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;

    node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    node(int data){
         this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~node(){
        cout << "node with value: " << this->data << "deleted" << endl;
    }
};

void print(node* &head){
    node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp->next;
    }
}

int getlength(node* head){
    int len = 0;
    node* temp = head;

    while(temp != NULL){
        temp = temp -> next;
        len++;
    }
    return len;
}

void insertAtHead(node* &head, node* &tail, int data){
    if(head == NULL){
        //ll is empty
        node* newNode = new node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        //LL is non empty
        //step 1
        node* newNode = new node(data);
        //step 2
        newNode->next = head;
        //step3
        head->prev = newNode;
        //step4
        head = newNode;
    }
}

void insertAtTail(node* &head, node* &tail, int data){
    if(head == NULL){
        //LL is empty
        node* newNode = new node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        //LL is non epty
        node* newNode = new node(data);
        tail ->next = newNode;
        newNode ->prev = tail;
        tail = newNode;
    }
}

void insertAtPosition(node* &head, node* &tail, int data, int position){
    if(head == NULL){
        //LL is empty
        node* newNode = new node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        //LL is non empty
        if(position == 1){
            insertAtHead(head, tail,data);
            return;
        }
        int len = getlength(head);
        if(position > len){
            insertAtTail(head, tail, data);
            return;
        }
        //insertion in middle
        //step1 find prev && curr
        int i = 1;
        node* prevNode = head;
        while(i < position - 1){
            prevNode = prevNode->next;
            i++;
        }
        node* curr = prevNode->next;

        //step 2
        node* newNode = new node(data);
        //step 3
        newNode->next = curr;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        curr->prev = newNode;
    }
}

void deleteFromPos(node* &head, node* &tail, int position){
    if(head == NULL){
        cout << "LL is empty";
        return;
    }
    if(head->next == NULL){
        //single node
        node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    if(position == 1){
        //want to delete first node
        node* temp = head;
        head = head ->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    int len = getlength(head);
    if(position == len){
        //last node delete
        node* temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }

    //delete from middle of linked list
    //step 1
    int i =1;
    node* left = head;
    while(i<position -1){
        left = left -> next;
        i++;
    }
    node* curr = left -> next;
    node* right = curr->next;

    //step2
    left-> next = right;
    //step3 
    right -> prev = left;
    //step4
    curr -> next = NULL;
    curr -> prev = NULL;
    delete curr;
}

int main(){

    //doubly linked list
    node *n1 = new node(10);
    node *n2 = new node(20);
    node *n3 = new node(30);

    node* head = n1;
    node* tail = n3;
    n1->next=n2;
    n2->prev=n1;

    n2->next=n3;
    n3->prev=n2;

    insertAtHead(head,tail,101);
    insertAtTail(head,tail,501);
    insertAtPosition(head,tail, 401,2);
    deleteFromPos(head,tail,1);

    print(head);
    cout << endl;
    return 0;
}