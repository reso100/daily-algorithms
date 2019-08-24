#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int arr[]={10,7,8,9,1,5};
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
    
}
int main(){
    int n=6;
    quicksort(arr,0,5);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
