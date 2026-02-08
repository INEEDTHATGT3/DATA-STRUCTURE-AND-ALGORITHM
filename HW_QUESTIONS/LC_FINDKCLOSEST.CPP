#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:

    int lowerBound(vector<int>& arr, int x){
        int start = 0, end = arr.size()-1;
        int ans = end;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid] >= x){
                ans=mid;
                end =mid-1;
            }
            else if(x>arr[mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
    vector<int> binarySearchMethod(vector<int>& arr, int k, int x){
        //lower bound
        int h= lowerBound(arr, x);
        int l = h-1;
        while(k--){
            if(l<0){
                h++;
            }
            else if(h >=arr.size()){
                l--;
            }
            if(x-arr[l]> x- arr[h]){
                h++;
            }
            else{
                l-- ;
            }
        }
        vector<int> ans;
        for(int i= l; i<= h; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return binarySearchMethod(arr, k ,x);
    }

    // vector<int> twoPointerMethod(vector<int>& arr, int k, int x){
    //     int l = 0, h= arr.size()-1;
    //     while(h-l >= k){
    //         if(abs(arr[l]-x)> abs(arr[h]-x)){
    //             l++;
    //         }
    //         else{
    //             h-- ;
    //         }
    //     }
    //     return vector<int>(arr.begin(), arr.begin()+h+1);
    // }
    
    // vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    //     return twoPointerMethod(arr, k ,x);
    // }
};