class Solution {
public:
    
    bool vis[50][50];
    int dX[4] = {0,1,0,-1};
    int dY[4] = {1,0,-1,0};
    
    int valid(int x,int y, int N){
        if(x>=0 && y>=0 && x<N && y<N){
            return 1;
        }
        return 0;
    }
    
    void dfs(int mid, int x, int y, int N, vector<vector<int>>& grid){
        vis[x][y]=1;
        for(int i=0;i<4;++i){
            int nx = x + dX[i];
            int ny = y + dY[i];
            if( valid(nx,ny,N) && !vis[nx][ny] && grid[nx][ny]<=mid ){
                dfs(mid,nx,ny,N,grid);
            }
        }
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int l=0,r=n*n;
        
        while(l<r){
            
            int mid = l + (r-l)/2;
            memset(vis,0,sizeof(vis));
            if(!vis[0][0] && grid[0][0]<=mid)
            dfs(mid,0,0,n,grid);
            
//             cout << "mid " << mid << endl;
            
//             for(int i=0;i<n;++i){
//                 for(int j=0;j<n;++j){
//                     cout << vis[i][j] << " ";
//                 }
//                 cout << endl;
//             }
            
//             cout << endl;
            
            if(vis[n-1][n-1]){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};