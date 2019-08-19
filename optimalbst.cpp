#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{   
    int v1[] = {34, 8, 50};  
    int n=3;
    int cost[n][n];
    for(int i=0;i<n;i++){
        cost[i][i]=v1[i];
    }
    for(int l=2;l<=n;l++){
        for(int i=0;i<=n-l+1;i++){
            int j=i+l-1;
            cost[i][j]=INT_MAX;
            for(int k=i;k<=j;k++){
                //when k becomes root of the subtree
                int c=accumulate(v1+i, v1+j+1, 0);
                if(k>i){
                    c+=cost[i][k-1];
                }
                if(k<j){
                    c+=cost[k+1][j];
                }
                if(c<cost[i][j]){
                    cost[i][j]=c;
                }
            }
        }
    }
    int ans=cost[0][n-1];
    cout<<ans<<endl;
    
}
