#include<iostream>
#include <climits>
#include <string>
#include <vector>
using namespace std;

int climbStairs(int n){
    // base case - stopping condition
    if(n == 0 || n == 1)
    return 1;

    int ans = climbStairs(n-1)+ climbStairs(n-2);
    return ans;
}

void print(int arr[], int n, int i){
    // base case
    if(i >= n){
        return;
    }

    //bigger problem
    cout << arr[i] << " ";
    // baaki recursion bhaiiii
    print(arr, n, i+1);
}

void findMaxi(int arr1[], int n1, int l, int& maxi){
    // base case
    if(l >= n1){
        // array agar katm, toh wapas ajao
        return;
    }

    //1 case hum solve karege, baaki recursion sambhal lega
    if(arr1[l] > maxi ){
        maxi = arr1[l];
    }

    findMaxi(arr1, n1, l+1, maxi);
}

void findMini(int arr1[], int n1, int l ,int& mini){
    if(l >= n1){
        return;
    }

    if(arr1[l]< mini){
        mini = arr1[l];
    }

    findMini(arr1, n1,l+1, mini);
}

void checkKey(string& str, int i1, int& n2, char& key, vector<int>& ansvec){ // add int& count
    //base case 
    if(i1 >= n2){
        return; // not found 
    }
    //1 case hum, baaki recursion
    if(str[i1] == key){
        ansvec.push_back(i1);
        // count++;
    }

    checkKey(str, i1+1, n2, key, ansvec);  //add count
}

void printDigits(int n){
    // base case 
    if(n == 0){
        return;
    }

    //recursion ka nara
     int newValueOfN = n/10;
     printDigits(newValueOfN);
     
    int digit = n % 10;
    cout << digit << " ";
   
}

int main(){
    int k;
    cout << "enter the value of n" << endl;
    cin >> k;

    int ans = climbStairs(k);
    cout << "answer is : " << ans << endl;

    //printng array with recursion
    int arr[5] = {10, 20 ,30, 40, 50};
    int n = 5;
    int i = 0;
    print(arr, n ,i);
    cout << endl;

    int arr1[] = {10,30,21,32,56,54,90,53}; // replaced 56.43 with 56
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    int maxi = INT_MIN;
    int mini = INT_MAX;

    int l = 0;
    findMaxi(arr1, n1, l, maxi);
    cout<< "max no is: " << maxi << endl;
    findMini(arr1, n1, l, mini);
    cout << "min no is: " << mini << endl;

    string str = "bobobhai";
    int n2 = str.length();

    char key = 'h';

    int i1 = 0;
    vector<int> ansVec;
    // int count = 0;

    checkKey(str, i1, n2, key, ansVec);// add count
    cout << "printing ans" << endl;
    for(auto val: ansVec){
        cout << val << " ";
    }
    cout << endl;
    //cout << count << endl;

    int n4 = 647;
    printDigits(n4);

    return 0;
}