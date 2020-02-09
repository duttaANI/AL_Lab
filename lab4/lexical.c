#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int fact(int n)
{
	int f=1;
	for (int i = 1; i <= n; ++i)
	{
		f=f*i;
	}
	return f;
}

void reverse(int arr[],int largestI,int n)
{
	int temp1;
	int i,j;
	for ( j=0, i = largestI + 1; i < n - j -1 ; ++i,++j)
	{
        
		temp1 = arr[n  - j -1 ];
		arr[n - j - 1] = arr[i];
		arr[i] = temp1;
	}
}

void swap(int arr[], int pos1, int pos2)
{
	int temp;
	temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int draw(int n, int arr[])
{
	int largestI = -1;
	for (int i = 0; i < n - 1 ; ++i)
	{
		if(arr[i]<arr[i+1])
		{
            largestI = i;
		}
	}

	// if(largestI == -1)
	// 	return 

	return largestI;
}

int draw2(int n ,int arr[])
{
    
	for (int i = 0; i < n; ++i)
    {
    	printf("%d\t", arr[i]);
    }
    printf("\n");


	int largestJ = -1;
	int largestI = draw(n,arr);
	//printf("%d\n",largestI );
  
    if(largestI == -1)
    	return 0;

	for (int j = 0; j < n; ++j)
	{
		if( arr[largestI] < arr[j])
		{
			largestJ = j;
		}
	}

	//printf("%d\n",largestJ );

	swap(arr,largestI,largestJ);

	//reverse from largestI + 1 to end

	reverse(arr,largestI,n);

     
	//return 1;
}


int main(void)
{
	int arr[] = {0,1,2};
    int i;
    

	int n = sizeof(arr)/sizeof(int);

	//draw2 will be called n! times

	for ( i = 0; i < fact(n); ++i)
	{
		draw2(n,arr);
	}

	// draw2(n,arr);
	// draw2(n,arr);
 //    draw2(n,arr);
 //    draw2(n,arr);
    // while(draw2(n,arr))
    // {
    // 	// for ( i = 0; i < n; ++i)
    // 	// {
    // 	// 	printf("%d\t", arr[i]);
    // 	// }
    // 	printf("\n");
    // }
    

	return 0;
}

