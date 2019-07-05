#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n,m;
int counttt=0;
int v1[5][5];
bool vis[5][5];
int gb[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
int db[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
void dfs(int i,int j){
    vis[i][j]=true;
    int x1,x2;
    for(int k=0;k<8;k++){
        x1=gb[k];
        x2=db[k];
        if((i+x1 >= 0) && (i+x1 < n) && (j +x2>= 0) && (j+x2 < m) && (v1[i+x1][j+x2]==1 && vis[i+x1][j+x2]==false)){
              dfs(i+x1,j+x2);  
        }
    }
}
int main(){
    cin>>n>>m;
    int x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>x;
            v1[i][j]=x;
            vis[i][j]=false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==false && v1[i][j]==1){
                dfs(i,j);
                counttt++;
            }
        }
    }
    cout<<counttt<<endl;
}
