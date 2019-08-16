#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct  Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node (int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
};
void inorder(struct Node* root){
    stack<struct Node*> st;
    struct Node* curr=root;
    while(curr!=NULL || st.empty()==false){
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
    }
}
int main()
{
    struct Node *root = new Node(1); 
    root->left        = new Node(2); 
    root->right       = new Node(3); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5); 
    inorder(root);
    
}
