#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int r=3;
int c=5;
int v1[3][5] = { {2, 1, 0, 2, 1}, 
                     {1, 0, 1, 2, 1}, 
                     {0, 1, 0, 2, 1}}; 
vector<int> v3={1,-1,0,0};
vector<int> v4={0,0,1,-1};
bool isvalid(int i,int j){
    if(i>=0 && j>=0 && i<3 && j<5 && v1[i][j]==1){
        return true;
    }
    return false;
}
void print(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<v1[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool checkall() 
{ 
    for (int i=0; i<r; i++) 
       for (int j=0; j<c; j++) 
          if (v1[i][j] == 1) 
             return true; 
    return false; 
} 
int solve(){
    queue<pair<int,int>> q;
    pair<int,int> temp;
    int ans=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(v1[i][j]==2){
                q.push(make_pair(i,j));
            }
        }
    }
    q.push(make_pair(-1,-1));
    while(q.empty()==false){
        
        bool flag=false;
        while(q.front().first!=-1 && q.front().second!=-1){
            temp=q.front();
            q.pop();
            int a,b;
            for(int i=0;i<4;i++){
                a=v3[i]+temp.first;
                b=v4[i]+temp.second;
                if(isvalid(a,b)){
                    if(flag==false){
                        flag=true;
                        ans++;
                    }
                    q.push(make_pair(a,b));
                    v1[a][b]=2;
                }
            }
        }
        q.pop();
        if(q.empty()==false){
            q.push(make_pair(-1,-1));
        }
    }
    if(checkall()==true){
        return -1;
    }
    else{
        return ans;
    }
}
int main()
{
    int ans = solve(); 
    cout<<ans<<endl;
    print();
}
