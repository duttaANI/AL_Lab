#include <bits/stdc++.h>
 
using namespace std;
 

/*
 * Complete the 'maxPathSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY board
 *  2. INTEGER p
 *  3. INTEGER q
 */
 
// int maxPathSum(vector<vector<int>> board, int p, int q) {
    
// }

int maxPathSum(vector<vector<int>> mat , int p ,int q) {


		// cout << " ddd ";

        int n = mat.size();
        int m = mat[0].size();
        if(n==1) return mat[0][0];

        int res ;
        // if(n==2) return max( { mat[0][0],mat[0][1] } ) + max( { mat[1][0],mat[1][1] } );


        //////////
        
        vector<vector<int> > dp(n, vector<int> (m,0)) ;
        
        for(int j=0;j<m; ++j){
        	if(  j==p  ){
        		dp[0][j] = mat[0][j];
        	}
        	else
            dp[0][j] = -10000;
        }
        
        for(int i=1;i<n; ++i){
            for(int j=0; j<m; ++j){
                if(j==0 ){
                    dp[i][j] = mat[i][j]+max({ dp[i-1][j],dp[i-1][j+1] });
                }
                else if(j==m-1){
                    dp[i][j] = mat[i][j]+max({ dp[i-1][j],dp[i-1][j-1] });
                }
                else{
                    dp[i][j] = mat[i][j]+max({ dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1] });
                }
            }
        }
        
        int ans = INT_MIN;
        for(int i=0;i<m;++i){
            ans = max({ans,dp[n-1][i]});
        }

        // cout << ans << " ans \n";



        // // return ans;

        // ///////////


        vector<vector<int> > dp2(n, vector<int> (m,0)) ;
        
        for(int j=0;j<m; ++j){
        	if(  j==q  ){
        		dp2[n-1][j] = mat[n-1][j];
        	}
        	else
            dp2[n-1][j] = -10000;
        }
        
        for(int i=n-2;i>=0; --i){
            for(int j=0; j<m; ++j){
                if(j==0 ){
                    dp2[i][j] = mat[i][j]+max({ dp2[i+1][j],dp2[i+1][j+1] });
                }
                else if(j==m-1){
                    dp2[i][j] = mat[i][j]+max({ dp2[i+1][j],dp2[i+1][j-1] });
                }
                else{
                    dp2[i][j] = mat[i][j]+max({ dp2[i+1][j-1],dp2[i+1][j],dp2[i+1][j+1] });
                }
            }
        }
        
        int ans2 = INT_MIN;
        for(int i=0;i<m;++i){
            ans2 = max({ans2,dp2[0][i]});
        }



        // return ans;

        res = max(ans,ans2);

        // cout << "  hello : " << res << endl;

        return res;

        // return -1;

    }

int main(){

    cout << "  sss ";
	vector<vector<int>> vect
    {
        { 10, 10, 2, 0, 20, 4 },
        { 1, 0, 0, 30, 2, 5 },
        { 0, 10, 4, 0, 2, 0 },
        { 1, 0, 2, 20, 0, 4 }
    };

    int ans = maxPathSum( vect, 0,0 );

    cout << ans << endl;

}


