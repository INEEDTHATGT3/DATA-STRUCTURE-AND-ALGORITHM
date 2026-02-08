#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    void countArrHelper(vector<int>& v, int n, int& ans, int currNum){
        // base
        if(currNum == n+1){
            for(int i=1; i<=n; i++){
                cout<<v[i]<< " ";
            }
            cout<<endl;
            ++ans;
            return;
        }

        for(int i=1; i<=n; ++i){
            if(v[i] == 0 && (currNum % i == 0 || i % currNum == 0)){
                v[i] = currNum;
                countArrHelper(v, n, ans, currNum+1);
                v[i] = 0; 
            }
        }
    }
    int countArrangement(int n) {
        vector<int> v(n+1);
        int ans = 0;
        countArrHelper(v, n, ans, 1);
        return ans;
        
    }
};