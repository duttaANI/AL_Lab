bool solve(const string A, const string B, int n, int m){
    bool dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    
    if(m == 0){
        return (n == 0);
    }
    
    for(int i = 1; i <= m; i++){
        if(B[i-1] == '*'){
            dp[0][i] = dp[0][i-1];
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(A[i-1] == B[j-1] || B[j-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(B[j-1] == '*'){
                dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    
    return dp[n][m];
}
 
int Solution::isMatch(const string A, const string B) {
    int n = A.length(), m = B.length();
    //memset(dp, 0, sizeof(dp));
    if(solve(A, B, n, m)){
        return 1;
    }
    return 0;
}

// Memory limit exceeded
int Solution::isMatch(const string A, const string B) {
    int m = A.length();
    int n = B.length();
 
    vector<vector<bool>> matched(m+1, vector<bool>(n+1,false));
    matched[0][0]=true;
    for(int i=0;i<B.length();i++){
        if(B[i]=='*')
          matched[0][i+1]=matched[0][i];
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(A[i-1]==B[j-1]||B[j-1]=='?')
                matched[i][j]=matched[i-1][j-1];
            else if(B[j-1]=='*'){
                matched[i][j]=matched[i][j-1]||matched[i-1][j];//0 or more
            }
            else 
                matched[i][j]=false;
        }
    }
  return matched[m][n];
}
