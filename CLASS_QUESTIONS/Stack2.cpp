#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<stack>
using namespace std;

void solve(stack<int> &s, int target){
    //base case
    if(s.empty()){
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();
    //rec call 
    solve(s, target);
    //backtrack
    s.push(topElement); 
}

void insertAtBottom(stack<int> &s){

    int target = s.top();
    s.pop();
    solve(s,target);
}

void reverseStack(stack<int> &s){
    //base case
    if(s.empty()){
        return;
    }
    //hindi steps 
    int target = s.top();
    s.pop();

    //reverse stack 
    reverseStack(s);
    //insert at bottom target ko
    insertAtBottom(s);
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    
    insertAtBottom(s);
    reverseStack(s);

    cout<<"printing" << endl;
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl; 
    return 0;
}