#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct trie{
    int leaf;
    struct tire* v1[26];
};
struct trie* newnode(){
    struct trie* temp=(struct tire*)malloc(sizeof(struct trie));
    temp->leaf=0;
    for(int i=0;i<26;i++){
        temp->v1[i]=NULL;
    }
    return temp;
}
int search(struct trie* head,char* str){
    if(head==NULL){
        return 0;
    }
    struct trie* temp=head;
    while(*str){
        
    }
}
void insert(struct trie* head,char* str){
    struct trie* curr=*head;
    while(*str){
        if(curr->v1[*str-'a']==NULL){
            curr->v1[*str-'a']=newnode();
        }
        else{
            curr=curr->v1[*str-'a'];
        }
        str++;
    }
}

int main(){
    //
}
