#define ar array
class Solution {
public:
    
    int H,W;
    
    int dX[8] = {0,-1,0,1,1,-1,-1,1};
    int dY[8] = {-1,0,1,0,1,-1,1,-1};
    
    bool valid(int x,int y){
        if(x>=0 && y>=0 && x<H && y<W){
            return 1;
        }
        return 0;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        H = grid.size();
        W = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(H , vector<int> (W,0));
        queue<ar<int,2>> q;
        
        if(grid[0][0]==0){
            q.push({0,0});
            vis[0][0] = 1;
        }
            
        while(q.size()){
            int k = q.size();
            // cout << " k " << k << endl;
            ++ans;
            for(int i=0;i<k;++i){
                ar<int,2> f = q.front(); q.pop();
                // cout << "f " << f[0] << " " << f[1] << endl;
                if(f[0]==H-1 && f[1]==W-1) return ans;
                for(int j=0;j<8;++j){
                    int nx = f[0] + dX[j];
                    int ny = f[1] + dY[j];
                    if( valid(nx,ny) && grid[nx][ny]==0 && !vis[nx][ny] ){
                        q.push({nx,ny});
                        // cout << " nx , ny " << nx  << " " << ny << endl;
                        vis[nx][ny]=1;
                    }
                }
            }
        }
        return -1;
    }
};