#include<iostream>
#include<string>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
         int index = 0, count = 1;
         char prev = chars[0];

         for(int i=1; i<chars.size(); ++i){
            if(chars[i] == prev){
                count++; // increment count if same character is found
            }
            else{
                chars[index++] = prev; // store the character
                if(count > 1){
                    int start = index; //store index where count will be stored
                    while(count>0){
                        chars[index++] = (count%10) + '0'; //convert count to character
                        count/=10; //reduce count
                    }
                    reverse(chars.begin() + start, chars.begin() + index); 
                    }
                    prev = chars[i]; // update previous character 
                    count = 1; //reset count
                }
            }

            chars[index++] = prev; //store the last character
            if(count > 1){
                int start = index; //store index where count will be stored
                while(count > 0){
                    chars[index++] = (count % 10) + '0'; //convert count to character
                    count/=10; 
                } 
            reverse(chars.begin() + start, chars.begin() + index); 
            }
         return index; // return new length of compressed string
    }
};