class Solution {
public:
    
    int dX[4] = {0,1,0,-1};
    int dY[4] = {1,0,-1,0};
    
    unordered_map < int,int > mp; // < color , size >
    
    static const int mxN = 500;
    int vis[mxN][mxN];
    int c[mxN][mxN];
    
    int color = 1;
    
    int n,m;
    
    int sz = 0;
    
    void dfs(int x,int y, int &sz, vector<vector<int>>& g){
        vis[x][y] = 1;
        c[x][y] = color;
        ++sz;
        for(  int i=0;i<4;++i ){
            int nx = x + dX[i];
            int ny = y + dY[i];
            if( valid(nx,ny) && !vis[nx][ny] && g[nx][ny]==1  ){
                dfs(nx,ny,sz,g);
            }
        }
    }
    
    int largestIsland(vector<vector<int>>& g) {
        
        n = g.size();
        m = g[0].size();
        
        int ans = 0;
        int cur= 0;
        
        // case where are cells are 1
        
        int flg = 0;

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if( g[i][j]==0 ){
                    flg = 1;
                    break;
                }
            }
        }
        
        if( !flg ){
            return n*m;
        }
        
        //
        
        for(  int i=0; i<n; ++i ){
            for(  int j =0; j<m; ++j ){
                if(  g[i][j] ==1 && !vis[i][j]  ){
                    sz=0;
                    ++color;
                    dfs(i,j,sz,g);
                    mp[color] = sz;
                }
            }
        }
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if( g[i][j]==0 ){
                    cur=0;
                    
                    set<int> colors;
                    for(int k=0;k<4; ++k){
                        int ni = i + dX[k];
                        int nj = j + dY[k];
                        
                        if(  valid(ni,nj) && mp.find(c[ni][nj])!=mp.end() ){
                            
                            colors.insert(c[ni][nj]);
                        }
                    }
                    
                    for( auto k : colors ){
                        cur += mp[k];
                    }
                    
                    ans = max(ans,cur);
                }
            }
        }
        
        return ans+1;
    }
    
    bool valid(int x,int y){
        if( x>=0 && y>=0 && x<n && y<m ){
            return 1;
        }
        return 0;
    }
};
