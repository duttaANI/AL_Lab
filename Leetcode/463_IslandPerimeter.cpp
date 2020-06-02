// My code slow 260ms
class Solution {
public:
    
    int dx[4] = {1,0,-1,0} ; int dy[4] = {0,1,0,-1};
    int tot_ones=0;       int twice_of_joint_walls =0 ;
    
    void fill_vis(vector<vector<int>>& grid ,vector<vector<bool>>& visited, int sr, int sc) {
        int x,y;
        visited[sr][sc] = true;
        ++tot_ones;
        for (int i=0; i<4; ++i) {
            x = sr + dx[i]; y = sc + dy[i];
            if (x>=0 && y>=0 && x<visited.size() && y<visited[0].size() && grid[x][y]==1) {
                ++twice_of_joint_walls;
                
                if(!visited[x][y])
                    fill_vis(grid,visited,x,y);
            }
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int h = grid.size(); int w = grid[0].size();
        vector<vector<bool>> visited ( h, vector<bool>(w,0));
        for (int i=0; i<h; ++i) {
            for (int j=0; j<w; ++j) {
                if(grid[i][j]==1 && !visited[i][j])
                {   
                
                    fill_vis(grid,visited,i,j);
                }
            }
        }
        //cout << tot_ones << " " << joint_walls;
        int free_walls = tot_ones*4 - twice_of_joint_walls;
        return free_walls;
    }
};

// Faster solution link: https://leetcode.com/problems/island-perimeter/discuss/373979/C%2B%2B-Easy-solution-simple-beats-98-100-with-explanation

class Solution {
public:
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int res = 0;
        int r = grid.size();
        int c = grid[0].size();
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j] == 1)
                {
                    res += (i == 0 || grid[i-1][j] == 0 ? 1 : 0);
                    res += (i == r-1 || grid[i+1][j] == 0 ? 1 : 0);
                    res += (j == 0 || grid[i][j-1] == 0 ? 1 : 0);
                    res += (j == c-1 || grid[i][j+1] == 0 ? 1 : 0);
                }
            }
        }
        
        return res;
    }
};