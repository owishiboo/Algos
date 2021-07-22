#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1000000
int n;
int arr[MAX_SIZE+1];
int tree[MAX_SIZE*4+1];
void buildtree(int node,int b,int e)
{
    if(b==e){
        tree[node]=arr[b];
        return;
    }
    buildtree(node*2,b,(b+e)/2);
    buildtree(node*2+1,(b+e)/2+1,e);
    tree[node] = tree[node*2] + tree[node*2+1];
}
int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)return 0;
    if(i<=b && j>=e)return tree[node];
    int query1 = query(node*2,b,(b+e)/2,i,j);
    int query2 = query(node*2+1,(b+e)/2+1,e,i,j);
    return query1+query2;
}
void update(int node, int b, int e, int index, int val) {
    if(index<b || e<index)return;
    if (index == b && b == e){
        arr[b] = val;
        tree[node] = val;
    }
    else {
        if (index <= (b+e)/2)update(node*2, b, (b+e)/2, index, val);
        else update(node*2+1, (b+e)/2+1, e, index, val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    buildtree(1,1,n);
    for(int i=1;i<=n*4;i++)
        cout<<i<<" "<<tree[i]<<endl;
    int k,i,j,p,mark;
    cin>>p;
    while(p--){
        cin>>i>>j;
        //cout<<"Update:";
        update(1,1,n,i,j);
        //else cout<<query(1,1,n,i,j)<<endl;
    }
    cin>>k;
    while(k--){
        cin>>i>>j;
        cout<<query(1,1,n,i,j)<<endl;
    }

}

