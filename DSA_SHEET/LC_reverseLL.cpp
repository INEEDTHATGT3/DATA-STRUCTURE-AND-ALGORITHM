#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
#include<limits.h>
using namespace std;

struct ListNode {
    int val;
   ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // //base case
        // if(head == NULL || head->next == NULL){
        //     return head;
        // }

        // //recursive call
        // ListNode* newHead = reverseList(head->next);

        // // solving q case
        // head->next->next = head;
        // head->next = NULL;

        // return newHead;

        //iterative qpproach : sliding window pointer
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL){
            next== curr->next; // save next node
            curr->next = prev; // reverse link
            prev = curr; // move prev forward
            curr = next; // move curr forward
        }
        return prev; // new head of reverse list
    }
};