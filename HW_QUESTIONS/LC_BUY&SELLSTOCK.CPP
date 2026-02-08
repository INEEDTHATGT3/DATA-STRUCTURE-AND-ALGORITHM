#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    void maxProfitFinder(vector<int>& prices, int i, int& minPrice, int& maxProfit){
        //base case
        if(i == prices.size()){
            return;
        }

        // 1 solution
        if(prices[i] < minPrice){
            minPrice = prices[i];
        }
        int todaysProfit = prices[i] - minPrice;
        if(todaysProfit > maxProfit)
            maxProfit = todaysProfit;
        //recursive function
        maxProfitFinder(prices, i+1, minPrice, maxProfit);
    }

    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxprofit = INT_MIN;
        maxProfitFinder(prices, 0, minPrice, maxprofit);
        return maxprofit;
    }
};