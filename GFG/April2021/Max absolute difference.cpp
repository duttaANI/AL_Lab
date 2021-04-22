class Solution{
    public:
    
    void findMaxSumSubarray(int A[], int aux[], int i, int j, int diff)
    {
        int max_so_far = A[i];
        int max_ending_here = A[i];
        aux[i] = A[i];
     
        for (int k = i + diff; k != j; k += diff)
        {
            // update the maximum sum of subarray "ending" or "starting" at index `k`
            max_ending_here = max(A[k], max_ending_here + A[k]);
     
            // update the result if the current subarray sum is found to be greater
            max_so_far = max(max_so_far, max_ending_here);
            aux[k] = max_so_far;
        }
    }
 
    void fillArrays(int A[], int left_max[], int right_max[],int left_min[], int right_min[], int n)
    {
        findMaxSumSubarray(A, left_max, 0, n - 1, 1);
        findMaxSumSubarray(A, right_max, n - 1, 0, -1);
     
        // negate `A[]` for finding the minimum sum of subarrays using
        // the same logic for finding the maximum sum of subarrays
        transform(A, A + n, A, negate<int>());
     
        // `transform()` is equivalent to
     
        /* for (int i = 0; i < n; i++) {
            A[i] = -A[i];
        } */
     
        findMaxSumSubarray(A, left_min, 0, n - 1, 1);
        findMaxSumSubarray(A, right_min, n - 1, 0, -1);
     
        // negate `left_min[]` and `right_min[]` to get the minimum sum of subarrays
        transform(left_min, left_min + n, left_min, negate<int>());
        transform(right_min, right_min + n, right_min, negate<int>());
     
        // restore the sign of `A[]`
        transform(A, A + n, A, negate<int>());
    }
    
    int findMaxAbsDiff(int A[], int n)
    {
        // Your code goes here
        
        int left_max[n], right_max[n], left_min[n], right_min[n];
        fillArrays(A, left_max, right_max, left_min, right_min, n);
     
        // stores the maximum absolute difference
        int max_abs_diff = INT_MIN;
     
        // do for each index `i` in the array
        for (int i = 0; i < n - 1; i++)
        {
            max_abs_diff = max(max_abs_diff, max(abs(left_max[i] - right_min[i+1]),
                                        abs(left_min[i] - right_max[i+1])));
        }
     
        return max_abs_diff;
    }
};