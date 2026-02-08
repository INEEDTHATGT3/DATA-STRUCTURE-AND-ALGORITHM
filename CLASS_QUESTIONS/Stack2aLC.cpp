#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i<s.length();i++){
            char ch = s[i];

            //opening bracket
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                //closing bracket
                if(st.empty()){
                    return false;
                }
                char topCh = st.top();
                if(ch == ')' && topCh == '('){
                    st.pop();
                }
                else if(ch == ']' && topCh == '['){
                    st.pop();
                }
                else if(ch == '}' && topCh == '{'){
                    st.pop();
                }
                else{
                    //brackets not matching
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
