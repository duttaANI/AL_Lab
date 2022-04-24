int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), l = 0, r = 0, res = 0, sum = A[0];
    while(l < n && r < n)
    {
        if(sum < B)
        {
            r++;
            if(r >= l)
                res += (r - l);
            if(r < n)
                sum += A[r];
        }
        else
        {
            sum -= A[l];
            l++;
        }
    }
    return res;
}