#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "lexical.h"
# define V 10

int cal_sum(int arr[],int n,int mat[][V])
{
	int min_sum=0;
	for (int i = 0; i < n; ++i)
	{
		min_sum = min_sum + mat[arr[i]][i];
	}
	return min_sum;
}

void new_min_sum_array(int arr[],int min_sum_arr[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		min_sum_arr[i] = arr[i];
	}
}

int main()
{
	int n, mat[V][V], arr[V], min_sum_arr[V];

	printf("enter no. of employee:\n");
	scanf("%d",&n);

	//<-------------------- generate array ------------------->
	for (int i = 0; i < n; ++i)
	{
		arr[i]=i;
		min_sum_arr[i]=i;
	}

	printf("Enter matrix width=>employee job_salary=>height\n");
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		scanf("%d",&mat[i][j]);
    	}
    }

    int min_sum = cal_sum(arr, n, mat) ;
    //printf("min_sum =%d\n", min_sum);
    int temp_min_sum;



    for (int i = 0; i < fact(n); ++i)
    {
    	get_next_lexical(n,arr);

        temp_min_sum = cal_sum(arr, n, mat);

    	if(  min_sum > temp_min_sum  )
    	{
            new_min_sum_array(arr,min_sum_arr,n);
            min_sum = temp_min_sum;
    	}
    }

    printf("solution is:\n");
    for (int i = 0; i < n; ++i)
    {
    	printf("%d\t",min_sum_arr[i]);
    }

	return 0;
}
