const int mxN = 1e3 + 5;
#define ar array

int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};

int vis[mxN][mxN];

int H,W;

bool valid(int x,int y){
    // cout << x << " " << y << " " << H << " " << W << endl;
    if( x>=0 && y>=0 && x<H && y<W ){
        return 1;
    }
    return 0;
}

int Solution::checkPath(vector<vector<int> > &A) {
    H = A.size();
    W = A[0].size();
    
    memset(vis,0,sizeof(vis));
    
    // get src / dst
    ar<int,2> src,dst;
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            if(A[i][j]==1){
                src = {i,j};
            }
            if(A[i][j]==2){
                dst = {i,j};
            }
        }
    }
    
    // cout << src[0] << " src " << src[1] << endl;
    // cout << dst[0] << " dst " << dst[1] << endl;
    
    // BFS
    queue< ar<int,2> > q;
    q.push(src);
    vis[src[0]][src[1]] = 1;
    
    while(q.size()){
        ar<int,2> f = q.front(); q.pop();
        for(int i=0;i<4;++i){
            int nx = f[0] + dX[i];
            int ny = f[1] + dY[i];
            // cout << nx << " " << ny << " " << valid(nx,ny) << endl;
            
            if(valid(nx,ny) && (A[nx][ny]!=0 ) && !vis[nx][ny]){
                // cout << nx << " in if " << ny << endl;
                vis[nx][ny]=1;
                if(nx==dst[0] && ny==dst[1]) return 1;
                q.push({nx,ny});
            }
        }
    }
    
    if(vis[dst[0]][dst[1]]==1) return 1;
    return 0;
    
}
