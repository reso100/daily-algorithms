//Complete Disjoint dataset with union and path compression:)

import java.util.*;
import java.io.*;
class Disjointset{
    int[] rank,parent;
    int n;
    public Disjointset(int n){
        this.n=n;
        rank= new int[n];
        parent=new int[n];
        makeset();
    }
    void makeset(){
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=1;
        }
        
    }
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void union(int x,int y){
        int x1=find(x);
        int x2=find(y);
        if(x1==x2){
            return;
        }
        if(rank[x1]<rank[x2]){
            parent[x1]=x2;
        }
        if(rank[x1]>rank[x2]){
            parent[x2]=x1;
        }
        if(rank[x1]==rank[x2]){
            parent[x1]=x2;
            rank[x2]=rank[x2]+1;
        }
        
    }
    public static void main(String[] args){
        int n=5;
        Disjointset d1=new Disjointset(5);
        d1.union(0,3);
        d1.union(1,4);
        int ans=d1.find(4);
        int ans1=d1.find(1);
        System.out.println(ans);
        System.out.println(ans1);
    }
    
    
    

}
