int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    if(n==0 ) return 0;
    if(A[0][0]==1) return 0;
    
    vector<vector<int>> dp (n, vector<int> (m,0));
    dp[0][0]=1;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if( i==0 && j!=0 && A[i][j]==0 ){
                dp[i][j] = dp[i][j-1];
            }
            if( j==0 && i!=0 && A[i][j]==0 ){
                dp[i][j] = dp[i-1][j];
            }
            if( i>0 && j>0 ){
                if(A[i][j]==0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else
                    dp[i][j] = 0;
            }
        }
    }
    return dp[n-1][m-1];
}
