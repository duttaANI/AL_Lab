class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int sum)
    {
       
        int l, r;

        /* Sort the elements */
        sort(A, A + n);
    
        /* Now fix the first element one by one and find the
           other two elements */
        for (int i = 0; i < n - 2; i++) {
    
            // To find the other two elements, start two index
            // variables from two corners of the array and move
            // them toward each other
            l = i + 1; // index of the first element in the
            // remaining elements
    
            r = n - 1; // index of the last element
            while (l < r) {
                if (A[i] + A[l] + A[r] == sum) {
                    // printf("Triplet is %d, %d, %d", A[i],A[l], A[r]);
                    return true;
                }
                else if (A[i] + A[l] + A[r] < sum)
                    l++;
                else // A[i] + A[l] + A[r] > sum
                    r--;
            }
        }
    
        // If we reach here, then no triplet was found
        return false;
    
    }

};