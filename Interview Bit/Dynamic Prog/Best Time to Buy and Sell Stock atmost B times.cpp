


int Solution::solve(vector<int> &A, int k) {
  
  int n = A.size();
  
  if(k>A.size())
  k = A.size();
  int dp[k+1][n];
  
  memset(dp,0,sizeof(dp));
  
  for(int i=1;i<=k;i++)
  {
      int prev = INT_MIN;
      for(int j=1;j<n;j++)
      {
          prev = max(prev,dp[i-1][j-1]-A[j-1]);
          dp[i][j] = max(dp[i][j-1],A[j]+prev);
      }
  }
  
  return dp[k][n-1];
  
  
}


