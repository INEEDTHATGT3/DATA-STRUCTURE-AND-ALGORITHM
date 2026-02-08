#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
   // vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //using map and sorting 
        // map<string, vector<string>> mp;

        // // iterate through each string in input vector
        // for(auto str:strs){
        //     string s = str; // make a copy of string
        //     sort(s.begin(), s.end()); // sort string for key
        //     mp[s].push_back(str); // add original string to map with sorted string as key
        // }

        // vector<vector<string>> ans; // vector to hold grouped anagrams
        // for(auto it= mp.begin(); it !=mp.end(); it++){
        //     ans.push_back(it->second); //push back vector of anagrams to answer vectors
        // }
        // return ans; // return grouped anagrams

        std::array<int, 256> hash(string s){
            std::array<int, 256>hash = {0};
            for(int i=0; i<s.size(); i++){
                hash[s[i]]++;
            }
            return hash;
        }

        vector<vector<string>> groupAnagrams(vector<string>& strs){
            map<std::array<int, 256>, vector<string>> mp;
        // iterate through each string in input vector
        for(auto str:strs){
            mp[hash(str)].push_back(str); // add original string to map with sorted string as key
        }

        vector<vector<string>> ans; // vector to hold grouped anagrams
        for(auto it= mp.begin(); it !=mp.end(); it++){
            ans.push_back(it->second); //push back vector of anagrams to answer vectors
        }
        return ans; // return grouped anagrams
    }
};