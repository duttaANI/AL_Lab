/*
I took a while to think why dp[i][j] = dp[i-1][j] + (j >= coins[i-1] ? dp[i][j-coins[i-1]] : 0); 
Here's my thought:
dp[i - 1][j]: means the number of combinations if we compeletly don't use the ith coin

dp[i][j - coins[i - 1]]: we must use at least one of the ith coin, so we expell the ith coin from j (Exclusive, opposite to the upper condition)
*/

/*
dp[i][j] : the number of combinations to make up amount j by using the first i types of coins
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp ( n+1, vector<int> (amount+1,0) );
        dp[0][0] = 1;
        
        for( int i=1; i<=n; ++i ){
            dp[i][0] = 1;
            for(int j=1; j<=amount; ++j){
                dp[i][j] = dp[i-1][j]+ (j>=coins[i-1]?dp[i][j-coins[i-1]]:0 );
            }
        }
        
        
        return dp[n][amount];
    }
};