const int mxN = 1e3;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};



int valid(int x,int y, int n, int m){
    if( x>=0 && y>=0 && x<n && y<m ){
        return 1;
    }
    return 0;
}

void dfs(int x, int y,vector<string> &A,int n,int m,int vis[mxN][mxN]){
    vis[x][y] = 1;
    for(int i=0; i<4;++i){
        int nx = x + dX[i];
        int ny = y + dY[i];
        if( valid(nx,ny,n,m) && !vis[nx][ny] && A[nx][ny]=='X' ){
            dfs(nx,ny,A,n,m,vis);
        }
    }
}

int Solution::black(vector<string> &A) {
    int n,m,ans=0;

    int vis[mxN][mxN] = {0};
    n = A.size();
    m = A[0].size();
    
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(A[i][j] == 'X' && !vis[i][j] ){
                ++ans;
                dfs(i,j,A,n,m,vis);
            }
        }
    }
    return ans;
}
