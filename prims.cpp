#include <bits/stdc++.h>
using namespace std;
#define vertices 5
bool check(int u, int v, vector<bool> visited){
    if(u == v)return false;
    if(visited[u] == false && visited[v] == false)return false;
    else if(visited[u] == true && visited[v] == true)return false;
    return true;
}
void prims(int cost[][vertices]){
    vector<bool> visited(vertices, false);
    visited[0] = true;
    int edgeNo = 0, totalCost = 0;
    while (edgeNo < vertices - 1) {
        int mincost = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (cost[i][j] < mincost && check(i, j, visited)) {
                        mincost = cost[i][j];
                        a = i;
                        b = j;
                }
            }
        }
        if (a != -1 && b != -1) {
            cout<<"Edge "<<edgeNo++<<" : ("<<a<<" , "<<b<<" ) : cost = "<<mincost<<endl;
            totalCost += mincost;
            visited[b] = visited[a] = true;
        }
    }
    cout<<"Cost of Minimum spanning tree ="<<totalCost;
}
int main() {
    int cost[][vertices] =
    { { INT_MAX, 12, INT_MAX, 25, INT_MAX },//adj[i][j]=is the cost between i and j vertices
    { 12, INT_MAX, 11, 8, 12 },
    { INT_MAX, 11, INT_MAX, INT_MAX, 17 },
    { 25, 8, INT_MAX, INT_MAX, 15 },
    { INT_MAX, 12, 17, 15, INT_MAX }, };
    cout<<"The Minimum spanning tree for the given tree is :\n";
    prims(cost);
    return 0;
}
