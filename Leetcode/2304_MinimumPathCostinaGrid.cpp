class Solution {
public:
    // Bottom up DP
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int ans = INT_MAX;
        int H = grid.size();
        int W = grid[0].size();
        
        vector<vector<int>> dp ( H, vector<int> (W,INT_MAX) );
        
        for(int i=0;i<W;++i){
            dp[H-1][i] = grid[H-1][i];
        }
        
        for(int level = H-2;level>=0;--level){
            for(int i=0;i<W;++i){// for row
                for(int j=0;j<W;++j){ // for edges
                    dp[level][i] = min({dp[level][i],dp[level+1][j] + moveCost[grid[level][i]][j]});
                }
                dp[level][i] += grid[level][i];
            }
        }
        
        for(int i=0;i<W;++i){
            ans = min({ans,dp[0][i]});
        }
        return ans;
    }
};