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