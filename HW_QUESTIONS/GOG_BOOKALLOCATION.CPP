#include<iostream>
#include<algorithm>
#include<vector>
#include <bits/stdc++.h> // for accumulate
using namespace std;

class Solution {
  public:

    bool isPossibleSolution(vector<int> &arr, int n, int k, int mid){
        int studentcount = 1; // start with one student
        int pagesum = 0; // sum of pages allocated to current student
        for(int i=0; i<n; i++){
            if(arr[i]> mid){
                return false; // if book has more pages than mid, not possible
            }
            if(pagesum + arr[i]> mid){
                studentcount++; // allocate to next student
                pagesum = arr[i]; // start new sum with current book
                if(studentcount > k){
                    return false; // if students exceed k, not possible
                }
            }
            else{
                pagesum += arr[i]; // add pages to current student
            }
        }
        return true; // if we can allocate within k students
    }

    int findPages(vector<int> &arr, int k) {
        // code here
        int m = arr.size();
        if(k> m){
            return -1; // not enough books to allocate
        }

        int start = 0;
        int end = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;
        while(start <= end){
            int mid = start + ((end - start) >> 1); // mid is max no of books a student can read
            if(isPossibleSolution(arr, m, k, mid)){
                ans = mid; // found a possible solution
                end = mid - 1; // try for smaller max pages
            }
            else{
                start = mid + 1; // try for larger max pages
            }
        }
        return ans;
    }
};