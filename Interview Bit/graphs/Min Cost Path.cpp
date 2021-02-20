#define ar array

int dX[4] = {0,1,0,-1}; // R D L U
int dY[4] = {1,0,-1,0};
char dir[4] = {'R','D','L','U'};

int valid(int x,int y, int n,int m){
    if(x>=0 && y>=0 && x<n && y<m ){
        return 1;
    }
    return 0;
}

int Solution::solve(int A, int B, vector<string> &C) {
    
    int n = C.size();
    int m = C[0].size();
    vector<vector<int>> dis (n, vector<int> (m,INT_MAX) );
    dis[0][0] = 0;
    priority_queue< ar<int,3>, vector<ar<int,3>> , greater<ar<int,3>> >pq;
    pq.push({0,0,0});
    
    while(!pq.empty()){
        int d;
        ar<int,3> frnt = pq.top(); pq.pop();
        if( frnt[0]>dis[frnt[1]][frnt[2]] || (C[frnt[1]][frnt[2]]==' ') ){
            continue;
        }
        char temp = C[frnt[1]][frnt[2]];
        C[frnt[1]][frnt[2]] = ' ';
        
        for( int i=0; i<4; ++i ){
            int nx = frnt[1] + dX[i];
            int ny = frnt[2] + dY[i];
            if( valid(nx,ny,A,B) && dis[nx][ny] > frnt[0] + (d = (temp==dir[i])?0:1) ){
                dis[nx][ny] = frnt[0] + (d = (temp==dir[i])?0:1);
                pq.push({dis[nx][ny],nx,ny});
            }
        }
    }
    
    return dis[A-1][B-1];
}
