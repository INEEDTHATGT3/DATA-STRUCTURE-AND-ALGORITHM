#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<stack>
using namespace std;

class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            char curr = s[i];
            if(curr == '(' || curr == '+' || curr == '-' || curr == '*' || curr == '/'){
                st.push(curr);
            }
            else if(curr == ')'){
                bool isRedundant = true;
                while(!st.empty() && st.top()!='('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();  // Remove '('
                }
                if(isRedundant){
                    return true;
                }
            }
        }
        return false;
    }
};
