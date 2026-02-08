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
    bool isCyclicBFS(int src, unordered_map<int,bool> &visited, unordered_map<int, list<int> > &adjList){
        unordered_map<int, int> parent;

        parent[src] = -1;
        visited[src] = 1;
        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto neighbour: adjList[front]){
                if(visited[neighbour] == true && neighbour != parent[front]){
                    return true;
                }
                else if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = 1;
                    parent[neighbour] = front;
                }
            }
        }
        return false;
    }

    bool isCyclicDFS(int node, int parent, unordered_map<int,bool> &visited, unordered_map<int, list<int>> &adjList){
        visited[node] = true;

        for(auto neighbour: adjList[node]){
            if(!visited[neighbour]){
                bool ans = isCyclicDFS(neighbour, node, visited, adjList);
                if(ans == true){
                    return true;
                }
            }
            else if(neighbour != parent){
                //cycle exists
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int m = edges.size();

        unordered_map<int, list<int> > adjList;
        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        //to handle disconnected components
        unordered_map<int, bool> visited;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool ans = isCyclicDFS(i, -1, visited, adjList);
                if(ans==1)
                return true;
            }
        }
        return false;
    }
};