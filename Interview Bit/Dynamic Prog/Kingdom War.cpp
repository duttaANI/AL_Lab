int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int ans = INT_MIN;
    
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    
    ans = dp[n-1][m-1] = A[n-1][m-1];
    for(int i=n-2;i>=0;--i){
        dp[i][m-1] = dp[i+1][m-1] + A[i][m-1];
        ans = max({ans,dp[i][m-1]});
    }
    for(int j=m-2;j>=0;--j){
        dp[n-1][j] = dp[n-1][j+1] + A[n-1][j];
        ans = max({ans,dp[n-1][j]});
    }
    
    
    for(int i = n-2; i>=0; --i){
        for(int j= m-2; j>=0; --j){
            dp[i][j] = A[i][j] + dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1];
            ans = max({ans,dp[i][j]});
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }
    
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<m;++j){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    return ans;
}
