#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<stack>
#include<climits>
using namespace std;

vector<int> prevSmallerElement(vector<int> &input){
    stack<int> s;
    
    s.push(-1);
    vector<int> ans(input.size());

    for(int i=0; i<input.size(); i++){
        int curr = input[i];
        //answer stack me hai
        while(s.top() != -1 && input[s.top()] >= curr){
            s.pop();
        }
        //chota element met -> ans store
        ans[i] = s.top();
        //push kardiya current element stack mai
        s.push(i);
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
        while(s.top() != -1 && input[s.top()] >= curr){
            s.pop();
        }
        //chota element met -> ans store
        ans[i] = s.top();
        //push kardiya current element stack mai
        s.push(i);
    }
    return ans;
}

int getrectangularAreaHistogram(vector<int> &height){

    // step 1 prevsmaller output
    vector<int> prev = prevSmallerElement(height);

    //step 2 nextSmaller(height);
    vector<int> next = nextSmaller(height);

    int maxArea = INT_MIN;

    for(int i=0; i<height.size(); i++){
        int length = height[i];

        if(next[i] == -1){
            next[i] = height.size();
        }
        int width = next[i] - prev[i] - 1;

        int area = length * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
    }
};