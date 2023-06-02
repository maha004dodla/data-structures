#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000005];
int visited[1000005];
void dfs(int node)
{
	cout<<node<<" ";
	visited[node]=1;
	for(auto i:adj[node])
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}

}
int main()
{
	int V,E,i;
	//enter no.of vertices and edges
	cin>>V>>E;
	for(i=0; i<V; i++)
	{
		int u,v;
		//enter vertex1 and vertex2
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout<<"dfs traversal: ";
	dfs(0);//dfs(start node);

}