//MY
class Solution {
public:
    #define ar array
    int H,W;
    int vis[100][100];
    int dX[4] = {0,1,0,-1};
    int dY[4] = {1,0,-1,0};
    
    int valid(int x,int y){
        if( x>=0 && y>=0 && x<H && y<W ){
            return 1;
        }
        return 0;
    }
    
    int bfs( int x, int y, vector<vector<int>>& A ){
        memset(vis,0,sizeof(vis));
        vis[x][y]=1;
        queue< ar<int,2> > q,q2;
        q2.push({ x,y });
        q.push({ x,y });
        
        // fill for multisource bfs
        while( q2.size() ){
            ar<int,2> f = q2.front(); q2.pop();
            // cout << f[0] << " " << f[1] << endl;
            for(int i=0;i<4;++i){
                int nx = f[0] + dX[i];
                int ny = f[1] + dY[i];
                if( valid(nx,ny) && A[nx][ny]==1 && !vis[nx][ny] ){
                    
                    q.push( {nx,ny} );
                    q2.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
        
        // expand 
        int cur = 0;
        while( q.size() ){
            int k = q.size();
            ++cur;
            // cout << k << " k cur " << cur << endl;
            for(int i=0;i<k;++i){
                ar<int,2> f = q.front() ; q.pop() ;
               
                for(int i=0;i<4;++i){
                    int nx = f[0] + dX[i];
                    int ny = f[1] + dY[i];
                    if( valid(nx,ny)  && !vis[nx][ny] ){
                        if( A[nx][ny]==1 ){
                            return cur-1;
                        }
                        q.push( {nx,ny} );
                        vis[nx][ny]=1;
                    }
                }
            }   
        }
        return -1;
    }
    
    

    int shortestBridge(vector<vector<int>>& A) {
        memset( vis,0, sizeof(vis) );
        H = A.size();
        W = A[0].size();
        for( int i=0;i<H;++i ){
            for( int j=0;j<W;++j ){
                if( !vis[i][j] && A[i][j]==1 ){
                    int ans = bfs( i,j, A );
                    return ans;
                }
            }
        }
        return -1;
    }
};


// Link : https://leetcode.com/problems/shortest-bridge/discuss/189293/C%2B%2B-BFS-Island-Expansion-%2B-UF-Bonus
// DFS + Flood Fill + Expand like Djikstra
class Solution {
public:
    // recursively Flood fill only the first island found by colour 2
    int paint(vector<vector<int>>& A, int i, int j) {
        if (i < 0 || j < 0 || i == A.size() || j == A.size() || A[i][j] != 1) return 0;
        A[i][j] = 2;
        return 1 + paint(A, i + 1, j) + paint(A, i - 1, j) + paint(A, i, j + 1) + paint(A, i, j - 1);
    }
    
    bool expand(vector<vector<int>>& A, int i, int j, int cl) {
        if (i < 0 || j < 0 || i == A.size() || j == A.size()) return false;
        if (A[i][j] == 0) A[i][j] = cl + 1; // Apply colour
        return A[i][j] == 1;
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        
        // The below loop breaks when we find first cell of first island
        for (int i = 0, found = 0; !found && i < A.size(); ++i)
            for (int j = 0; !found && j < A[0].size(); ++j) found = paint(A, i, j);

        for (int cl = 2; ; ++cl)  // To keep on changing colours 2,3,4,5...
            for (int i = 0; i < A.size(); ++i)
                for (int j = 0; j < A.size(); ++j) 
                    if (A[i][j] == cl && ((expand(A, i - 1, j, cl) || expand(A, i, j - 1, cl) || 
                        expand(A, i + 1, j, cl) || expand(A, i, j + 1, cl))))
                            return cl - 2;
    }
};
