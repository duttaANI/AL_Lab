// top down

int Solution::solve(vector<int> &A) {
    int N = A.size() ;
    
    int t[N][N];
    memset( t , 0 , sizeof t);
    
    int p[N+1]; p[0] = 0  ;
    for( int i = 0 ; i < N ; i++ )p[i+1] = p[i] + A[i];
    
    for( int L = 2 ; L <= N ; L++ )
    for( int i = 0 ; i+L-1<N; i++ )
    {
        int j = i+L-1;
        t[i][j] = INT_MAX ; 
        
        for( int k = i ; k <= j ; k++ )
        t[i][j] = min( t[i][j] , t[i][k] + t[k+1][j] + p[j+1]-p[i] );
    }
    return t[0][N-1];
}
/// 



int dp[201][201];

int helper(vector<int> &A, int i, int j, vector<vector<int>> &S){
    if(j==i) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i; k<j; k++){
        int temp=S[i][k]+S[k+1][j]+helper(A, i, k, S)+helper(A, k+1, j, S);
        ans=min(ans, temp);
    }
    return dp[i][j]=ans;
}

int Solution::solve(vector<int> &A) {
    int N=A.size();
    memset(dp, -1, sizeof(dp));
    
    vector<vector<int>> sum(N, vector<int>(N,0));
    
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            if(i==j) sum[i][j]=A[i];
            else sum[i][j]=A[j]+sum[i][j-1];
        }
    }
    
    return helper(A, 0, N-1, sum);
}



/// better

int Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n==0) 
        return 0;
    
    vector<vector<int>> dp(n,vector<int>(n,0));
    vector<int> sum(n,0);
    sum[0] = A[0];
    
    for(int i=1;i<n;i++)
        sum[i] = sum[i-1] + A[i];
    
    for(int len=1;len<n;len++){
        for(int i=0;i<n-len;i++){
            int j = i+len;
            int add = INT_MAX;
            for(int k=i;k<j;k++)
                add = min(add,dp[i][k] + dp[k+1][j]);
            dp[i][j] = (sum[j]-((i==0)? 0 : sum[i-1])) + add;
        }
    }
    return dp[0][n-1];
}


