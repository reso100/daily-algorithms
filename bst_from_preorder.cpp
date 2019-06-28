#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
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
struct node* solve(int pre[],int* preindex,int low,int high,int size){
    if(*preindex>=size || low>high){
        return NULL;
    }
    struct node* root=newnode(pre[*preindex]);
    *preindex=*preindex+1;
    if(low==high){
        return root;
    }
    int i;
    for(i=low;i<=high;i++){
         if ( pre[ i ] > root->data )  
            break;  
    }
    root->left = solve ( pre, preindex, *preIndex,  
                                         i - 1, size );  
    root->right = solve ( pre, preindex, i, high, size ); 
    return root;
    
}
node * tree(int pre[], int size)  
{  
    int preIndex = 0;  
    return solve (pre, &preindex, 0, size - 1, size);  
}
void printInorder (node* node)  
{  
    if (node == NULL)  
        return;  
    printInorder(node->left);  
    cout<<node->data<<" ";  
    printInorder(node->right);  
}
int main ()  
{  
    int pre[] = {10, 5, 1, 7, 40, 50};  
    int size = sizeof( pre ) / sizeof( pre[0] );  
  
    node *root = tree(pre, size);  
  
    cout<<"Inorder traversal of the constructed tree: \n";  
    printInorder(root);  
  
    return 0;  
} 
