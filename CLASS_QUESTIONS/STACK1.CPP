#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <stack>
using namespace std;

class Stack{

    private: //indexing cant be done
    int *arr;
    int top;
    int top1;
    int size; //show array size

    public:
    Stack(int size){
        arr = new int[size];
        this-> size = size;
        top = -1;
        top1 = size;
    }

    //functions
    void push(int data){
        // if(size-top>1){
        //     //space available
        //     //insert
        //     top++;
        //     arr[top]=data;
        // }
        // else{
        //     cout<< "stack overflow" << endl;
        // }

        if(top1-top == 1){
            cout<<"overflow" << endl;
        }
        else{
            top++;
            arr[top] = data;
        }
    }

    void push1(int data){
        if(top1-top == 1){
            cout<<"overflow" << endl;
        }
        else{
            top1--;
            arr[top1] = data;
        }
    }

    void pop(){
        if(top == -1){
            //stack empty
            cout << "stack underflow" << endl;
        }
        else{
            top--;
        }
    }

    void pop1(){
        if(top1 == size){
            //stack empty
            cout << "stack underflow" << endl;
        }
        else{
            top1++;
        }
    }

    int getTop(){
        if(top == -1){
            //stack empty
            cout << "no element is present" << endl;
        }
        else{
            return arr[top];
        }

    }

    //to return no of valid element in stack
    int getSize(){
        return top+1;
    }

    int isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

void printMiddle(Stack &st, int &totalSize){

    if(st.isEmpty()){
        return;
    }
    //base case
    if(st.getSize() == totalSize/2+1){
        cout << "middle element is: " <<st.getTop() << endl;
        return;
    }

    int temp = st.getTop();
    st.pop();

    //recursive call
    printMiddle(st, totalSize);

    //backtrack
    st.push(temp);
}
int main(){
    //creation
    //stack<int> st;
    Stack st(10);

    //insertion
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);

    st.pop();
    int totalSize = st.getSize();
    printMiddle(st,totalSize);


    // cout<< "element on top: " << st.top() <<endl;
    cout<< "element on top: " << st.getTop() <<endl;
    //cout<<"size of : "<< st.size() << endl;
    cout<<"size of : "<< st.getSize() << endl;

    //if(st.empty()){
    if(st.isEmpty()){
        cout<<"stack is empty" << endl;
    }
    else{
        cout << "stack is not empty" << endl;
    }

    string str = "dhruv";

    stack<char> s;
    for(int i = 0; i<str.length(); i++){
        s.push(str[i]);
    }

    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    cout << endl;

    return 0;
}