#include<bits/stdc++.h>
using namespace std;
long long caseno=0;
#define print_case printf("Case %d: ",++caseno);
#define ll long long int
#define inf 0x3f3f3f3f
#define print(a) cout<<a<<endl;
#define pi acos(-1)
#define mod 1000003
#define EPS (1e-9)
#define MAX_SIZE 1000010
int nod[MAX_SIZE],cnt[MAX_SIZE];
void solve()
{
    nod[0] = 1;
    for(int i=1;i<MAX_SIZE;i++){
        for(int j=i;j<MAX_SIZE;j+=i)cnt[j]++;
    }
    for(int i=1;i<MAX_SIZE;i++)nod[i] = nod[i-1]+cnt[nod[i-1]];
}
int main()
{
    solve();
    int t,a,b,n;
    //print(111111)
    cin>>t;
    while(t--){
        cin>>a>>b;
        print_case
        int q = upper_bound(nod,nod+MAX_SIZE,b)-nod;
        int p = lower_bound(nod,nod+MAX_SIZE,a)-nod;
        cout<<q-p<<endl;
    }
    return 0;

}
