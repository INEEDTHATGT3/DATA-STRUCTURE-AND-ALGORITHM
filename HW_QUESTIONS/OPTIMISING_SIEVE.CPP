#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

vector<bool> Sieve(int n){
    //create sieve array of N size telling isPrime
    vector<bool>sieve(n+1, true);
    sieve[0] = sieve[1] = false;

    for(int i=2; i*i<=n; i++){
        if(sieve[i] == true){
            int j=i*i; //1st optimization asfirst unmarked no would be i*i, as others have been marked by 2 to (i-1)
            while(j<=n){
                sieve[j] = false;
                j+=i;
            }

        }
    }
    return sieve;
}

vector<bool> segSieve(int L, int R){
    //get me prime array, i will use it to mark sag sieve
    vector<bool>sieve = Sieve(sqrt(R));
    vector<int>basePrime;
    for(int i=0; i<sieve.size(); i++){
        if(sieve[i]){
            basePrime.push_back(i);
        }
    }

    vector<bool>segSieve(R-L+1, true);
    if(L==1 || L==0){
        segSieve[L] = false;
    }

    for(auto prime:basePrime){
        int first__mul = (L / prime) * prime;
        if(first__mul <L){
            first__mul += prime;
        }
        int j = max(first__mul, prime*prime);
        while(j <= R){
            segSieve[j- L] = false;
            j += prime;
        }
    }
    return segSieve;
}

int main(){
    // vector<bool>sieve=Sieve(25);
    // for(int i=0; i<=25; i++){
    //     if(sieve[i]){
    //         cout<<i<<" ";
    //     }
    // }

    int L = 110;
    int R = 200;
    vector<bool>ss = segSieve(L, R);
    for(int i=0; i<ss.size(); i++){
        if(ss[i]){
            cout<< i+L << " ";
        }
    }
    return 0;
}