int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    
    int dp[n+1][C+1];
    
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=C;j++){
        dp[0][j] = 0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=C;j++){
            if(B[i-1] <= j){
                dp[i][j] = max(A[i-1] + dp[i-1][j-B[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][C];
}

/*

int n = A.size();
    vector<vector<int>> dp( n, vector<int> (C,0) ); // Suppose dp[i][j] represents the maximum value that can be obtain considering first i items and a knapsack with a capacity of j.
    
    dp[0][0]=0;
    
    for(int i=0; i<n ;++i){
        for(int j=0;j<C;++j){
            if(i>0){
                if(  j-B[i]>=0 )
                    dp[i][j] = max( dp[i-1][j], dp[i-1][j-B[i]]+A[i] );
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    return dp[n-1][C-1];
*/
