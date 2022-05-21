// What is Minimum Spanning Tree? 
// Given a connected and undirected graph, a spanning tree of that graph is a subgraph that is a tree and connects all the vertices together. 
// A single graph can have many different spanning trees. A minimum spanning tree (MST) or minimum weight spanning tree for a 
// weighted, connected, undirected graph is a spanning tree with a weight less than or equal to the weight of every other spanning tree. 
// The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.

// How many edges does a minimum spanning tree has? 
// A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph. 

#include <bits/stdc++.h> 
using namespace std; 
#define V 4

int primMST(int graph[V][V]) 
{ 

	int key[V];int res=0; 
	fill(key,key+V,INT_MAX);
	bool mSet[V]; key[0]=0;

	for (int count = 0; count < V ; count++) 
	{ 
		int u = -1; 

		for(int i=0;i<V;i++)
		    if(!mSet[i]&&(u==-1||key[i]<key[u]))
		        u=i;
		mSet[u] = true; 
		res+=key[u];

		
		for (int v = 0; v < V; v++) 

			if (graph[u][v]!=0 && mSet[v] == false) 
				key[v] = min(key[v],graph[u][v]); 
	} 
    return res;
} 

int main() 
{ 
	int graph[V][V] = { { 0, 5, 8, 0}, 
						{ 5, 0, 10, 15 }, 
						{ 8, 10, 0, 20 }, 
						{ 0, 15, 20, 0 },}; 

	cout<<primMST(graph); 

	return 0; 
} 
