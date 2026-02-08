#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
#include<unordered_map>
#include<list>
using namespace std;

class Solution {
  public:

    void prepareAdjList(unordered_map<int, list<int> > &adjList, vector<vector<int>> &adj){
        for(int i=0; i<adj.size(); i++){
            for(int j=0; j<adj[i].size(); j++){
                adjList[i].push_back(adj[i][j]);
            }
        }
    }
    
    void bfs(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node){
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            //store frontnode into ans
            ans.push_back(frontNode);

            //traverse all neighbours of frontNode
            for(auto i: adjList[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }

    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        unordered_map<int, list<int> > adjList;
        vector<int> ans;
        unordered_map<int, bool> visited;
        int vertex = adj.size();

        prepareAdjList(adjList, adj);

        //traverse all component of a graph
        for(int i=0; i<vertex; i++){
            if(!visited[i]){
                bfs(adjList, visited, ans, i);
            }
        }
        return ans;
    }
};