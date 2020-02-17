#include <stdio.h>
#include <stdlib.h>

void swap(int *A,int a, int b)
{
    int temp;
    printf("\nswapping %d and %d\n",A[a],A[b]);
    temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

void quickSort( int*A ,int Abegin,int i, int j, int Aend)
{
	int pi=Abegin;
    
    
    if( Abegin < Aend)//base condition 
    {
	    while( A[i]<A[pi] && i<Aend)
	    {
	    	i=i+1;
	    }
	    while( A[j]>A[pi] )
	    {
	    	j=j-1;
	    }
	    if(i <j)
	    {
	    	swap(A,i,j);
                
                printf("\nAbegin=%d i=%d j=%d Aend=%d\n",Abegin,i,j,Aend);
                printf("\n------------------------------------------------------\n");
	    	quickSort(A,Abegin,i+1     ,j-1 ,Aend);
	    }
	    else
	    {
	    	swap(A,pi,j);
                
                printf("\nAbegin=%d i=%d j=%d Aend=%d\n",Abegin,i,j,Aend);
                printf("\n------------------------------------------------------\n");
	    	quickSort(A,Abegin,Abegin+1,j-1 ,j-1 );
	    	quickSort(A,i     ,i+1     ,Aend,Aend);
	    }
    }
    return ;
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

	quickSort(arr,0,1,n-1,n-1);

	printf(" sorted arr is:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
