#include <stdio.h>
# include <stdlib.h>

int floor1( int x )
{
	return x/2 ;
}

int ceilg( int x)
{
	if( x%2 ==0 )
		return x/2;
	return x/2 + 1;
}

void copy( int* P , int* Q, int begin , int end , int copycatBegin)
{
	int j=copycatBegin;
	for (int i = begin; i <= end; ++i)
	{
		Q[j] = P[i];
		j=j+1;
	}
}

void merge1( int*B , int*C , int*A ,int p,int q)
{
    int i=0,j=0,k=0;
    while(i<p && j<q)
    {
    	if(B[i]<=C[j])
    	{
    		A[k]=B[i]; i=i+1;
    	}
    	else
    	{
    		A[k]=C[j]; j=j+1;
    	}
    	k=k+1;
    }
    if(i==p)
    {
    	copy(C,A, j,q-1, k);
    }
    else
    {
    	copy(B,A, i,p-1, k);
    }
}

void mergeSort( int* A, int n )
{
	int * B = (int *)malloc(  (floor1(n)-1)*sizeof(int) );
	int * C = (int *)malloc(  (ceilg(n)-1)*sizeof(int) );
	
     if( n > 1)
     {
     	copy ( A,B, 0        ,floor1(n)-1 ,0);
     	copy ( A,C, floor1(n) ,n-1        ,0);
     	mergeSort( B , floor1(n) );
     	mergeSort( C , ceilg(n) );
     	merge1(B,C,A,floor1(n),ceilg(n) );
     }
}



int main()
{
	int n;
	printf("Enter size :\n");
	scanf("%d",&n);

	int* arr = (int *)malloc(n*sizeof(int));

    printf("Enter arr to be sorted:\n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}

	mergeSort(arr,n);

	printf(" sorted arr is:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
