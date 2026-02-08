#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isSafe(int i, int j, int n, vector<vector<int>>& m, vector<vector<int>>& visited){
        if((i >= 0 && i < n) && (j >= 0 && j < n) && 
           (m[i][j] == 1) && (visited[i][j] == 0)) {
            return true;
        }
        return false;
    }
    
    void solve(vector<vector<int>>& m, int n, vector<string>& ans, 
               int x, int y, vector<vector<int>>& visited, string path) {
        
        // Base case - reached destination
        if(x == n-1 && y == n-1) {
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        // Down
        if(isSafe(x+1, y, n, m, visited)) {
            solve(m, n, ans, x+1, y, visited, path + "D");
        }
        
        // Left  
        if(isSafe(x, y-1, n, m, visited)) {
            solve(m, n, ans, x, y-1, visited, path + "L");
        }
        
        // Right
        if(isSafe(x, y+1, n, m, visited)) {
            solve(m, n, ans, x, y+1, visited, path + "R");
        }
        
        // Up
        if(isSafe(x-1, y, n, m, visited)) {
            solve(m, n, ans, x-1, y, visited, path + "U");
        }
        
        visited[x][y] = 0; // Backtrack
    }
    
    vector<string> ratInMaze(vector<vector<int>>& m) {
        int n = m.size();
        vector<string> ans;
        
        if(m[0][0] == 0 || m[n-1][n-1] == 0) {
            return ans;
        }
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        solve(m, n, ans, 0, 0, visited, "");
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main() {
    Solution sol;
    
    // Test case: 3x3 maze
    vector<vector<int>> maze = {
        {1, 0, 0},
        {1, 1, 0},
        {1, 1, 1}
    };
    
    vector<string> result = sol.ratInMaze(maze);
    
    cout << "Paths found:" << endl;
    for(const string& path : result) {
        cout << path << endl;
    }
    
    if(result.empty()) {
        cout << "No path found" << endl;
    }
    
    return 0;
}
