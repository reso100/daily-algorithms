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
void print(struct node* root){
    if(root==NULL){
        return;
    }
    map<int,vector<int>> v1;
    queue<pair<struct node*,int>> q1;
    int hd=0;
    q1.push(make_pair(root,hd));
    while(q1.empty()==false){
        pair<struct node*,int> temp=q1.front();
        q1.pop();
        struct node* p=temp.first;
        int hdval=temp.second;
        v1[hdval].push_back(p->data);
        if(p->left!=NULL){
             q1.push(make_pair(p->left, hdval-1)); 
        }
        if(p->right!=NULL){
             q1.push(make_pair(p->right, hdval+1)); 
        }
        
    }
    map< int,vector<int> > :: iterator it; 
    for (it=v1.begin(); it!=v1.end(); it++) 
    { 
        for (int i=0; i<it->second.size(); ++i) 
            cout << it->second[i] << " "; 
        cout << endl; 
    } 
}
int main(){
    
    struct node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
    root->right->right->left= newNode(10); 
    root->right->right->left->right= newNode(11); 
    root->right->right->left->right->right= newNode(12); 
    cout << "Vertical order traversal is \n"; 
    print(root); 
    return 0; 
}
