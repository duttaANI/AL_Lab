int kp(vector<int> &A,int n,int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(j>=A[i-1]){
                dp[i][j]=max(A[i-1]+dp[i-1][j-A[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int Solution::solve(vector<int> &A) {
    int n=A.size(),sum=0;
    for(int a=0;a<n;a++){
        sum+=A[a];
    }
    return sum-(2*(kp(A,n,sum/2))); 
}