#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;

bool cmp(char first, char second){
    return first > second; //descending order
}

bool compare(int first,int second){
    return first > second;
}

int main(){
    string s = "dhruv";
    sort(s.begin(), s.end(), cmp);

    vector<int> v{5,3,1,4,2};
    sort(v.begin(), v.end(), compare);
    for(auto i:v){
        cout << i << " ";
    }

    cout << s << endl;
    
    // creation of map
    map<int, char> meramap;
    meramap[0] = 'a';
    meramap[1] = 'b';
    meramap[25] = 'z';
    cout << "ans is: " << meramap[23] << endl;
    return 0;
}