#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int solve(vector<int>& arr, int target){
    //base case
    if(target == 0){
        return 0;
    }
    if(target < 0){
        return INT_MAX;
    }

    //let's solve 1 case
    int mini = INT_MAX;
    for(int i=0; i<arr.size(); i++){
        int ans = solve(arr, target-arr[i]);
        if(ans != INT_MAX) //if ans = int_max then invalid
        mini = min(mini, ans+1); //1 element is used so update ans
    }

    return mini;
}

int solve1(int n, int x, int y, int z){
// base case
if(n == 0)
    return 0;

if(n<0){
    return INT_MIN;
}

int ans1 = solve1(n-x, x, y, z) +1;
int ans2 = solve1(n-y, x, y, z) +1;
int ans3 = solve1(n-z, x, y, z) +1;

int ansa = max(ans1, max(ans2, ans3));
return ansa;
}

void solve2(vector<int>& arr1,int i, int sum, int& maxi){
    //base case 
    if(i>= arr1.size()){
        //maxi update
        maxi = max(sum, maxi);
        return;
    }

    //include
    solve2(arr1, i+2, sum +arr1[i], maxi);
    //exclude
    solve2(arr1, i+1, sum, maxi);
}

int main(){
    //adobe wala question
    vector<int> arr{1,2};
    int target = 5;

    int ans = solve(arr,target);
    cout << "answer is: " << ans << endl;

    //cut into segments
        int n = 8;
        int x = 6;
        int y = 4;
        int z = 2;

    //solve function -> returns maximum no of segments
    int ansa = solve1(n, x, y, z);
    if(ansa < 0){
        ansa = 0;
    }
    cout << "answer is: " << ansa << endl;

    // maximum sum of non adjacent element
    vector<int> arr1{2,1,4,9};
    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;
    solve2(arr1, i, sum, maxi);

    cout << maxi << endl;
    return 0;
}