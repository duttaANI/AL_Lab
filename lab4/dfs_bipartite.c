// A C Program to demonstrate adjacency list 
// representation of graphs 
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include "graphAdjacency_list.h"
#define V  10 // CHANGE IF REQUIRED

// Perform DFS on graph starting from vertex v
int DFS(struct Graph *graph, int v, int *discovered,int *color)
{
    struct AdjListNode* pCrawl = graph->array[v].head; 
      
    //printf("\n"); 
    // do for every edge (v -> u)
    
    while (pCrawl)
    {   
        // if vertex u is explored for first time
        if (!discovered[pCrawl->dest])
        {
            // mark current node as discovered
            discovered[pCrawl->dest] = 1;

            // set color as opposite color of parent node
            color[pCrawl->dest] = !color[v];

            // if DFS on any subtree rooted at v
            // we return false
            if (!DFS(graph, pCrawl->dest, discovered, color))
                return 0;
        }
        // if the vertex is already been discovered and color of vertex
        // u and v are same, then the graph is not Bipartite
        else if (color[v] == color[pCrawl->dest]) {
            return 0;
        }
        
        pCrawl = pCrawl->next; 
        printf("\n");
    }

    return 1;
}

// Driver program to test above functions 
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
    
   

    /*addEdge(graph, 1, 2); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 2, 8); 
    addEdge(graph, 3, 4); 
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 7); 
    addEdge(graph, 5, 9); 
    addEdge(graph, 8, 9); */
    //(graph, 2, 4); // if we remove 2->4 edge, graph is becomes Bipartite
    
    /*addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); */

    int discovered[V] = {0};
    int color[V] = {0};

    // mark source vertex as discovered and
    // set its color to 0
    discovered[0] = true, color[0] = 0;

    // print the adjacency list representation of the above graph 
    printGraph(graph); 

    if (DFS(graph, 0, discovered, color))
        printf( "Bipartite Graph");
    else
        printf("Not a Bipartite Graph");

    return 0; 
} 
