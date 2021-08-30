int Solution::solve(vector<int> &A) {
    int N=A.size();
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        // from observation: frequency of 
        // number at i-th index will be (i + 1) * (N - i) 
        int freq = (i + 1) * (N - i);
        // if frequency is odd, then include it in the result
        if (freq % 2 == 1) res = res ^ A[i];
    }
    return res;
}