#include<bits/stdc++.h>
using namespace std;
#define max_size 100000
#define ll long long int
ll n;
ll arr[max_size+1];
ll tree[max_size*4];
ll lazy[max_size*4];
void buidtree(ll node,ll b,ll e)
{
    if(b==e){
        tree[node]=arr[b];
        return;
    }
    buidtree(node*2,b,(b+e)/2);
    buidtree(node*2+1,(b+e)/2+1,e);
    tree[node] = min(tree[node*2],tree[node*2+1]);
}
void updatetree(ll node,ll b,ll e,ll i,ll j,ll diff)
{
    if(lazy[node]!=0){
        tree[node] += (b-e+1)*lazy[node];
        if(b!=e){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(i>e || b>j)return;
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
    tree[node] = min(tree[node*2],tree[node*2+1]);
}
ll query(ll node,ll b,ll e,ll i,ll j)
{
    if(lazy[node]!=0){
        tree[node] += (e-b+1)*lazy[node];
        if(b!=e){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(j<b || e<i)return INT_MAX;
    if(i<=b && e<=j)return tree[node];
    ll query1 = query(node*2,b,(b+e)/2,i,j);
    ll query2 = query(node*2+1,(b+e)/2+1,e,i,j);
    return min(query1,query2);
}
int main()
{
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    buidtree(1,1,n);
    for(int i=1;i<=n*4;i++)
        cout<<i<<" "<<tree[i]<<endl;
    int k,i,j;
    cin>>k;
    while(k--){
        cin>>i>>j;
        cout<<query(1,1,n,i,j)<<endl;
    }

}

