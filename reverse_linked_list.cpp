#include <iostream>
using namespace std;
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
struct node* newnode(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void insert(int data){
    struct node* x=newnode(data);
    if(head==NULL){
        head=x;
        return;
    }
    else{
        struct node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=x;
    }
    
}
void print(){
    struct node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void reverse(struct node* temp){
    if(temp->next==NULL){
        head=temp;
        return;
    }
    reverse(temp->next);
    struct node* x=temp->next;
    x->next=temp;
    temp->next=NULL;
}
int main()
{
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    insert(5);
    print();
    reverse(head);
    print();
   
}
