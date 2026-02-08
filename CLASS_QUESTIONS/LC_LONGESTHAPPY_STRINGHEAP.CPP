#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
using namespace std;

class node{
    public: 
    char data;
    int count;

    node(char d, int c){
        data = d;
        count = c;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->count < b->count;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<node*, vector<node*>, compare> maxHeap;

        if(a > 0){
            maxHeap.push(new node('a', a));
        }
        if(b>0){
            maxHeap.push(new node('b', b));
        }

        if(c>0){
            maxHeap.push(new node('c', c));
        }

        string ans = "";

        while(maxHeap.size() > 1){
            node* first = maxHeap.top();
            maxHeap.pop();
            node* second = maxHeap.top();
            maxHeap.pop();

            if(first->count >= 2){
                ans += first->data;
                ans+= first->data;
                first->count -=2;
            }
            else{
                ans += first->data;
                first->count--;
            }

            if(second->count >= 2 && second->count >= first->count){
                ans += second->data;
                ans += second->data;
                second->count -= 2;
            }
            else{
                ans += second->data;
                second->count--;
            }

            if(first->count > 0){
                maxHeap.push(first);
            }

            if(second->count > 0){
                maxHeap.push(second);
            }
        }
        if(maxHeap.size() == 1){
            node* temp = maxHeap.top();
            maxHeap.pop();

            if(temp->count >= 2){
                ans += temp->data;
                ans += temp->data;
                temp->count -= 2;
            }
            else{
                ans += temp->data;
                temp->count--;
            }
        }
        return ans;
    }
};