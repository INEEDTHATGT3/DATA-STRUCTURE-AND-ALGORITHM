#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<stack>
using namespace std;

vector<int> prevSmallerElement(vector<int> &input){
    stack<int> s;
    s.push(-1);
    vector<int> ans(input.size());

    for(int i=0; i<input.size(); i++){
        int curr = input[i];
        //answer stack me hai
        while(s.top() >= curr){
            s.pop();
        }
        //chota element met -> ans store
        ans[i] = s.top();
        //push kardiya current element stack mai
        s.push(curr);
    }
    return ans;
}

vector<int> nextSmaller(vector<int> &input){
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());
    for(int i=input.size()-1; i>=0; i--){
        int curr = input[i];
        //answer stack me hai
        while(s.top() >= curr){
            s.pop();
        }
        //chota element met -> ans store
        ans[i] = s.top();
        //push kardiya current element stack mai
        s.push(curr);
    }
    return ans;
}

int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    vector<int> ans1 = nextSmaller(v);
    cout<< "printing ans1" << endl;

    for(int i=0; i<v.size(); i++){
        cout << ans1[i] << " ";
    }cout << endl;

    vector<int> ans2 = prevSmallerElement(v);
    cout << "printing ans2" << endl;
    for(int i=0; i<v.size(); i++){
        cout<< ans2[i] << " ";
    }cout << endl;

    return 0;
}