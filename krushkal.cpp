#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
Struct Node // as a data structure storage map
{
	int start;
	int end;
	int length;
};
bool compare(Node a, Node b)
{
	return a.length < b.length;
}
void Kruskal(vector<Node> &arr, vector<bool> &visited)
{
	int M, N;
	M = visited.size();
	N = arr.size();
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].start >> arr[i].end >> arr[i].length;
	}
	sort(arr.begin(), arr.end(), compare);
	int weight = 0;
	for (int i = 0; i < N; i++)
	{
		if (!visited[arr[i].start] || !visited[arr[i].end]){
			weight += arr[i].length;
			visited[arr[i].start] = true;
			visited[arr[i].end] = true;
		}
	}
	 Cout << "Minimum spanning tree weight:";
	cout << weight << endl;
}
int main()
{
	int M,N;
	cin>>M>> N;
	vector<Node> arr(N);
	vector<bool> visited(M);
	Kruskal(arr,visited);
}
/*
 I am sent to you as a test case.
6 8
0 1 2
0 2 1
1 3 5
2 3 4
1 2 3
2 4 1
4 5 2
3 5 3
 Minimum spanning tree weight is 9
*/
