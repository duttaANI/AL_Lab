int Solution::adjacent(vector<vector<int> > &A) {
   
    int n=A[0].size();
    
    if(n==1){
        return max({ A[0][0],A[1][0] });
    }
    if(n==2){
        return max({ A[0][0],A[1][0],A[0][1],A[1][1] });
    }
    int y = max({ A[0][0],A[1][0] });
    int x = max({ A[0][0],A[1][0],A[0][1],A[1][1] });
    
    vector<int> B(n,0);
    // cout << "n " << n << "\n";
    for(int i=0; i<n; ++i){
        B[i] = max( { A[0][i],A[1][i] } );
    }
    
    vector<int> dp(n,0); // dp[i] -> max till ith index
    dp[0] = y;
    dp[1] = x;
    for(int i=2;i<n;++i){
        dp[i] = B[i];
    }
    
    int mx=x;
    for(int i=2; i<n; ++i){
        dp[i] = max( { dp[i-2]+dp[i] , dp[i-1] });
        mx = max({mx,dp[i]});
    }
    
    
    return mx;
}



// Better

int Solution::adjacent(vector<vector<int> > &A) {
    int N = A[0].size();
    
    if( N == 0 )return 0 ; 
    if( N == 1 )return max( A[1][0] , A[0][0] );
    
    int t[N];
    memset( t , 0 , sizeof t );
    
    t[N-1] = max( A[0][N-1] , A[1][N-1] ) ; 
    
    for( int i = N-2 ; i >= 0 ; i-- )
    {
        if( i + 2 >= N )
        t[i] = max(  t[i+1] , max( A[1][i] , A[0][i])  );
        
        else 
        t[i] = max( t[i+1] , max( A[1][i] , A[0][i] ) + t[i+2] );
    }
    return t[0] ;
}
