int Solution::isMatch(const string a, const string b) {
    int m,n;
    int i,j;
    
    m = a.size();
    n = b.size();
    
    vector<vector<bool>> dp(m+1 , vector<bool>(n+1));
    dp[0][0] = true;
    
    for(i=1;i<=m;i++) dp[i][0] = false;
    for(j=1;j<=n;j++)
    {
        if(b[j-1]=='*') dp[0][j] = dp[0][j-2];
        else dp[0][j] = false;
    }
    
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i-1] == b[j-1] || b[j-1]=='.')
                dp[i][j] = dp[i-1][j-1];
            else if(b[j-1]=='*')
            {
                if(a[i-1]==b[j-2] || b[j-2]=='.')
                    dp[i][j] = dp[i][j-2] || dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-2];
            }
            else
                dp[i][j] = false;
        }
    }
    
    return dp[m][n];
}
