#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

node* reverse(node* n1){
    node* prev=NULL;
    node* curr = n1;
    node*next = curr->next;
    while(curr != NULL){
        next = curr ->next;
        curr->next=prev;
        prev=curr;
        curr = next;
    }
    return prev;
}

bool checkPalindrome(node* &n1){
    if(n1 == NULL){
        cout << "LL is empty"<< endl;
        return true;
    }
    if(n1->next == NULL){
        return true;
    }

    //step1
    node* slow = n1;
    node* fast = n1->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    //slow pointer is pointing at middle node
    //step 2
    node* reverselln1 = reverse(slow->next);

    slow->next=reverselln1;
    //step3 
    node* temp1 = n1;
    node* temp2 = reverselln1;
    while(temp2 != NULL){
        if(temp1 -> data != temp2 ->data){
            return false;
        }
        else{
            //if data is equal, then aage
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
}

void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp ->next;
    } 
    cout << endl;
}

void removeDuplicate(node* &n1){
    if(n1 == NULL){
        cout << "LL is empty"<< endl;
        return;
    }
    if(n1->next == NULL){
        return;
    }

    //step 1 
    node* curr = n1;
    while(curr != NULL){
        if((curr->next != NULL) && (curr->data == curr->next->data)){
            node* temp = curr->next;
            curr->next=curr->next->next;
            temp->next = NULL;
            delete temp;
        }
        else{
            curr = curr->next;
        }
    }
}

int main(){
    node* n1 = new node(10);
    node* n2 = new node(20);
    node* n3 = new node(20);
    node* n4 = new node(30);
    node* n5 = new node(30);

    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    n4 -> next = n5;
    n5 -> next = NULL;

    bool isPalindrome = checkPalindrome(n1);

    if(isPalindrome){
        cout << "LL is a valid palindrome" << endl;
    }
    else{
        cout<<"LL is not a palindrome" << endl;
    }

    cout<<"input ll: ";
    print(n1);
    removeDuplicate(n1);
    cout<< "output ll: ";
    print(n1);
}