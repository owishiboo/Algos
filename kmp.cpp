#include<bits/stdc++.h>
using namespace std;
void createlps(char* pattern, int m, int* lps)
{
    int i=1;
    int j=0;
    lps[0] = 0;
    while(i<m){
        if(pattern[i]==pattern[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j==0){
                lps[i]=0;
                i++;
            }
            else
                j = lps[j-1];
        }
    }
    //for(i=0;i<m;i++)cout<<lps[i]<<endl;
}
void searchpattern(char* text,char* pattern)
{
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[m];
    createlps(pattern,m,lps);
    int i=0,j=0;
    while(i<n){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        else{
            if(j==0)i++;
            else j=lps[j-1];
        }
        if(j==m){
            cout<<"Shift "<<i-j<<endl;
            j=lps[j-1];
        }


    }
}
int main()
{
    char text[] = "acacabacacabacacac";
    char pattern[] = "acac";
    searchpattern(text,pattern);
}
