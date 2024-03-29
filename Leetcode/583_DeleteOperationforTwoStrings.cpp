

class Solution {
public:
    int dp[1001][1001];
    int minDistance(string text1, string text2) {
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
        return n+m-2*dp[n][m];
    }
};