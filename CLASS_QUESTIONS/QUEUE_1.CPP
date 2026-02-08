#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
using namespace std;

class cirQueue{
    public:
    int size;
    int *arr;
    int front;
    int rear;

    cirQueue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data){
        //queue full
        //single element case -> first element
        //circular nature
        //normal flow
        //TODO: add one more condition to check full queue in circular
        if(front == 0 && rear == size-1){
            cout << "Q is full, cannot insert" << endl;
        }
        else if(front == -1){
            front = rear = 0;
            arr[rear] = data;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }

    void pop(){
        //empty check
        if(front == -1){
            cout << "Q is empty, cannot pop" << endl;
        }
        //single element 
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        //circular nature
        else if(front == size-1){
            front = 0;
        }
        //normal flow
        else{
            arr[front]= -1;
            front++;
        }
    }
};

class Deque{
    public:
    int size;
    int *arr;
    int front;
    int rear;

    Deque(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushRear(int data){
        //full eali puri karni hai
         if(front == 0 && rear == size-1){
            cout << "Q is full, cannot insert" << endl;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
    }
    arr[rear] = data;
    }

    void pushFront(int data){
        //full wali condition puri karni hai
        if(front == 0 && rear == size-1){
            cout << "Q is full, cannot insert" << endl;
            return;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if(rear != size-1 && front == 0){
            front = size-1;
        }
        else{
            rear++;
        }
    arr[rear] = data;
    }

    void popFront(){
         //empty check
        if(front == -1){
            cout << "Q is empty, cannot pop" << endl;
        }
        //single element 
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        //circular nature
        else if(front == size-1){
            front = 0;
        }
        //normal flow
        else{
            arr[front]= -1;
            front++;
        }
    }

    void popRear(){
         //empty check
        if(front == -1){
            cout << "Q is empty, cannot pop" << endl;
        }
        //single element 
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        //circular nature
        else if(rear == 0){
            rear = size-1;
        }
        //normal flow
        else{
            rear--;
        }
    }
};


class Queue{
    public: 
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data){
        if(rear == size){
            cout << "Q is full" << endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    void pop(){
        if(front == rear){
            cout<< "Q is empty" << endl;
        }
        else{
            arr[front] = -1;
            front++;
            if(front==rear) {
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront(){
        if(front == rear){
            cout << " Q is empty" << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    bool isempty(){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    int getSize(){
        return rear - front;
    }
};

int main(){
    //creation
    queue<int> q;
    Queue a(10);

    //insertion
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    a.push(53);
    a.push(154);
    a.push(255);
    a.push(556);
    //size
    cout<<"size of queue: " << q.size() << endl;
    cout<<"size of queue: " << a.getSize() << endl;

    if(q.empty()){
        cout << "queue is empty" << endl;
    }
    else{
        cout << "Q is not empty" << endl;
    }

    cout << "Front element is : " << q.front() << endl;
    
    a.pop();
    cout << "size of queue: "<< a.getSize() << endl;
    cout << "Front element is : " << a.getFront() << endl;
    return 0;
}