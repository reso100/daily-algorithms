#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
struct node* insert(struct node* node,int data){
    if(node==NULL){
        return newNode(data);
    }
    if(data>node->data){
        node->right=insert(node->right,data);
    }
    else{
        node->left=insert(node->left,data);
    }
    return node;
}
int hit(struct node* p){
    if(p==NULL){
        return 0;
    }
    int lhight=hit(p->left);
    int rhight=hit(p->right);
    return max(lhight,rhight)+1;
    
}
int diameter(struct node* p){
    if(p==NULL){
        return 0;
    }
    int lhit=hit(p->left);
    int rhit=hit(p->right);
    int ldiameter=diameter(p->left);
    int rdiameter=diameter(p->right);
    return max(lhit+rhit+1,max(ldiameter,rdiameter));
}
int main(){
  
   struct node* root=NULL;
   root=insert(root,20);
   root=insert(root,10);
   root=insert(root,40);
   root=insert(root,30);
   root=insert(root,70);
   root=insert(root,75);
   int ht=hit(root);
   int di=diameter(root);
   cout<<di<<endl;
   cout<<ht<<endl;
   inorder(root);
}
