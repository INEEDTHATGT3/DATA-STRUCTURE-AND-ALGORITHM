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

  void topoSortHelper(int node, unordered_map<int, bool> &visited, stack<int> &stack, unordered_map<int, list<int>> &adjList){
    visited[node]=1;

    for(auto neighbour: adjList[node]){
        if(!visited[neighbour]){
            topoSortHelper(neighbour, visited, stack, adjList);
        }
    }

    stack.push(node);
  }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, list<int>> adjList;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
        }

        //call dfs topological sort until function for all components
        //visited can be used in vector for better complexity
        unordered_map<int, bool>visited;
        stack<int> stack;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                topoSortHelper(i, visited, stack, adjList);
            }
        }
        vector<int> ans;

        while(!stack.empty()){
            ans.push_back(stack.top());
            stack.pop();
        }
        return ans;
    }
};