#include "queue.h"

int main()
{
    int mat[V][V],n,x;

    printf("enter no. of nodes:\n");
	scanf("%d",&n);

    printf("Enter adj matrix height=>source width=>destination \n");
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		scanf("%d",&mat[i][j]);
    	}
    }

    int vis[V] = {0};
    printf("bfs pop order\n");

    for (int i = 0; i < V; ++i)
    {
    	if(vis[i]!=1)
    	{
    		vis[i] =1;
    		enqueue(i);

    		while(front!= -1) // while queue not empty
    		{
    			x = dequeue();
    			printf("%d\t", x);

    			for (int j = 0; j < V; ++j)
    			{
    				if( mat[x][j] == 1 && vis[j]!=1 )
    				{
    					vis[j]=1;
    					enqueue(j);
    				}
    			}
    		}
    	}
    }

	return 0;
}

/*

enter no. of nodes:
5
Enter adj matrix height=>source width=>destination 
0 1 1 1 0
1 0 0 1 1
1 0 0 1 1
1 1 1 0 1
0 1 1 1 0
bfs pop order
0	1	2	3	4

*/