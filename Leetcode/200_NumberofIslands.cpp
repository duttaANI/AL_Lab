#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
class Solution {
public:
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, 1, 0, -1};
    void dfs (int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i > grid.size()-1 || j > grid[0].size()-1 || visited[i][j] || grid[i][j] == '0') return;
        visited[i][j] =true;
        for (int k=0; k<4; k++) {
            dfs(i+x[k], j+y[k], grid, visited);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        fastIO;
        
        if (!grid.size()) return 0;
        int h = grid.size(); 
        int w = grid[0].size(); 
        int ans=0;
        
        vector<vector<bool>> visited ( h , vector<bool> (w,false));
        
        for (int i=0; i<h; ++i) {
            for(int j=0; j<w; ++j) {
                if(grid[i][j]=='1' && !visited[i][j]) {
                    dfs(i,j,grid,visited);
                    ++ans;
                } 
            }
        }
        return ans;
    }
};
