#include<bits/stdc++.h>
using namespace std;

#define V 4                       /*NUMBER OF VERTICES*/
// an array of vectors can be used as a matrix by enclosing them in curly braces and using two square brackets to get the values at different indexes.
vector<int> djikstra(int graph[V][V],int src)      //V STANDS FOR NUMBER OF VERTICES AND src STANDS FOR SOURCE VERTEX FROM WHICH WE WANT TO FIND THE SHORTEST DISTANCE
{ 

	vector<int> dist(V,INT_MAX);					//dist = distance array whose size is V and we initialize it as infinite.
									// we are going to use vertices as indexes in this array!
	
	dist[src]=0;							// initialized the distance of source vertex as 0
	vector<bool> fin(V,false);					//fin = finalized array which is a Boolean Array which is initialized as false and its size is V.

	for (int count = 0; count < V-1 ; count++) 
	{ 
		int u = -1; 

		for(int i=0;i<V;i++)
		    if(!fin[i]&&(u==-1||dist[i]<dist[u]))
		        u=i;
		fin[u] = true; 
		
		for (int v = 0; v < V; v++) 

			if (graph[u][v]!=0 && fin[v] == false) 
				dist[v] = min(dist[v],dist[u]+graph[u][v]); 
	} 
    return dist;
} 

int main() 
{ 
	int graph[V][V] = { { 0, 50, 100, 0}, 
						{ 50, 0, 30, 200 }, 
						{ 100, 30, 0, 20 }, 
						{ 0, 200, 20, 0 },}; 
	
	for(int x: djikstra(graph,0)){
	    cout<<x<<" ";
	} 

	return 0; 
} 

