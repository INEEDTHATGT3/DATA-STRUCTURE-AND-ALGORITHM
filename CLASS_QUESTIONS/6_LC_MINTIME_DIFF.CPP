#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
    //     vector<int> minutes;

    //     for(int i=0; i<timePoints.size(); i++){
    //     string curr = timePoints[i];

    //     int hours = stoi( curr.substr(0,2));
    //     int mins = stoi(curr.substr(3,2));
    //     int totalMinutes = hours*60 + mins;
    //     minutes.push_back(totalMinutes);
    //     }

    //     // sort the minutes vector
    //     sort(minutes.begin(), minutes.end());

    //     // calculate diffrence
    //     int mini = INT_MAX;
    //     int n = minutes.size();

    //     for(int i =0; i<n; i++){
    //         int diff = minutes[i] - minutes[i-1];
    //         mini = min(mini, diff);
    //     }
    //     // check for circular difference
    //    int lastdiff = (minutes[0] + 1440) - minutes[n-1];
    //     mini = min(mini, lastdiff);
    //     return mini;

     vector<int> minutes;
        
        for(int i=0; i<timePoints.size(); i++){
            string curr = timePoints[i];
            
            int hours = stoi(curr.substr(0,2));
            int mins = stoi(curr.substr(3,2));
            int totalMinutes = hours*60 + mins;
            minutes.push_back(totalMinutes);
        }
        
        // Sort the minutes vector
        sort(minutes.begin(), minutes.end());
        
        // Find minimum difference
        int minDiff = INT_MAX;
        for(int i=1; i<minutes.size(); i++){
            minDiff = min(minDiff, minutes[i] - minutes[i-1]);
        }
        
        // Check circular difference (between last and first time)
        int circularDiff = (minutes[0] + 1440) - minutes[minutes.size()-1];
        minDiff = min(minDiff, circularDiff);
        
        return minDiff;
    }
};