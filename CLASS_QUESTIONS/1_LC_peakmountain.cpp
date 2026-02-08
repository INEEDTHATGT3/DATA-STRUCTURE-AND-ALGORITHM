#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//peak index in mountain array
class Solution {
public:
int findPeakIndex(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid + 1]) {
            start = mid + 1; // Move to the right half
        } else {
            end = mid; // Move to the left half
        }
        mid = start + (end - start) / 2; // Update mid after changing start or end
    }
    return start; // or end, both will be the peak index
}

int peakIndexInMountainArray(vector<int>& arr) {
    return findPeakIndex(arr);
}
};