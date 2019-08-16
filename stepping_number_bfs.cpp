#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void bfs(int n,int m,int num){
    queue<int> q;
    q.push(num);
    while(q.empty()==false){
        int temp=q.front();
        q.pop();
        if(temp>=n && temp<=m){
            cout<<temp<<" ";
        }
        if(temp>=m || num==0){
            continue;
        }
        int last=temp%10;
        int a=temp*10+ last-1;
        int b=temp*10+ last+1;
        if(last==0){
            q.push(b);
        }
        else if(last==9){
            q.push(a);
        }
        else{
            q.push(a);
            q.push(b);
        }
        
    }
}
void solve(int n,int m){
    for(int i=0;i<=9;i++){
        bfs(n,m,i);
    }
}
int main()
{
    int n=0;
    int m=21;
    solve(n,m);
    
}
