int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    long long int dp[n][m];
    memset(dp,0,sizeof(dp));
    
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            
            if(i+1<n && j+1<m) dp[i][j]+=max(dp[i+1][j],dp[i][j+1]);
            else if(i+1<n) dp[i][j]+=dp[i+1][j];
            else if(j+1<m) dp[i][j]+=dp[i][j+1];
            
            dp[i][j]+=A[i][j];
            if(dp[i][j]>0) dp[i][j]=0;
        }
    }
    return (1+abs(dp[0][0]) );
}
