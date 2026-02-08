#include <iostream>
#include <vector>
using namespace std;

bool checkSorted(vector<int> &v, int& n, int i){
// base case
    if(i == n-1){
        return true;
    }

    // 1case humra
    if(v[i+1] < v[i]){
        return false;
    }
    // baaki recursion
    return checkSorted(v, n ,i+1);
}

int binarySearch(vector<int> &v, int& s, int& e, int& key){
    //base case
    //case 1 key not found
    if(s > e)
    return -1;

    int mid = s + (e-s)/2;
    //case 2 key found
    if(v[mid] == key)
        return mid;
    
    //arr[mid] < key -> right me
    if(v[mid] < key){
        s = mid+1;
        return binarySearch(v, s, e, key); //mid+1 ismai likhege toh s become non constant hence can't be pass by refrence
    }
    else{
        e = mid-1;
        return binarySearch(v, s, e, key); //mid-1 ismai likhege toh e become non constant hence can't be pass by refrence
    }
}

void printSubSequences(string str, string output, int i, vector<string> &k){
    //base case
    if(i >= str.length()){
        k.push_back(output);
        //cout << output << endl;
        return;
    }

    //EXCLUDE
    printSubSequences(str, output, i+1, k);

    //INCLUDE note- include used below exclude because character daalne ke baad nikalna bhi padega
    output.push_back(str[i]);
    printSubSequences(str, output, i+1, k);
}

int main(){
    vector<int> v{10,20,30,40,60,70,80,90,99};
    int n = v.size();
    int i = 0;
    int target = 90;

    bool isSorted = checkSorted(v, n, i);

    if(isSorted){
        cout << "array is sorted" << endl;
    }
    else{
        cout << "array is not sorted" << endl;
    }

    int s = 0;
    int e = n-1;
    int ans = binarySearch(v, s, e, target);

    cout << "answer is: " << ans << endl;

    //subsequene of string
    string str = "abc";
    string output = " ";
    vector<string> k;

    printSubSequences(str, output, i, k);
    for(auto val: k ){
        cout << val << " ";
    }
    return 0;
}