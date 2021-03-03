int Solution::minPathSum(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size();
    int dp[n][m];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            dp[i][j] += A[i][j];
            if(i > 0 && j > 0) dp[i][j] += min(dp[i-1][j], dp[i][j-1]); // left and top
            else if(i>0) dp[i][j] += dp[i-1][j]; //for 1st row 0th col ele
            else if(j>0) dp[i][j] += dp[i][j-1]; // for 1st col 0th row ele
        }
    }
    return dp[n-1][m-1];
}
