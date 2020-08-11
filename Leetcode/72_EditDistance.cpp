// O(n) space

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size(), pre;
        vector<int> cur(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            cur[j] = j;
        }
        for (int i = 1; i <= m; i++) {
            pre = cur[0];
            cur[0] = i;
            for (int j = 1; j <= n; j++) {
                int temp = cur[j];
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = pre;
                } else {
                    cur[j] = min(pre, min(cur[j - 1], cur[j])) + 1;
                }
                pre = temp;
            }
        }
        return cur[n];
    }
};

/*
link : https://www.youtube.com/watch?v=We3YDTzNXEk
Diagonal ( EDIT )
Left ( DELETE )
Top  ( INSERT )
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int H = word2.length();
        int W = word1.length();
        vector<vector<int>> dp (H+1, vector<int> (W+1,0));
        dp[0][0] = 0;
        for(int i=1; i<=H; ++i){
            dp[i][0] = i;
        }
        for(int i=1; i<=W; ++i){
            dp[0][i] = i;
        }
        
        for(int i=1; i<=H; ++i){
            for(int j=1; j<=W; ++j){
                if(word2[i-1]==word1[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j] = min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]})+1;
                }
            }
        }
        return dp[H][W];
    }
};