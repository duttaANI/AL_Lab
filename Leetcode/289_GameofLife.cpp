// my solution
class Solution {
public:
    
    int n,m;
    int dX[8] = {1,0,-1,0, 1,-1,-1,1};
    int dY[8] = {0,1,0,-1, 1,-1,1,-1};
    
    int valid(int x, int y){
        if( x>=0 && y>=0 && x<n && y<m ){
            return 1;
        }
        return 0;
    }
    
    int live_neig( int x, int y, vector<vector<int>>& board ){
        int res=0;
        for(int i=0; i<8; ++i){
            int nx = x + dX[i];
            int ny = y + dY[i];
            if( valid(nx,ny) && board[nx][ny]==1 ){
                ++res;
            }
        }
        return res;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>> res( n, vector<int> (m,0) );
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                int neigh = live_neig(i,j,board);
                if(neigh < 2 && board[i][j]==1 ){
                    res[i][j]= 0;
                }
                else if( (neigh == 2 || neigh==3) && board[i][j]==1 ){
                    res[i][j]= 1;
                }
                else if( neigh>3 && board[i][j]==1 ){
                    res[i][j]= 0;
                }
                else if( neigh==3 && board[i][j]==0 ){
                    res[i][j] = 1;
                }
            }
        }
        
        for(int i=0; i<n;++i){
            for(int j=0; j<m;++j){
                board[i][j] = res[i][j];
            }
        }
        return ;
    }
};