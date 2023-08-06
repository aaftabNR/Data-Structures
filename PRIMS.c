//Write a program to implement Prim’s algorithm for a given directed graph

#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define V 5 //NUMBER OF VERTICES IN THE GRAPH

//STEP-1
int minKey(int key[], bool mstSet[])
{
	int min= INT_MIN, min_index;
	
	for(int v=0; v<V; v++)
	{
		if(mstSet[v] == false && key[v] <min)
		{
			min = key[v];
			min_index = v;
		}
	}
	return min_index;
}

//STEP-2
void primMST(int graph[V][V])
{
	int parent[V];
	int key[V];
	bool mstSet[V]; //INDICATES IF NODE HAS BEEN INSERTED IN ARRAY OR NOT(T/F)
	
	for(int i=0;i<V;i++)
	{		
		key[i]=INT_MAX; //EACH NODE=INT MAX
		mstSet[i]=false;
	}
	
	key[0]=0;
	parent[0]=-1;
	for(int count =0; count<V-1;count++)
	{
		int u = minKey(key, mstSet);
		mstSet[u]= true;
		
		for(int v=0;v<V;v++)
		{
			if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v])
			{
				parent[v]=u;
				key[v]=graph[u][v];
			}
		}
	}
	
	printf("Edge \t Weight\n");
	for(int i=1;i<V;i++)
	{
		printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
	}
}

//STEP-3
int main()
{
	int graph[V][V];
	printf("Enter the adjacency matrix: \n");
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}
	
	primMST(graph);
	return 0;
}



