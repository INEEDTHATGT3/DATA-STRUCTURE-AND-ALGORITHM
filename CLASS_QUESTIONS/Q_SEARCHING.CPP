#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int firstOccurence(vector<int> v, int target) {
    int start = 0;
    int end = v.size() - 1;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (v[mid] == target) {
            ans = mid; // Found the target, but continue searching to the left
            end = mid - 1; // Move to the left half
        } else if (v[mid] < target) {
            start = mid + 1; // Search in the right half
        } else {
            end = mid - 1; // Search in the left half
        }
        mid = start + (end - start) / 2; // Update mid after changing start or end
    }
    return ans; // Return the index of the first occurrence or -1 if not found
}

int lastOccurence(vector<int> v, int target) {
    int start = 0;
    int end = v.size() - 1;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (v[mid] == target) {
            ans = mid; // Found the target, but continue searching to the right
            start = mid + 1; // Move to the right half
        } else if (v[mid] < target) {
            start = mid + 1; // Search in the right half
        } else {
            end = mid - 1; // Search in the left half
        }
        mid = start + (end - start) / 2; // Update mid after changing start or end
    }
    return ans; // Return the index of the last occurrence or -1 if not found
}
 
int main() {
    vector<int> v{1,3,4,4,4,4,6,7};
    int target = 4;
    // Function to find the first occurrence of a target in a sorted vector (BY BINARY SEARCH)
    
    //int indexOfFirstoccurrence = firstOccurence(v , target);
    //cout << "First occurrence of " << target << " is at index: " << indexOfFirstoccurrence << endl;

    // predefined function to find the first occurrence of a target in a sorted vector (BY BINARY SEARCH)
    int indexOfFirstoccurrence = lower_bound(v.begin(), v.end(), target) - v.begin();
    cout << "First occurrence of " << target << " is at index: " << indexOfFirstoccurrence << endl;
    
    // Function to find the last occurrence of a target in a sorted vector (BY BINARY SEARCH)
    
    //int indexofLastOccurrence = lastOccurence(v, target);
    //cout << "Last occurrence of " << target << " is at index: " << indexofLastOccurrence << endl;

    // predefined function to find the last occurrence of a target in a sorted vector (BY BINARY SEARCH)
    int indexofLastOccurrence = upper_bound(v.begin(), v.end(), target) - v.begin() - 1;
    cout << "Last occurrence of " << target << " is at index: " << indexofLastOccurrence << endl;

    // Count of occurrences of the target in the vector
    int count = indexofLastOccurrence - indexOfFirstoccurrence + 1;
    cout << "Count of occurrences of " << target << " is: " << count << endl;
    
    //peak element in mountain array
    vector<int> mountainArray{1, 3, 5, 7, 9, 8, 6, 4, 2};
    
    
}