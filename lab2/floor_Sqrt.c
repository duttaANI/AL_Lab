 #include <stdio.h>
#include <stdlib.h>

int floorSqrt(int A) {

    if (A==0 || A==1) return A;
    int start = 0, end = A;
    int ans;
    while(start<=end)
    {
        int mid = start + (end - start)/2;
        if (mid <= A/mid)
        {
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid - 1;
    }
    return ans;
}

int main()
{
    int a , sqrt;
	printf("Enter number for sqrt:\n");
	scanf("%d",&a);

	sqrt = floorSqrt(a);

	printf("sqrt : %d\n",sqrt );
}
