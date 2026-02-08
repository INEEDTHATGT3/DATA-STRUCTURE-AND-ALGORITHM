#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
#include<limits.h>
#include<unordered_map>
#include<list>
using namespace std;

class Solution {
  public:

    void dfsHelper(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList, vector<int> &component){
        component.push_back(node);
        visited[node] = true;

        //har connected node ke liye recursive call
        for(auto i: adjList[node]){
            if(!visited[i]){
                dfsHelper(i, visited, adjList, component);
            }
        }
        }

    vector<vector<int>> dfs(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int, list<int> > adjList;
        //making adjacency list
        for(int i=0; i<adj.size(); i++){
            int u = adj[i][0];
            int v = adj[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int >> ans;
        unordered_map<int, bool> visited;

        for(int i=0; i<adjList.size(); i++){
            if(!visited[i]){
                vector<int> component;
                dfsHelper(i, visited, adjList, component);
                ans.push_back(component);
            }
        }
        return ans;

    }
};