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

void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp ->next;
    } 
    cout << endl;
}

//replacement is allowed
void sortZeroOne(node* &n1){
    int zero = 0;
    int one = 0;
    int two = 0;

    node* temp = n1;
    while(temp != NULL){
        if(temp-> data == 0)
            zero++;
        else if(temp->data == 1)
            one++;
        else if(temp->data == 2)
            two++;
        temp = temp->next;
    }

    // step 2
    temp = n1;
        //fill zeros
        while(zero--){
            temp->data=0;
            temp=temp->next;
        }

        //fill ones
        while(one--){
            temp->data=1;
            temp=temp->next;
        }

        //fill twos
        while(two--){
            temp->data = 2;
            temp=temp->next;
        }
}

node* sortTwo(node* &n1){
    node* zeroHead = new node(-1);
    node* zeroTail = zeroHead;

    node* oneHead = new node(-1);
    node* oneTail = oneHead;

    node* twoHead = new node(-1);
    node* twoTail = twoHead;

    //traverse original ll
    node* curr = n1;
    while(curr != NULL){
        if(curr -> data == 0){
            //taking out zero wali node
            node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //append zero node in zeroHead
            zeroTail->next=temp;
            zeroTail=temp;
        }
        else if(curr->data==1){
            node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //append one node in oneHead
            oneTail->next=temp;
            oneTail=temp;

        }
        else if(curr->data==2){
            node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //append two node in twoHead
            twoTail->next=temp;
            twoTail=temp;
        }
    }
    //join them 
    //remove dummy nodes
    //modify one wali list
    node* temp = oneHead;
    oneHead = oneHead -> next;
    temp->next = NULL;
    delete temp;
    //two wali list
    temp = twoHead;
    twoHead=twoHead->next;
    temp->next=NULL;
    delete temp;

    //join list
    if(oneHead != NULL){
        //ONE WALI NON EMPTY
        zeroTail->next=oneHead;
        if(twoHead != NULL){
            oneTail->next=twoHead;
        }
    }
    else{
        // one wali list is empty
        if(twoHead != NULL)
            zeroTail = twoHead;
    }

    //remove zerohead dummy
    temp=zeroHead;
    zeroHead = zeroHead->next;
    temp->next=NULL;
    delete temp;

    return zeroHead;
}

int main(){
    node* n1 = new node(1);
    node* n2 = new node(2);
    node* n3 = new node(0);
    node* n4 = new node(0);
    node* n5 = new node(2);

    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    n4 -> next = n5;
    n5 -> next = NULL;

    print(n1);
    n1 = sortTwo(n1);
    print(n1);
}