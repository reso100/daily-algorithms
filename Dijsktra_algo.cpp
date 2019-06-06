#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define v 9
int dis[v];
bool vis[v];
int graph[v][v] = {   {0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                  }; 

int mindis(){
    int mi=INT_MAX;
    int index;
    for(int i=0;i<v;i++){
        if(vis[i]==false && dis[i]<=mi){
            mi=dis[i];
            index=i;
        }
    }
    return index;
}
void print(){
    for(int i=0;i<v;i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    for(int t=0;t<v;t++){
        int u=mindis();
        vis[u]=true;
        for(int i=0;i<v;i++){
            if(!vis[i] && graph[u][i]!=0 && dis[u]!=INT_MAX  && dis[u]+graph[u][i]<dis[i]){
                dis[i]=dis[u]+graph[u][i];
            }
        }
    }
    print();
}
int main(){ 
    for(int i=0;i<v;i++){
        vis[i]=false;
    }
    for(int i=0;i<v;i++){
      dis[i]=INT_MAX;
    }
    dis[0]=0;
    //print();
    solve();
}
