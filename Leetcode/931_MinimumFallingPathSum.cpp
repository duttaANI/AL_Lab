//931. Minimum Falling Path Sum

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        if(n==1) return mat[0][0];
        if(n==2) return min( { mat[0][0],mat[0][1] } ) + min( { mat[1][0],mat[1][1] } );
        
        vector<vector<int> > dp(n, vector<int> (m,0));
        
        for(int j=0;j<m; ++j){
            dp[0][j] = mat[0][j];
        }
        
        for(int i=1;i<n; ++i){
            for(int j=0; j<m; ++j){
                if(j==0 ){
                    dp[i][j] = mat[i][j]+min({ dp[i-1][j],dp[i-1][j+1] });
                }
                else if(j==m-1){
                    dp[i][j] = mat[i][j]+min({ dp[i-1][j],dp[i-1][j-1] });
                }
                else{
                    dp[i][j] = mat[i][j]+min({ dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1] });
                }
            }
        }
        
        int ans = INT_MAX;
        for(int i=0;i<m;++i){
            ans = min({ans,dp[n-1][i]});
        }
        return ans;
    }
};