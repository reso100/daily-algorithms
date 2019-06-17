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
int solve(struct node* p1,struct node* p2){
    if(p1==NULL && p2==NULL){
        return 1;
    }
    else if(p1==NULL && p2!=NULL){
        return 0;
    }
    else if(p2==NULL && p1!=NULL){
        return 0;
    }
    else{
        if(p1->data==p2->data && solve(p1->left,p2->left) && solve(p1->right,p2->right) ){
            return 1;
        }
        else{
            return 0;
        }
    }
}
int main(){
    
    
    struct node* root1 = newNode(5); 
    struct node* root2 = newNode(5); 
    root1->left = newNode(3); 
    root1->right = newNode(8); 
    root1->left->left = newNode(290); 
    root1->left->right = newNode(4); 
  
    root2->left = newNode(3); 
    root2->right = newNode(8); 
    root2->left->left = newNode(290); 
    root2->left->right = newNode(4); 
  
    if (solve(root1, root2)) 
        cout << "Both BSTs are identical"; 
    else
        cout << "BSTs are not identical"; 
}
