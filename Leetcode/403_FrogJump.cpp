// link : https://www.youtube.com/watch?v=oTCPG1ezlKc&feature=youtu.be
class Solution {
public:
    
    bool dp[2001][2001];  // i-> stones index , j -> K value 
    
    bool canCross(vector<int>& stones) {
        int n = stones.size() ;
        
        dp[0][1] = true;
        
        for(int i=1; i<n ; ++i){
            for(int j=0; j<i; ++j){
                int diff = stones[i] - stones[j];
                if(diff < 0 || diff > n || !dp[j][diff]) continue;
                dp[i][diff] = true;
                if(diff - 1 >= 0) dp[i][diff - 1] = true;
                if(diff + 1 <= n) dp[i][diff + 1] = true;
                if(i == n - 1) return true;
            }
        }
        
        // for(int i=0;i<n;++i){
        //     for(int j=0;j<n;++j){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        
        
        return false ;
    }
};