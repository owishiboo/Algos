#include<bits/stdc++.h>
using namespace std;
#define max_size 100000
int n;
int arr[max_size+1];
int tree[max_size*4];
int lazy[max_size*4];
void buidtree(int node,int b,int e)
{
    if(b==e){
        tree[node]=arr[b];
        return;
    }
    buidtree(node*2,b,(b+e)/2);
    buidtree(node*2+1,(b+e)/2+1,e);
    tree[node] = tree[node*2]+tree[node*2+1];
}
void updatetree(int node,int b,int e,int i,int j,int diff)
{
    if(lazy[node]!=0){
        tree[node] += (b-e+1)*lazy[node];
        if(b!=e){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(i>e || b>j)return;//b>e is not possible
    if(i<=b && j>=e){
        tree[node] += (b-e+1)*diff;
        if(b!=e){
            lazy[2*node] += diff;
            lazy[2*node+1] += diff;
        }
        return;
    }
    updatetree(node*2,b,(b+e)/2,i,j,diff);
    updatetree(node*2+1,(b+e)/2+1,e,i,j,diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}
int query(int node,int b,int e,int i,int j)
{
    if(lazy[node]!=0){
        tree[node] += (e-b+1)*lazy[node];
        if(b!=e){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(j<b || e<i)return 0;
    if(i<=b && e<=j)return tree[node];
    int query1 = query(node*2,b,(b+e)/2,i,j);
    int query2 = query(node*2+1,(b+e)/2+1,e,i,j);
    return query1+query2;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    buidtree(1,1,n);
    int k;
    for(int i=1;i<=n*4;i++)
        cout<<i<<" "<<tree[i]<<endl;
    cout<<"Update operations: "<<endl;
    cin>>k;
    while(k--){
        int i,j,k;
        cin>>i>>j>>k;
        updatetree(1,1,n,i,j,k);
    }
    cout<<"After update"<<endl;
    for(int i=1;i<=n*4;i++)
        cout<<i<<" "<<tree[i]<<endl;
    cout<<"Sum operations: "<<endl;
    cin>>k;
    while(k--){
        int i,j;
        cin>>i>>j;
        cout<<query(1,1,n,i,j)<<endl;
    }
}
