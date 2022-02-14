/*



Maintain PrefixSum and SuffixSum for odd and even index seperately.
Let consider the following variable:
leftOdd[i] : Denote the prefixSum of element on odd index till i-1.
leftEven[i] : Denote the prefixSum of element on even index till i-1.
rightOdd[i] : Denote the SuffixSum of element of odd index till i+1.
rightEven[i] : Denote the SuffixSum of element of even index till i+1.

Now, check if the ith element is the special or not.

If leftOdd[i] + rightEven[i] == leftEven[i] + rightOdd[i], then ith element is special, so we increase the count.


*/

int Solution::solve(vector<int> &A) {
    if(!A.size())
        {
            return 0;
        }
        
        int odd = 0;
        int even = 0;
        for(int i = 0; i < A.size(); i++)
        {
            if(i % 2)
            {
                odd += A[i];
            }
            else
            {
                even += A[i];
            }
        }
        
        int count = 0;
        int odd1 = 0;
        int even1 = 0;
        int prev = 0;
        for(int i = (int)A.size() - 1; i >= 0; i--)
        {
            if(i % 2)
            {
                odd1 += prev;
                odd -= A[i];
            }
            else
            {
                even1 += prev;
                even -= A[i];
            }
            prev = A[i];
            if(odd + odd1 == even + even1)
            {
                count++;
            }
        }
        return count;
}
