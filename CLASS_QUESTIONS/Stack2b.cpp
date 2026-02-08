#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<stack>
using namespace std;

void insertSorted(stack<int> &s,int target){
    //base case
    if(s.empty()){
        s.push(target);
        return;
    }
    if(s.top()>= target){
        s.push(target);
        return;
    }

    //step a
    int topElement= s.top();
    s.pop();
    insertSorted(s,target);

    //bt
    s.push(topElement);
}

void sortStack(stack<int> &s){
    //base case
    if(s.empty()){
        return;
    }

    int topElement = s.top();
    s.pop();
    
    sortStack(s);

    insertSorted(s,topElement);
}

int main(){
    stack<int> s;
    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);

    sortStack(s);

    cout<<"printing" << endl;
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl; 
    return 0;

}