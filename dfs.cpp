#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
vector<int> adj[100];
void addEdge(int a,int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}
void dfs(int s){
    stack<int> s1;
    vector<bool> visited;
    visited.assign(7,false);
    s1.push(s);
    while(s1.empty()==false){
        s=s1.top();
        s1.pop();
        if(visited[s]==false){
            cout<<s<<" ";
            visited[s]=true;
        }
        for(auto i=adj[s].begin();i!=adj[s].end();i++){
            int temp=*i;
            if(visited[temp]==false){
                s1.push(temp);
            }
        }
    }
}
int main()
{
    addEdge(1, 0); 
    addEdge(0, 2); 
    addEdge(2, 1); 
    addEdge(0, 3); 
    addEdge(1, 4); 
    dfs(0);
    
}
