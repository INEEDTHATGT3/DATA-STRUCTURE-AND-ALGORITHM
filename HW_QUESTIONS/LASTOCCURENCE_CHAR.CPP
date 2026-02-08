#include<iostream>
#include<string>
using namespace std;

void lastOccltor(string& s, char x, int i, int& ans){
    //base case
    if(i >= s.size()){
        return;
    }
    //ek case solution
    if(s[i] == x){
        ans = i;
    }
    lastOccltor(s, x, i+1, ans);
}

void lastOccltor(string&s, char x, int i, int& ans){
    //base case
    if(i<0){
        return;
    }
    // ek case solution
    if(s[i] == x){
        ans = i;
        return;
    }
    lastOccltor(s,x,i-1,ans);
}

int main(){
    string s;
    cin >> s;

    char x;
    cin>>x;

    int ans = -1;
//    lastOccltor(s, x, 0, ans);
    lastOccltor(s, x, s.size()-1, ans);
    cout<<ans<<endl;
}
