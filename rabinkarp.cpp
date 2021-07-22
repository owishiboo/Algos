#include<bits/stdc++.h>
using namespace std;
#define d 256
void searchpattern(char* text,char* pattern)
{
    int j=0;
    int n = strlen(text);
    int m = strlen(pattern);
    int prime = 101;
    int t = 0;//hashcode of text
    int p = 0;//hashcode of pattern
    int h = 1;//basically value of d with highest power possible--> d^(m-1)
    for(int i=0;i<m-1;i++)h=(h*d)%prime;

    for(int i=0;i<m;i++)//define hashcode
    {
        t = (t*d+text[i])%prime;
        p = (p*d+pattern[i])%prime;
        //cout<<p<<" "<<t<<endl;
    }
    for(int i=0;i<=n-m;i++)//match
    {
        if(p==t){
            for(j=0;j<m;j++){
                if(pattern[j]!=text[i+j])
                    break;
            }
            if(j==m)
                cout<<"Pattern found at shift "<<i<<endl;
        }
        if(i<n-m)t = ((t-text[i]*h)*d + text[i+m])%prime;//mod korar karone hoyto je value ashar kotha tar theke kome gese, ejonne t negative hoite pare
        if(t<0)t=t+prime;
    }

}
int main()
{
    char text[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char pattern[] = "aaaaaa";
    searchpattern(text,pattern);

}

