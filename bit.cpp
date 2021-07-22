#include<bits/stdc++.h>
using namespace std;
void update(int bittree[],int n,int index,int val)
{
    index = index+1;
    while(index<=n){
        bittree[index] +=  val;
        index += index & (-index);
    }
}
int *constructbit(int arr[],int n)
{
    int *bittree = new int[n+1];
    for(int i=0;i<=n;i++)
        bittree[i]=0;
    for(int i=0;i<=n;i++)
        update(bittree,n,i,arr[i]);
    for(int i=0;i<=n;i++)
        cout<<bittree[i]<<endl;
    return bittree;

}
int getsum(int bittree[], int index)
{
    int sum = 0;
    index = index+1;
    while(index>0){
        sum += bittree[index];
        index -= index & (-index);
    }
    return sum;
}
int main()
{
    int arr[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *bittree = constructbit(arr,n);
    cout<<"Sum: "<<getsum(bittree,n);

}
