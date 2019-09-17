#include <bits/stdc++.h> 
using namespace std; 
struct Node { 
	int data; 
	Node *left, *right; 
}; 
Node* newNode(int data) 
{ 
	Node* node = (Node*)malloc(sizeof(Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 
void solve(struct Node* root){
    queue<struct Node*> q;
    q.push(root);
    q.push(NULL);
    int sum=0;
    while(q.empty()==false){
        struct Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            if(q.empty()==true){
                cout<<"sum of diagonal"<<" "<<sum<<endl;
                break;
            }
            if(q.empty()==false){
                q.push(NULL);
                cout<<"sum of diagonal"<<" "<<sum<<endl;
                sum=0;
                cout<<endl;
            }
        }
        else{
            while(temp!=NULL){
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                sum=sum+temp->data;
                cout<<temp->data<<" ";
                temp=temp->right;
            }
        }
    }
}
int main() 
{ 
	Node* root = newNode(8); 
	root->left = newNode(3); 
	root->right = newNode(10); 
	root->left->left = newNode(1); 
	root->left->right = newNode(6); 
	root->right->right = newNode(14); 
	root->right->right->left = newNode(13); 
	root->left->right->left = newNode(4); 
	root->left->right->right = newNode(7); 
	solve(root); 
} 
