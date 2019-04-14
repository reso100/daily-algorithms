//Graph algorithm part1 
//adjacency list representation
#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print(vector<int> adj[],int n){
    for(int i=0;i<n;i++){
        for(auto p:adj[i]){
            cout<<"->"<<p;
        }
        cout<<endl;
    }
}
int main()
{
    int n = 5; 
    vector<int> adj[n]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    print(adj, n);
     
}
