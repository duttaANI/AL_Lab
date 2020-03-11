#include <stdio.h>
#include <stdlib.h>

void printer(int x, int* h)
{
	printf("i=%d\n",x);
	for (int i = 1; i <= x; ++i)
	{
		printf("%d\t", h[i]);
	}
}

int get_parent(int i)
{
	if(i%2==0)
		return i/2;
	return (i-1)/2;
}

void make_heap(int parent , int* h) // makes heap among parent and its children
{
	int l_child = 2*parent;
	int r_child = l_child + 1;
	int temp;
	int max_child = h[l_child]>h[r_child]?l_child:r_child;

	if(h[max_child] > h[parent]){
		temp=h[parent] ;
		h[parent]=h[max_child];
		h[max_child]=temp; 
	}

    return ;
}

int main()
{
	int heap1[20]={-9999};
	int ele;
	printf("Enter no. of ele:\n");
	scanf("%d",&ele);
    int parent_calc;
	printf("Enter  ele:\n");
	for (int i = 1; i <= ele; ++i)
	{
		scanf("%d",&heap1[i]);

        if(i>1){
        	parent_calc = i;
            while(parent_calc>1)
            {
            	make_heap(get_parent(parent_calc),heap1);
            	parent_calc = get_parent(parent_calc);
            }
        }
        printer(i,heap1);
	}
    
	

    return 0;
}
