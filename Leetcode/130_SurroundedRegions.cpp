// My approach BFS

#define ar array
class Solution {
public:
    
    
    int H,W;
    int dX[8] = {0,1,0,-1};
    int dY[8] = {1,0,-1,0};

    bool valid(int x, int y ){
        if(x>=0 && y>=0 && x<H && y<W){
            return 1;
        }
        return 0;
    }

    void bfs(int a, int b, vector<vector<char> > &A, vector<vector<int>>& vis){
        queue<ar<int,2>> q;
        vis[a][b] = 1;
        q.push({a,b});

        while(!q.empty()){
            ar<int,2> frnt = q.front(); q.pop();
            for(int i=0; i<4; ++i){
                int nx = frnt[0] + dX[i];
                int ny = frnt[1] + dY[i];
                if( valid(nx,ny) && !vis[nx][ny] && A[nx][ny]=='O' ){
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& A) {
        H = A.size();
        W = A[0].size();
        vector<vector<int>> vis ( H, vector<int> (W,0)  ); // vis = 

        for(int i=0;i<H;++i){
            if(A[i][0]=='O'){
                if(!vis[i][0])
                    bfs(i,0,A,vis);
            }
            if(A[i][W-1]=='O'){
                if(!vis[i][W-1])
                    bfs(i,W-1,A,vis);
            }
        }

        for(int j=0;j<W;++j){
            if(A[H-1][j]=='O'){
                if(!vis[H-1][j])
                    bfs(H-1,j,A,vis);
            }
            if(A[0][j]=='O'){
                if(!vis[0][j])
                    bfs(0,j,A,vis);
            }
        }
        // change all non visted 'O' to 'X'
        for(int i=0;i<H;++i){
            for(int j=0;j<W;++j){
                if(A[i][j]=='O' && !vis[i][j]){
                    A[i][j] = 'X';
                }
            }
        }
    }
};



class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            check(board, i, 0);             // first column
            check(board, i, col - 1);       // last column
        }
        for (int j = 1; j < col - 1; ++j) {
            check(board, 0, j);             // first row
            check(board, row - 1, j);       // last row
        }
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '1') board[i][j] = 'O';
    }
    
    void check(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = '1';
            if (i > 1) check(board, i - 1, j);
            if (j > 1) check(board, i, j - 1);
            if (i + 1 < board.size()) check(board, i + 1, j);
            if (j + 1 < board[0].size()) check(board, i, j + 1);
        }
    }
};
