#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define pb push_back
vector<pair<int,int>> v1;
#define v 5
vector<int> wt;
int dis[v];
void bellmonford(){
    for(int i=0;i<v;i++){
        dis[i]=INT_MAX;
    }
    int e=v1.size();
    dis[0]=0;
    int a,b;
    for(int j=0;j<v-1;j++){
        for(int i=0;i<e;i++){
            a=v1[i].first;
            b=v1[i].second;
            if(dis[a]+wt[i]<dis[b]){
                dis[b]=dis[a]+wt[i];
            }
        }
    }
    //if we iterate through nth time and get a shortest path for any vertex then we get a -ve wt cycle.
    for(int i=0;i<e;i++ ){
        a=v1[i].first;
        b=v1[i].second;
        if(dis[a]+wt[i]<dis[b] && dis[b]!=INT_MAX){
                cout<<"Graph contain -ve cycle "<<endl;
                break;
        }
    }
    
    for(int i=0;i<v;i++){
        cout<<dis[i]<<" ";
    }
    
}

int main(){
    
    v1.pb(make_pair(0,1));
    v1.pb(make_pair(0,2));
    v1.pb(make_pair(1,2));
    v1.pb(make_pair(1,3));
    v1.pb(make_pair(1,4));
    v1.pb(make_pair(3,2));
    v1.pb(make_pair(3,1));
    v1.pb(make_pair(4,3));
    wt.pb(-1);
    wt.pb(4);
    wt.pb(3);
    wt.pb(2);
    wt.pb(2);
    wt.pb(5);
    wt.pb(1);
    wt.pb(-5);
    bellmonford();
    
    
}
