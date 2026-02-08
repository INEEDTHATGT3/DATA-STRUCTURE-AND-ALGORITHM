#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

long merge(vector<int> &arr, vector<int> &temp, int start, int mid, int end){
    int i = start, j = mid+1, k = start;
    long c = 0;
    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            c += (mid-i+1); //count inversions
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=end){
        temp[k++] = arr[j++];
    }
    while(start<=end){
        arr[start] = temp[start];
        ++start;
    }
    return c;
}
long mergeSort(vector<int> &arr, vector<int> &temp, int start, int end){
    if(start >= end) return 0;
    int mid = start + (end-start)/2;
    long c = 0;

    c += mergeSort(arr, temp, start, mid);
    c += mergeSort(arr, temp, mid+1, end);
    c += merge(arr, temp, start, mid, end);
    return c;
}

long countInversions(vector<int> arr) {
    long c = 0; // to count inversions
    vector<int> temp(arr.size(), 0);
    c = mergeSort(arr, temp, 0, arr.size() - 1);
    return c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
