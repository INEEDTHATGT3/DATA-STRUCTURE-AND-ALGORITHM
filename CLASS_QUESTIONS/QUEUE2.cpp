#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
using namespace std;

void interLeaveQueue(queue<int> &q){
    //step A 
    int n = q.size();
    if(q.empty()){
        return;
    }
    int k = n/2;
    int count = 0;
    queue<int> q2;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        q2.push(temp);
        count++;

        if(count == k){
            break;
        }
    }

    // step B interleaving
    while((!q.empty()) && (!q2.empty())){
        int first = q2.front();
        q2.pop();

        q.push(first);

        int second = q.front();
        q.pop();

        q.push(second);
    }
    //odd wala case
    if(n&1){ //n&1 means n is odd
        int element = q.front();
        q.pop();
        q.push(element);
    }
}
void reverseK(queue<int> &q, int k){
    //step A queue -> kelement -> stack
    stack<int> s;
    int count = 0;
    int n = q.size();

    if(k==0 || k>n){
        return;
    }

    while(!q.empty() && count <k){
        int temp = q.front();
        q.pop();
        s.push(temp);
        count++;

        if(count == k){
            break;
        }
    }

    //step B stack -> q me wapas
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    //step c: push n-k element from q front to back
    count = 0;
    while(!q.empty() && n-k >0){
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;

        if(count == n-k)
            break;
    }
}

void reverseQueue(queue<int> &q){
    stack<int> s;

    //step 1 : put all elements of q into s 
    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }

    //step 2:put all elemnt from stack into q
    while(!s.empty()){
        int element = s.top();
        s.pop();

        q.push(element);
    }
}

void reverseQueueRE(queue<int> &q){
    //base case
    if(q.empty()){
        return;
    }
    //step 1
    int temp = q.front();
    q.pop();

    //step 2
    reverseQueueRE(q);
    //step 3
    q.push(temp);
}

void solve_SW(int arr[], int n, int k){
    deque<int> q;
    
    //process first window of size k
    for(int i=0; i<k; i++){
        if(arr[i] < 0){
            q.push_back(i);
        }
    }

    //remaining window ko precess kro
    for(int i=k; i<n; i++){
        //answer dedo purani window ka
        if(q.empty()){
            cout << 0 << " ";
        }
        else{
            cout << arr[q.front()] << " ";
        }

        // out of window element remove kro
        while(!q.empty() && (i - q.front() >=k)){
            q.pop_front();
        }

        //new element ko add kro
        if(arr[i]<0){
            q.push_back(i);
        }

        //last window
        if(q.empty()){
            cout << 0 << " ";
        }
        else{
            cout << arr[q.front()] << " ";
        }
    }
}

int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    int arr[] {12,-1,-7,8,-15,30,16,20};
    int size = 8;
    int k = 3;
    solve_SW(arr,size,k);

    reverseQueue(q);
    reverseK(q,4);
    interLeaveQueue(q);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}