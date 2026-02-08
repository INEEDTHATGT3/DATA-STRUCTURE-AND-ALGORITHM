#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    int mincostTickets_helper(vector<int>& days, vector<int>& costs, int i){
        //base case
        if(i>= days.size()) return 0;

        //sol of one case
        // 1 day pass 
        int cost1 = costs[0] + mincostTickets_helper(days, costs, i+1);

        // 7 day pass
        int passEndDay7 = days[i] + 7 - 1;
        int j7 = i;
        while(j7 < days.size() && days[j7] <= passEndDay7){
            j7++;
        }
        int cost7 = costs[1] + mincostTickets_helper(days, costs, j7);

        // 30 day pass
        int passEndDay30 = days[i] + 30 - 1;
        int j30 = i;
        while(j30 < days.size() && days[j30] <= passEndDay30){
            j30++;
        }
        int cost30 = costs[2] + mincostTickets_helper(days, costs, j30);

        return min(cost1, min(cost7, cost30));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return mincostTickets_helper(days, costs, 0);
    }
};