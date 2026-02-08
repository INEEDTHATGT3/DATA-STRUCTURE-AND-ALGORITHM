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

    bool checkCyclicDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adjList){
        visited[node] = true;
        dfsVisited[node] = true;

        for(auto neighbour: adjList[node]){
            if(!visited[neighbour]){
                bool cycleDetected = checkCyclicDFS(neighbour, visited, dfsVisited, adjList);
                if(cycleDetected)
                    return true;
            }
            else if(dfsVisited[neighbour]){
                //visited true 
                return true;
            }
        }

        dfsVisited[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        //create adjacency list
        unordered_map<int, list<int>> adjList;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
        }

        //call dfs for all components
        unordered_map<int, bool> visited;
        unordered_map<int,bool> dfsVisited;
        for(int i=1; i<=V; i++){
            if(!visited[i]){
                bool cycleFound = checkCyclicDFS(i, visited, dfsVisited, adjList);
                if(cycleFound)
                    return true;
            }
        }
        return false;
    }
};