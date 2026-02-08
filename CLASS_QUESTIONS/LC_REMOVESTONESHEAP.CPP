#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;
        for(int i=0; i<piles.size(); i++){
            maxHeap.push(piles[i]);
        }
        while(k--){
            int maxElement = maxHeap.top();
            maxHeap.pop();
            maxElement = maxElement - floor(maxElement/2);
            maxHeap.push(maxElement);
        }

        int sum = 0;
        while(!maxHeap.empty()){
            int temp = maxHeap.top();
            maxHeap.pop();
            sum += temp;
        }
        return sum;
    }
};