#include<bits/stdc++.h>
#include<algorithm>
#define v 9
#define pb push_back
using namespace std;
int parent[v];
vector<int> wt={1,2,2,4,4,6,7,7,8,8,9,10,11,14};
vector<pair<int,int>> v1;
int find(int i){
    if(parent[i]==i){
        return i;
    }
    return find(parent[i]);
}
void mere(int x,int y){
    int a=find(x);
    int b=find(y);
    parent[a]=b;
}
void kruskal(){
    int cost=0;
    int n=v1.size();
    int a,b;
    int edge=0;
    for(int i=0;i<n;i++){
            a=v1[i].first;
            b=v1[i].second;
            if(find(a)==find(b)){
                continue;
            }
            if(find(a)!=find(b)){
                cout<<a<<" "<<b<<endl;
                cost=cost+wt[i];
                mere(a,b);
                edge++;
            }
            if(edge==v-1){
                break;
            }
    }
    cout<<"min cost is "<<cost<<endl;
    
}
int main(){
    v1.pb(make_pair(7,6));
    v1.pb(make_pair(8,2));
    v1.pb(make_pair(6,5));
    v1.pb(make_pair(0,1));
    v1.pb(make_pair(2,5));
    v1.pb(make_pair(8,6));
    v1.pb(make_pair(2,3));
    v1.pb(make_pair(7,8));
    v1.pb(make_pair(0,7));
    v1.pb(make_pair(1,2));
    v1.pb(make_pair(3,4));
    v1.pb(make_pair(5,4)); v1.pb(make_pair(1,7)); v1.pb(make_pair(3,5));
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    cout<<wt.size()<<" "<<v1.size()<<endl;
    kruskal();
    int h=find(8);
    int k=find(6);
    cout<<h<<" "<<k<<endl;
}
