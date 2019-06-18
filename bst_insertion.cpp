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
