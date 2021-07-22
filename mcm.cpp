#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int n;
int m[100][100],s[100][100];
void mcm(int mat[])
{
    //for(int i=1;i<n;i++)m[i][i]=0;
    for(int len=2;len<n;len++){
        for(int i=1;i<n-len+1;i++){
            int j=i+len-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int q = m[i][k]+m[k+1][j]+mat[i-1]*mat[k]*mat[j];
                if(q<m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout<<"elements of m: "<<endl;
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++)cout<<m[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<"elements of s: "<<endl;
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++)cout<<s[i][j]<<" ";
        cout<<endl;
    }

}
int main()
{
    int mat[] = {30,20,15,5,10,5,10};//order of matrices => 30*20,20*15,15*5,...
    n = sizeof(mat)/sizeof(1);//number of matrices + 1 = n
    mcm(mat);

}
