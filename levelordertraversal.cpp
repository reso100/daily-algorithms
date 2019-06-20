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

void printlevel(struct node* root){
    if(root==NULL){return;}
    queue<struct node*> q1;
    q1.push(root);
    while(q1.empty()==false){
        struct node* temp=q1.front();
        cout<<temp->data<<" ";
        q1.pop();
        if(temp->left!=NULL){
            q1.push(temp->left);
        }
        if(temp->right!=NULL){
            q1.push(temp->right);
        }
    }
}
int main(){
    struct node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    cout << "Level Order traversal of binary tree is \n"; 
    printlevel(root); 
    return 0; 
    
}
