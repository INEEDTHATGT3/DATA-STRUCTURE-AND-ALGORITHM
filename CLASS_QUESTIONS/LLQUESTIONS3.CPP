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

void print(node* n1){
    node* temp = n1;
    while(temp != nullptr){
        cout << temp-> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

node* getMiddle(node* &n1){
    if(n1 == NULL){
        cout << "LL is empty";
        return n1;
    }
    if(n1->next == NULL){
        //only 1 node in LL
        return n1;
    }

    node* slow = n1;
    node* fast = n1 ->next;//next included for 3 in even case 

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

int getLength(node* n1){
    int len = 0;
    node* temp = n1;
    while(temp != NULL){
        temp = temp -> next;
        len++;
    }

    return len;
}
node* reverseKNode(node* &n1, int k){
    if(n1 == NULL){
        cout << "LL is empty" << endl;
        return NULL;
    }
    int len = getLength(n1);
    if(k >len){
        //cout << "enter valid value for k" << endl;
        return n1;
    }

    //it means number of node in LL is >= k
    //step 1
    node* prev = NULL;
    node* curr = n1;
    node* forward = curr -> next;
    int count = 0;

    while(count < k){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    //step 2
    if(forward != NULL){
        //still have node left
        n1 -> next =reverseKNode(forward, k);
    }
    // step 3
    return prev;
}

bool checkForLoop(node* &n1){
    if(n1 == NULL){
        cout << "LLis empty" << endl;
        return false;
    }

    node* slow = n1;
    node* fast = n1;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast -> next;
            slow = slow -> next;
        }

    if(slow == fast){
        //loop present 
        return true;
    }
}
return false;
}

bool startingPointLoop(node* &n1){
    if(n1 == NULL){
        cout << "LLis empty" << endl;
        return NULL;
    }

    node* slow = n1;
    node* fast = n1;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast -> next;
            slow = slow -> next;
        }

    if(slow == fast){
        slow = n1;
        break;
    }
}
node* prev = fast;
while (slow != fast){
    slow = slow->next;
    fast = fast->next;
}
prev->next=NULL;
}


int main(){
    node* n1 = new node(10);
    node* n2 = new node(20);
    node* n3 = new node(30);
    node* n4 = new node(40);
    node* n5 = new node(50);
    node* n6 = new node(60);
    node* n7 = new node(70);
    node* n8 = new node(80);

    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    n4 -> next = n5;
    n5 -> next = n6;
    n6 -> next = n7;
    n7 -> next = n8;
    n8 -> next = n4;

    //print(n1);
    cout << "middle node is: " << getMiddle(n1) -> data << endl;
    n1 = reverseKNode(n1, 2);
    //print(n1);
    cout << "loop is present or not" << checkForLoop(n1);
    cout << "starting point of LOOP is: " << startingPointLoop(n1)<<endl;  
    return 0;
}
