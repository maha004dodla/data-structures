#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000005];
int visited[1000005];
void bfs(int node)
{
	queue<int>q;
	q.push(node);
	visited[node]=1;
	while(!q.empty())
	{
		node=q.front();
		q.pop();
		cout<<node<<" ";
		for(auto i:adj[node])
		{
			if(!visited[i])
			{
				q.push(i);
				visited[i]=1;
			}
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
	cout<<"bfs traversal: ";
	bfs(0); //bfs(start node);
	return 0;
}




