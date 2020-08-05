class Solution {
public:
    
    int area(vector<vector<int>>& grid, vector<vector<bool>>& vis,int x, int y){
        /*
        This function returns area of island
        */
        if( x<grid.size() && y<grid[0].size() && !vis[x][y] && grid[x][y]==1 ){
            vis[x][y] = true;
            return area(grid,vis, x+1,y) +
                   area(grid,vis, x-1,y) +
                   area(grid,vis, x,y+1) +
                   area(grid,vis, x,y-1) + 1;
        }
        return 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> vis ( grid.size(), vector<bool> ( grid[0].size() , false) );
        int n = grid.size();
        int maxArea=0,curArea;
        for( int i=0; i<n; ++i ){
            for (int j=0; j<grid[0].size(); ++j){
                if( !vis[i][j] && grid[i][j]==1 ){
                    curArea = area(grid,vis,i,j);
                    // cout << curArea << "\n";
                    if(curArea > maxArea){
                        maxArea = curArea;
                    }
                }
            }
        }
        return maxArea;
    }
};