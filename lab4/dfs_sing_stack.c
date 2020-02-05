
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include "graphAdjacency_list.h"
#define V  9 // CHANGE IF REQUIRED

int stack[20];
int top=-1;


int DFS(struct Graph *graph, int v, int *discovered)
{
  
    top=top+1;
    stack[top]=v;

    
    while (top!=-1)
    {
        
        v= stack[top];
        top=top-1;

        
        if (discovered[v])
            continue;

        
        discovered[v] = 1;
        printf("%d\t",v);

        
        struct AdjListNode * pCrawl = graph->array[v].head;
        while(pCrawl)
        {
            int u = pCrawl->dest;
            if (!discovered[u]){
                top++;
                stack[top] = u;
                
            }
            pCrawl=pCrawl->next;
        }
    }
}
 
int main() 
{ 
    int i,j;
    // create the graph given in above fugure 
    
    struct Graph* graph = createGraph(V); 

    addEdge(graph, 0, 1); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 7); 
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 5); 
    addEdge(graph, 4, 6);
    addEdge(graph, 4, 8); 
    addEdge(graph, 7, 8); 
    addEdge(graph, 1, 3); 
    
    

    int discovered[V] = {0};
    int color[V] = {0};

    

    // print the adjacency list representation of the above graph 
    printGraph(graph); 

    for (int i = 0; i < V; i++)
        if (discovered[i] == 0)
            DFS(graph, i, discovered);

    

    return 0; 
} 
