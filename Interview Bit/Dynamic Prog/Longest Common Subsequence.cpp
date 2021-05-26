// top down
    int dp[1001][1001];
    
int Solution::solve(string text1, string text2) {
   
    memset(dp,0,sizeof(dp));

    int n = text1.size();
    int m = text2.size();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(text1[i-1]==text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else{
                dp[i][j] = max({dp[i-1][j],dp[i][j-1]});
            }
        }
    }
    return dp[n][m];

}

// memoization



int dp[1001][1001];

int LCS(string X,string Y, int m,int n){
    if(m==0 || n==0){
        return 0;
    }
    
    if(dp[m][n]!=-1){
        return dp[m][n];
    }

    if( X[m-1] == Y[n-1]  ){
        return dp[m][n]=(1 + LCS( X,Y,m-1,n-1 ));
    }
    else{
        return dp[m][n]=max({  LCS(X,Y,m,n-1) , LCS(X,Y,m-1,n) });
    }
}

    
int Solution::solve(string A, string B) {
    int m = A.size();
    int n = B.size();
    memset(dp,-1,sizeof(dp));
    return LCS(A,B,m,n);
}











// Recursive TLE

int LCS(string X,string Y, int m,int n){
    if(m==0 || n==0){
        return 0;
    }

    if( X[m-1] == Y[n-1]  ){
        return 1 + LCS( X,Y,m-1,n-1 );
    }
    else{
        return max({  LCS(X,Y,m,n-1) , LCS(X,Y,m-1,n) });
    }
}

    
int Solution::solve(string A, string B) {
    int m = A.size();
    int n = B.size();
    return LCS(A,B,m,n);
}