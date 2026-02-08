#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printSubArr(vector<int>& nums, int start, int end){
    //base case

    if(end == nums.size()){
        return;
    }

    //1 case sol
    for(int i= start; i<=end; i++){
        cout<<nums[i]<< " ";
    }
    cout << endl;

    //recursive case
    printSubArr(nums, start, end+1);
}

void printSubArr_util(vector<int>& nums){
    for(int i = 0; i<nums.size(); i++){
        printSubArr(nums, i, i);
    }
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    printSubArr_util(nums);
    return 0;
}