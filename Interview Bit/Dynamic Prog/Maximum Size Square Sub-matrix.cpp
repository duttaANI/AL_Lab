int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    
    int ans=0;
    
    vector<vector<int> > dp(n, vector<int> (m,0) );
    
    for(int i=0;i<n;++i){
        dp[i][0] = A[i][0];
        ans = max(ans,dp[i][0]);
    }
    
    for(int j=0; j<m; ++j){
        dp[0][j] = A[0][j];
        ans = max(ans,dp[0][j]);
    }
    
    for(int i=0;i<n;++i){
        for(int j=0; j<m;++j){
            if( i>0 && A[i-1][j-1] && A[i][j-1] && A[i-1][j] && A[i][j] ){
                dp[i][j] = min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]}) +1;
                ans = max(ans,dp[i][j]);
            }
            else if(i>0){
                dp[i][j] = A[i][j];
            }
        }
    }
    
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<m; ++j){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    return ans*ans;
}
