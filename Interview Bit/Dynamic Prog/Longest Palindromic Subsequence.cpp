int dp[1001][1001];
int Solution::solve(string A) {
    memset(dp,0,sizeof(dp));
    
    int n = A.size();
    
    for(int i=0;i<n;++i) dp[i][i] = 1;
    
    for(int i = n-1; i>=0; --i){
        for(int j = i+1 ; j <n;++j){
            if( A[i]==A[j] ){
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            else{
                dp[i][j] = max({ dp[i+1][j], dp[i][j-1] });
            }
        }
    }
    return dp[0][n-1];
}
