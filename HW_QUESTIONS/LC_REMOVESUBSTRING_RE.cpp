#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void removeOccRE(string& s, string& part){
        int found = s.find(part);
        if(found != string::npos){
            //base case

            //part string found ,remove
            string left = s.substr(0, found);
            string right = s.substr(found + part.size(), s.size());
            s = left + right;
            // recursion
            removeOccRE(s, part);
        }

        // part string not found , base case
        else{
            return;
        }
    }
    
    string removeOccurrences(string s, string part) {
         removeOccRE(s,part);
         return s;
    }
};