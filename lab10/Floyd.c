// for directional weighted graph as adj matrix
#include <stdio.h>
#define  V 10
#define MAX 999

int min(int,int);

void floyds(int adj_mat[V][V],int n)
{
  int i,j,k;

  for(k=0;k<n;k++)  // for traversing all nodes
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        if(i==j) adj_mat[i][j]=0;
        else
          adj_mat[i][j]=min(adj_mat[i][j],adj_mat[i][k]+adj_mat[k][j]);
}

int min(int a,int b)
{
  if(a<b)
    return(a);
  else
    return(b);
}

void printer(int adj_mat[V][V], int n)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      printf("%d\t",adj_mat[i][j]);
    }
    printf("\n");
  }
}

void main()
{
  int n;
  printf("\n Enter the number of vertices:");
  scanf("%d",&n);

  int adj_mat[V][V] = {
    {0, 3,   MAX, 7},
    {8, 0,   2,   MAX},
    {5, MAX, 0,   1},
    {2, MAX, MAX, 0}
  };

  floyds(adj_mat,n);
 
  printf("\n The shortest paths are:\n");
  printer(adj_mat, n);
  
}
/*

 Enter the number of vertices:4

 The shortest paths are:
0	3	5	6	
5	0	2	3	
3	6	0	1	
2	5	7	0	
*/
