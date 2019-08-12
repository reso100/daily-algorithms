#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int sum=0;
int k=20;
stack<int> st;
int ans=0;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newnode(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void solve(struct node* p)
{
    if(p==NULL){
        return;
    }
    sum=sum+p->data;
    st.push(p->data);
    if(sum==k){
      //print stack;
      ans++;
    }
    solve(p->left);
    solve(p->right);
    sum=sum-st.top();
    st.pop();
}
int main(){
    struct node* root=newnode(1);
    root->left=newnode(2);
    root->left->left=newnode(4);
    root->left->left->left=newnode(8);
    root->left->right=newnode(5);
    root->left->left->right=newnode(9);
    root->right=newnode(3);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    root->right->right->right=newnode(12);
    root->right->left->left=newnode(10);
    root->right->left->right=newnode(10);
    solve(root);
    cout<<ans<<endl;
}

