#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
using namespace std;

string solve(string str){
     int freq[26]={0};
    queue<char> q;

    string ans = " ";

    for(int i =0; i<str.length(); i++){
        char ch = str[i];

        //increment frequency
        freq[ch - 'a']++;
        //q.push
        q.push(ch);

    while(!q.empty()){
        if(freq[q.front() - 'a'] > 1){
            q.pop();
        }
        else{
            ans.push_back(q.front());
            break;
        }
    }
    if(q.empty()){
        ans.push_back('#');
    }
    }
    cout << "ans is: " << ans << endl;
    return ans;
}

int main(){
    string str = "aabc";
    solve(str);
    return 0;    
}