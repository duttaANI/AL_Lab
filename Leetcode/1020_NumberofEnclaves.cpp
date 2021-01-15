class Solution {
public:
    
    int H,W,ans=0;
    
    int vis[500][500];
    
    int dX[4] = {0,1, 0,-1};
    int dY[4] = {1,0,-1, 0};
    
    int valid(int x, int y){
        if( x>0 && x<H-1 && y>0 && y<W-1 ){
            return 1; // inside
        }
        else if ( ( x>=0 && x<=H-1 ) && ( y>=0 && y<=W-1 ) ){
            return 2; // on boundry
        }
        else{
            return 0; // outside
        }
    }
    
    void dfs(int x, int y, vector<vector<int>>& A ){
        vis[x][y] = 1; 
        for(int i=0;i<4;++i){
            int nx = x + dX[i];
            int ny = y + dY[i];
           
            if( valid(nx,ny)>0 && !vis[nx][ny] && A[nx][ny]==1  ){
                dfs(nx,ny,A);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& A) {
        H = A.size();
        W = A[0].size();
        
        int j=0,i;
        for( i=0; i<H; ++i){
            if( A[i][j] == 1 && !vis[i][j]  ){
                dfs(i,j, A);
            } 
        }
        
        j=W-1;
        for( i=0; i<H; ++i){
            if( A[i][j] == 1 && !vis[i][j]  ){
                dfs(i,j, A);
            } 
        }
        
        i=0;
        for( j=0; j<W; ++j){
            if( A[i][j]==1 && !vis[i][j] ){
                dfs(i,j,A);
            }
        }
        
        i=H-1;
        for( j=0; j<W; ++j){
            if( A[i][j]==1 && !vis[i][j] ){
                dfs(i,j,A);
            }
        }
        
        for(i=0; i<H; ++i){
            for(j=0; j<W; ++j){
                if( vis[i][j]==0 && A[i][j]==1 ){
                    ++ans;
                }
            }
        }
        
        return ans;
    }
};