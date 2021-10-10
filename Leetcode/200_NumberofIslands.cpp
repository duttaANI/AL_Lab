class Solution {
public:
    
    int dX[4] ={0,1,0,-1};
    int dY[4] ={1,0,-1,0};
    
    int H;
    int W;
    
    bool valid(int x, int y){
        if( x>=0 && y>=0 && x<H && y<W  ){
            return 1;
        }
        return 0;
    }
    
    void dfs(int x,int y,vector<vector<char>>& grid, vector<vector<int>>& vis ){
        vis[x][y] = 1;
        for(int i=0;i<4;++i){
            int nx = x + dX[i];
            int ny = y + dY[i];
            if( valid(nx,ny) && grid[nx][ny]=='1' && !vis[nx][ny]  ){
                dfs(nx,ny,grid,vis);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        
        H = grid.size();
        W = grid[0].size();
        
        vector<vector<int>> vis( H , vector<int> (W,0) );
        
        for(int i=0;i<H;++i){
            for(int j=0;j<W;++j){
                if(!vis[i][j] && grid[i][j]=='1'  ){
                    ++ans;
                    dfs(i,j,grid,vis);
                }
            }
        }
        
        return ans;
    }
};


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
