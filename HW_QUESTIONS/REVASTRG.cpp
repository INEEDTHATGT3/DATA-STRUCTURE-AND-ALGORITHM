#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void revStr(string& s, int start, int end){
    //base case
    if(start >= end){
        return;
    }

    //ek case
    swap(s[start], s[end]);

    revStr(s, start+1,end-1);
}

int main(){
    string s;
    cin >> s;

    revStr(s, 0, s.size()-1);
    cout<<s<<endl;
    return 0;
}