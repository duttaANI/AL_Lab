int dX[8] = {0,1,0,-1,1,-1,1,-1};
int dY[8] = {1,0,-1,0,1,-1,-1,1};

const int mxN = 100 + 17;
int n,m;

bool check(int i,int j, vector<vector<int> > &A, int vis[][mxN]){
    if(i<n && i>=0 && j<m && j>=0 && vis[i][j]==0 && A[i][j]==1 ){
        return true;
    }
    return false;
}

void dfs(int x, int y,vector<vector<int> > &A , int &cur, int vis[mxN][mxN]){
    
    for(int i=0; i<8;++i){
        int nx = x + dX[i];
        int ny = y + dY[i];
        if( check(nx,ny,A,vis) ){
            vis[nx][ny] = 1;
            cur += 1;
            dfs(nx,ny,A,cur,vis);
        }
    }
}

int Solution::solve(vector<vector<int> > &A) {
    n = A.size();
    m = A[0].size();
    int ans=0,cur=0;
    int vis[mxN][mxN];
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(vis[i][j]==0 && A[i][j]==1){
                vis[i][j] = 1;
                cur = 1;
                dfs(i,j,A,cur,vis);
                ans = max({ans,cur});
            }
        }
    }
    // for(int i=0 ; i<n;++i){
    //     for(int j=0;j<m; ++j){
    //         cout << vis[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return ans;
}
