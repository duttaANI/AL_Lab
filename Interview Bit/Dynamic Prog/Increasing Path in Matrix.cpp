int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    if(n==0) return 0;
    vector<vector<int>> dp (n, vector<int> (m,0));
    
    dp[0][0]=1;
    
    int flg=1;
    for(int i=1;i<n;++i){
        if(flg && A[i][0]>A[i-1][0]){
            dp[i][0] = 1;
        }
        else{
            flg=0;
        }
    }
    
    for(int i=1;i<m;++i){
        if(!flg && A[0][i]>A[0][i-1]){
            dp[0][i] = 1;
        }
        else{
            flg=1;
        }
    }
    
    for(int i=1;i<n;++i){
        for(int j=1;j<m;++j){
            if(A[i][j] > A[i][j-1])
            dp[i][j] = max(dp[i][j], dp[i][j-1]  );
            if(A[i][j] > A[i-1][j])
            dp[i][j] = max(dp[i][j], dp[i-1][j]  );
        }
    }
    if(dp[n-1][m-1]>0){
        return n+m-1;
    }
    return -1;
}
