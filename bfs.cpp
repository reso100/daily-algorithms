#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define pb push_back
vector<bool> v;
vector<int> g[5];
void addedge(int a,int b){
        g[a].pb(b);
        g[b].pb(a);
}
void bfs(int u){
        queue<int> q;
        q.push(u);
        v[u]=true;
        while(q.empty()==false){
            int temp=q.front();
            q.pop();
            cout<<temp<<" ";
            for(auto i=g[temp].begin();i!=g[temp].end();i++){
                if(v[*i]==false){
                    q.push(*i);
                    v[*i]=true;
                }
            }
        }
}
int main() 
{ 
   
   addedge(1,2);
   addedge(1,5);
   addedge(2,3);
   addedge(2,4);
   bfs(1);
   //levelorder traversal of a tree;
} 