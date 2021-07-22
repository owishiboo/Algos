#include<bits/stdc++.h>
using namespace std;
#define pf                  printf
#define sf(a)               scanf("%d",&a)
#define sf(a,b)             scanf("d",&a,&b)
#define sfc1(a)               scanf("%c",&a)
struct heap
{
    int n;
    int capacity=0;
    heap(int inp){
        n=inp;
    }
    int *heaparr = new int[n];
    int parent(int child);
    int left(int parent);
    int right(int parent);
    void insertval(int val);
    int getmin();
    void delmin();
    void decreasekey(int i,int val);

};
int heap :: parent(int child)
{
    return (child-1)/2;
}
int heap :: left(int parent)
{
    return 2*parent+1;
}
int heap :: right(int parent)
{
    return 2*parent+2;
}
void heap :: insertval(int val)
{
    if(capacity==n){
        cout<<"overloaded"<<endl;
        return;
    }

}
int main()
{

}
