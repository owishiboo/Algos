#include<bits/stdc++.h>
using namespace std;
struct node
{
    int value;
    node *left, *right;
    node(int x){
        left = NULL;
        right = NULL;
        value = x;
    }
};
struct bst
{
    bst(){
        root = NULL;
    }
    node *root;
    node* find_(int x);
    void insert_(int x);
    void printbst(node *a);

};
node* bst :: find_(int x)
{
    node *curr = root;
    while(curr->value!=x){
        if(curr->value>x){
            if(curr->left==NULL)return curr;
            curr = curr ->left;
        }
        else if(curr->value<x){
            if(curr->right==NULL)return curr;
            curr = curr ->right;
        }
    }
    return curr;
}
void bst :: insert_(int x)
{
    node *curr = new node(x);
    if(root==NULL){
        root=curr;
        return;
    }
    node *address = find_(x);
    if(address->value>x)address->left = curr;
    else if(address->value<x)address->right = curr;
}
void bst:: printbst(node *a)
{
    node* curr = a;
    if(curr==NULL) return;
    cout<<"Curr: "<<curr->value<<" ";
    cout<<"Left: "<<((curr->left==NULL)?-1:curr->left->value)<<" ";
    cout<<"Right: "<<((curr->right==NULL)?-1:curr->right->value)<<endl;
    printbst(curr->left);
    printbst(curr->right);
}
int main()
{
    bst a;
    a.insert_(100);
    a.insert_(200);
    a.insert_(9);
    a.insert_(20);
    a.insert_(30);
    a.printbst(a.root);
}
