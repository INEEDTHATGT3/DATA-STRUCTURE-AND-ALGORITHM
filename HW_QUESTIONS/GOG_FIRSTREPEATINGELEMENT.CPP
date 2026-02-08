#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Function to find the first repeating element in an array
    int firstRepeated(int a[], int n) {
        // Optimized solution using a hash map
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) {
            hash[a[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (hash[a[i]] > 1) {
                return i + 1; // Return the 1-based index of the first repeating element
            }
        }
        return -1; // Return -1 if no repeating element is found
    }
};