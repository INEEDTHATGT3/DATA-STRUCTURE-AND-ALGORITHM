#include<iostream>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reorganizestring(string s){
        int hash[26] = {0}; // frequency of each character

        for(int i=0; i<s.size(); i++){
            hash[s[i] - 'a']++; //count freq of each character  
        }

        //find most frequent character
        char maxFreqChar;
        int max_freq = INT_MIN;
        for(int i=0; i<26; i++){
            if(hash[i] > max_freq){
                max_freq = hash[i];
                maxFreqChar = i + 'a';
            }
        }

        //check if most freq character can be placed
        int index = 0;
        while(max_freq > 0 && index < s.size()){
            s[index] = maxFreqChar; // places most frequent character
            max_freq--;
            index += 2; // place it at even indices
        }

        if(max_freq != 0){
            return "";
        }

        hash[maxFreqChar - 'a']= 0; // set freq of most frequent character to 0
        // now placing other characters
        for(int i= 0; i<26; i++){
            while(hash[i] > 0){
                while(hash[i] > 0){
                    index = index >= s.size() ? 1: index; // if index exceeds size, start from 1 
                    s[index] = i + 'a'; // place character at current index
                    index += 2; // move to next even index
                    hash[i]--;
                }
            }
        }
        return s; 
    }
};