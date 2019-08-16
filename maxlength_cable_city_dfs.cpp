#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int n = 6; 
vector< pair<int,int> > graph[7]; 
bool vis[7];
int ans=-100;

void dfs(int s,int prev){
    vis[s]=true;
    int currlen=0;
    pair<int,int> temp;
    int a,b;
    for(int i=0;i<graph[s].size();i++){
        temp=graph[s][i];
        a=temp.first;
        b=temp.second;
        if(vis[a]==false){
            currlen=prev+b;
            dfs(a,currlen);
        }
        ans=max(ans,currlen);
        currlen=0;
    }
    
}
int solve(){
    for(int i=1;i<=n;i++){
        memset(vis,false,sizeof(vis));
        dfs(i,0);
    }
    return ans;
}
int main()
{
   
    graph[1].push_back(make_pair(2, 3)); 
    graph[2].push_back(make_pair(1, 3)); 
  
    graph[2].push_back(make_pair(3, 4)); 
    graph[3].push_back(make_pair(2, 4)); 
 
    graph[2].push_back(make_pair(6, 2)); 
    graph[6].push_back(make_pair(2, 2)); 
 
    graph[4].push_back(make_pair(6, 6)); 
    graph[6].push_back(make_pair(4, 6)); 
    graph[5].push_back(make_pair(6, 5)); 
    graph[6].push_back(make_pair(5, 5)); 
    int gb=solve();
    cout<<gb<<" ";
    
}
