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
template <typename T> //to make any type of greph only need to mention before calling

class graph{
    public:
    unordered_map<T, list<T>> adj;

    void addEdge(int u, int v, bool direction){
        //direction = 0-> undirected
        //direction = 1-> directed

        //create an edge from u to v
        adj[u].push_back(v);
        if(direction ==0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout << i.first << "->";
            for(auto j:i.second){
                cout << j << ", ";
            }
            cout<< endl;
        }
    }
};

int main(){

    int n;
    std :: cout<< "Enter the number of nodes" << endl;
    std :: cin >> n;

    int m;
    std :: cout<< "Enter the number of nodes" << endl;
    std :: cin >> m;

    graph <int>g;

    for(int i=0; i<m; i++){
        int u, v;
        std:: cin >> u >> v;
        //creating a undirected graph
        g.addEdge(u,v,0);
    }

    //PRINTING GRAPH
    g.printAdjList();
}