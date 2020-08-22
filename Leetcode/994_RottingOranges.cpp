// link : https://leetcode.com/problems/rotting-oranges/discuss/238579/C%2B%2BJava-with-picture-BFS
class Solution { 
public:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) rotten.push({i, j});
            }
        }
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k; 
            while(k--){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i < 4; ++i){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            if(!rotten.empty()) days++;
        }
        
        return tot == cnt ? days : -1;
    }
};

// following wont work-

class Solution {
    
public:
    int dx[4] = {1,0,-1,0}; int dy[4] = {0,1,0,-1}; 
    int minutes = 0;
    
    int orangesRotting(vector<vector<int>>& grid) {
        int H = grid.size();
        int W = grid[0].size();
        vector<vector<bool>> visited (grid.size(), vector<bool> (grid[0].size(), false));
        
        for( int i=0; i<H; ++i ){
            for(int j=0; j<W; ++j){
                if( grid[i][j]==2 )
                    floodFill( grid,2,1,i,j,visited );
            }
        }
        for( int i=0; i<H; ++i ){
            for(int j=0; j<W; ++j){
                if( grid[i][j]==1 )
                {
                    return -1;
                }
            }   
        }
        return minutes;
    }
    
    void floodFill (vector<vector<int>>& grid, int newColor, int oldColor, int sr, int sc, vector<vector<bool>>& visited) {
        grid[sr][sc] = newColor;
        visited[sr][sc] =true;
        int x,y;
        int inc = 0;
        for (int i=0; i<4; ++i) {
            x = sr + dx[i]; y = sc + dy[i];
            
            if( x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y] == 1 && !visited[x][y] )
            {  
               ++inc;
            }
        }
       
        
        for (int i=0; i<4; ++i) {
            x = sr + dx[i]; y = sc + dy[i];
            
            if( x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]==oldColor && !visited[x][y])
            {  
                floodFill(grid, newColor, oldColor, x, y, visited);
            }
        }
    }
};