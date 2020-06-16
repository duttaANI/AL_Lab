#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
//#define V2 5

int stack[20];
int top=-1;

// Perform iterative DFS on graph g starting from vertex v
void iterative_DFS(struct Graph *graph, int v, int *discovered)
{
	

	// push the source node into stack
	top=top+1;
	stack[top]=v;

	// run till stack is not empty
	while (top!=-1)
	{
		// Pop a vertex from stack
		// v = stack.top();
		// stack.pop();
		v= stack[top];
		top=top-1;

		// if the vertex is already discovered yet,
		// ignore it
		if (discovered[v])
			continue;

		// we will reach here if the popped vertex v
		// is not discovered yet. We print it and process
		// its undiscovered adjacent nodes into stack
		discovered[v] = 1;
		//cout << v << " ";
		printf("%d\t",v);

		// do for every edge (v -> u)
		// we're using reverse iterator (Why?)
		// for (auto it = graph.adjList[v].rbegin();
		// 		  it != graph.adjList[v].rend(); ++it)
		struct AdjListNode * pCrawl = graph->array[v].head;
		while(pCrawl)
		{
			int u = pCrawl->dest;
			if (!discovered[u]){
                top++;
                stack[top] = u;
				//stack.push(u);
			}
			pCrawl=pCrawl->next;
		}
	}
}



int main()
{
	int i,j;
	int V=5; //< -------------- no. of vertices ------------------>//

	struct Graph* graph = createGraph(V);

	printf("enter adj matrix\n");
	int k=1;

	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			scanf("%d",&MATRIX[i][j]);
		}
	}
	

	for(i=0;i<V;i++)
	{
		for(j=k;j<V;j++)
		{
			if(MATRIX[i][j]==1)
				addEdge(graph,i,j);
		}
		k=k+1;
	}
    printGraph(graph);

    int discovered [V];

    for(int n=0;n<V;n++)
    {
    	discovered[n]=0;
    }

    for (int i = 0; i < V; i++)
		if (discovered[i] == 0)
			iterative_DFS(graph, i, discovered);

    
}