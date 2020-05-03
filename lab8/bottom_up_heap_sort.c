#include <stdio.h>


void heapify(int h[], int n, int i)
{
	int k,v,heapify,j;

	
		k=i; v = h[k] /*get parent*/; heapify=0;

		while(heapify==0 && 2*k<=n)
		{
			j=2*k; //<*> and check if after swapping @ the swapped position i.e. where prev parent came is a heap
			if(j<n) // there are two children 2*k and 2*k +1
				if(h[j]<h[j+1]) j=j+1; // choose larger child in variable j

			if(v>=h[j])  // is parent greater than larger child?
				heapify=1;
			else // swap parent with larger child
			{
				h[k]=h[j]; // make larger child the parent in array
				k=j;   // so that now j=2*k will update j to 2*j  <*>
				//h[k]=v; // is correct but {not optimal}
			}
		}

		// when heapify =1 put v in its place 
		h[k]=v; // {is optimal }
	

	return ;
}

// main function to do heap sort
void heapSort(int arr[], int n) {
	// Build max heap
	for (int i = n/2 ; i >= 1; i--)
	  heapify(arr, n, i);

	int temp;

	// Heap sort
	for (int i = n ; i >= 1; i--) {
	  //swap(arr[0], arr[i]);
	  temp = arr[1];
	  arr[1]=arr[i];
	  arr[i]=temp;

	  // Heapify root element to get highest element at root again
	  heapify(arr, i-1, 1);

	}
}

void main()
{
	int h[20],i,n;
	printf("Enter the no of ele:\n");
	scanf("%d",&n);
	printf("Enter ele:\n");
	for ( i = 1; i <= n; ++i)
	{
		scanf("%d",&h[i]);
	}
	printf("array is:\n");
	for (i = 1; i <= n; ++i)
	{
		printf("%d\t",h[i] );
	}

	//heap sort
	heapSort(h,n);
	

	printf("\nheap after sorting is: \n");
	for (i = 1; i <= n; ++i)
	{
		printf("%d\t",h[i] );
	}
}

/*
sample i/o:
Enter the no of ele:
6
Enter ele:
1 6 5 9 10 12
array is:
1	6	5	9	10	12	
heap after sorting is: 
1	5	6	9	10	12	

*/
