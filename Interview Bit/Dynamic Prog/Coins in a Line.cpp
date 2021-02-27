const int mxN = 5e3;


int getDiff(vector<int> &A,int dp[][mxN]) {
    int n = A.size();
    for (int i = 0; i < n; i++) { dp[i][i] = A[i]; }
    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            dp[i][j] = max(A[i] - dp[i + 1][j], A[j] - dp[i][j - 1]);
        }
    }

    // for (int i = 0; i < n; ++i)
    // {
    //  for (int j = 0; j < n; ++j)
    //  {
    //      cout << dp[i][j] << " ";
    //  }
    //  cout << "\n";
    // }

    return dp[0][n - 1];
}


int Solution::maxcoin(vector<int> &A) {
    int dp[mxN][mxN]; // dp[x][y] ->  how much more scores that the first-in-action player will get from i to j than the second player.
    int sum=0;
    for(int i=0;i<A.size();++i){
        sum += A[i];
    }
    return (sum+getDiff(A,dp) )/2;
}
