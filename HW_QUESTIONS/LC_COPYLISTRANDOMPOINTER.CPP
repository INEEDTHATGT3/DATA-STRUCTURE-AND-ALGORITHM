#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:

   Node* copyRandomList(Node* head) {
        if(!head) return 0;

        //step 1: clone A -> A*
        Node* it = head;
        while(it){
            Node* clonedNode = new Node(it->val);
            clonedNode->next = it->next;
            it->next = clonedNode;
            it = it->next->next;
        }

        //step 2 update random pointers
        it = head;
        while(it){
            Node* clonedNode = it->next;
            clonedNode->random = it->random ?it->random->next : nullptr;
            it = it->next->next;
        }

        //step 3: detach A* and A
        it = head;
        Node*clonedHead = head->next;
        while(it){
            Node* clonedNode = it->next;
            it->next = it->next->next;
            if(clonedNode->next){
            clonedNode->next = clonedNode->next->next;
            }
            it = it->next;
        }
        return clonedHead;
    }
};