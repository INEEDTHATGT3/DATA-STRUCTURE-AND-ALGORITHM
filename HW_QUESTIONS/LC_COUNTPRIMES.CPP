#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// sqrt approach 
// bool isPrime(int n){
//     if(n <= 1) return false; // 0 and 1 are not prime numbers
//     int sqrtN = sqrt(n);
//     for(int i = 2; i <= sqrtN; i++){
//     if(n % i == 0){
//         return false;
//     }
//     }
//     return true;
// }
// time complexity: O(sqrt(n))

class Solution {
public:
    int countPrimes(int n) {
        // int count = 0;
        // for(int i = 2; i <= n; i++){
        //     if(isPrime(i)){
        //         ++count;
        //     }
        // }
        // return count;

        // sieve of eratosthenes approach
        if (n == 0) return 0;

        vector<bool> prime(n , true);
        prime[0] = prime[1] = false; 

        int ans = 0;

        for(int i=2; i<n; i++){
            if(prime[i]){
                ans++;

                int j=2*i; 
                while(j<n){
                    prime[j] = false;
                    j += i; // mark all multiples of i as non prime
                }
            }
        }
        return ans; 
    }
};