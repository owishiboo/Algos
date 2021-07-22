#include<bits/stdc++.h>
#define inf 1<<25
using namespace std;
int n;
int capacity[10000][10000];
vector<int > adj[1000];//array of vectors
int bfs(int source, int sink, vector<int>& parent)
{
    fill(parent.begin(),parent.end(),-1);
    parent[source] = -2;//parent upgrade, mane traverse kora hoyeche
    queue<pair<int,int> >q;
    q.push(make_pair(source,INT_MAX));//int_max or inf
    while(!q.empty()){
        int curr = q.front().first;//kon vertex e achi ekhon
        int flow = q.front().second;//etokkhon porjonto minimum flow koto. shurute minimum flow ekta boro value dhore nei
        q.pop();
        for(int i=0;i<adj[curr].size();i++){
            if(parent[adj[curr][i]]==-1 && capacity[curr][adj[curr][i]]>0){
                parent[adj[curr][i]]=curr;//parent upgrade, mane traverse kora hoyeche
                int new_flow = min(flow,capacity[curr][adj[curr][i]]);
                if(adj[curr][i]==sink)return new_flow;//augmented path is completed
                else q.push(make_pair(adj[curr][i],new_flow));//if sink is not found then again count
            }
        }
    }
    return 0;//sink porjonto jete pareni, mane r way nai
}
int maxcount(int source, int sink)
{
    int maxflow = 0,flow;
    vector<int>parent(n+1);//augmented path
    while(flow = bfs(source, sink, parent)){//barbar traverse kora jotokkhon na porjonto 0 ashe
//        cout<<flow<<endl;
//        for(int i=0;i<n;i++)cout<<parent[i]<<" ";
//        cout<<endl;
        maxflow += flow;
        int prev = parent[sink];
        int curr = sink;
        while(prev!=-2){
            capacity[prev][curr] -= flow;
            capacity[curr][prev] += flow;
            curr = prev;
            prev = parent[prev];
        }
    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++)
//            cout<<capacity[i][j]<<" ";
//        cout<<endl;
//    }
    return maxflow;
}
int main()
{
    int a,b,cost,m;
    cin>>n>>m;//n=number of vertices,m=number of edges
    memset(capacity,0,sizeof capacity);
    while(m--){
        cin>>a>>b>>cost;
        adj[a].push_back(b);
        adj[b].push_back(a);//as an undirected graph
        capacity[a][b]=cost;
    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<adj[i].size();j++)
//            cout<<adj[i][j]<<" ";
//        cout<<endl;
//    }
//    cout<<endl;
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++)
//            cout<<capacity[i][j]<<" ";
//        cout<<endl;
//    }
    cout<<maxcount(0,5)<<endl;
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++)
//            cout<<capacity[i][j]<<" ";
//        cout<<endl;
//    }

}
/*
6 9
0 1 7
0 4 4
1 2 5
1 3 3
2 5 8
3 2 3
3 5 5
4 1 3
4 3 2
answer: 10
6 9
0 1 10
0 3 10
1 3 2
1 2 4
3 4 9
1 4 8
4 2 6
2 5 10
4 5 10
answer: 19
for bipartite matching: loj 1149
*/
