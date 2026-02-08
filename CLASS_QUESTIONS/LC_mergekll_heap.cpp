#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class compare{
  public:
  bool operator()(ListNode* a, ListNode* b){
    return a->val > b->val;
  }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        //first k elements insert in minHeap
        int k = lists.size();
        if(k == 0){
          return NULL;
        }

        //insert first element of each list
        for(int i=0; i<k; i++){
          if(lists[i] != NULL){
            minHeap.push(lists[i]);
          }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!minHeap.empty()){
          ListNode* temp = minHeap.top();
          minHeap.pop();

          // temp can be first element of answer linked list
          if(head == NULL){
            //temp-> first element
            head = temp;
            tail = temp;
          }
          else{// temp not first element
              tail->next = temp;
              tail = temp;
            }
            if(tail->next != NULL){
                minHeap.push(tail->next);
            }
        }
        return head;
    }
};