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
                
//                 printf("\nAbegin=%d i=%d j=%d Aend=%d\n",Abegin,i,j,Aend);
//                 printf("\n------------------------------------------------------\n");
            printf("\ni=%d j=%d\n",i,j);
	    	quickSort(A,Abegin,i+1     ,j-1 ,Aend);
	    }
	    else // partition happens
	    {
	    	swap(A,pi,j);
                
                //printf("\nAbegin=%d i=%d j=%d Aend=%d\n",Abegin,i,j,Aend);
                printf("\n------------------------------------------------------\n");
		printf("l1=%d u1=%d p=%d l2=%d u2=%d i=%d j=%d",Abegin,j-1,j,i,Aend,i,j);
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

/* sample i/o:

input :7
 2 7 6 3 1 5 4
 
 output:
 Enter size :
Enter arr to be sorted:

swapping 7 and 1

i=1 j=4

swapping 2 and 1

------------------------------------------------------
l1=0 u1=0 p=1 l2=2 u2=6 i=2 j=1
swapping 7 and 4

i=4 j=6

swapping 6 and 5

------------------------------------------------------
l1=2 u1=4 p=5 l2=6 u2=6 i=6 j=5
swapping 5 and 4

------------------------------------------------------
l1=2 u1=3 p=4 l2=4 u2=4 i=4 j=4
swapping 4 and 3

------------------------------------------------------
l1=2 u1=2 p=3 l2=3 u2=3 i=3 j=3 sorted arr is:
1 2 3 4 5 6 7 

*/
