#define ar array

int dX[8] = {0,1,0,-1};
int dY[8] = {1,0,-1,0};

int valid(int x, int y, int n, int m){
    if(x>=0 && y>=0 && x<n && y<m){
        return 1;
    }
    return 0;
}

void bfs(int a, int b, vector<vector<char> > &A, vector<vector<int>>& vis, int n , int m){
    queue<ar<int,2>> q;
    vis[a][b] = 1;
    q.push({a,b});
    
    while(!q.empty()){
        ar<int,2> frnt = q.front(); q.pop();
        for(int i=0; i<8; ++i){
            int nx = frnt[0] + dX[i];
            int ny = frnt[1] + dY[i];
            if( valid(nx,ny,n,m) && !vis[nx][ny] && A[nx][ny]=='O' ){
                q.push({nx,ny});
                vis[nx][ny] = 1;
            }
        }
    }
}

void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> vis ( n, vector<int> (m,0)  ); // vis = 
    
    for(int i=0;i<n;++i){
        if(A[i][0]=='O'){
            if(!vis[i][0])
                bfs(i,0,A,vis,n,m);
        }
        if(A[i][m-1]=='O'){
            if(!vis[i][m-1])
                bfs(i,m-1,A,vis,n,m);
        }
    }
    
    for(int j=0;j<m;++j){
        if(A[n-1][j]=='O'){
            if(!vis[n-1][j])
                bfs(n-1,j,A,vis,n,m);
        }
        if(A[0][j]=='O'){
            if(!vis[0][j])
                bfs(0,j,A,vis,n,m);
        }
    }
    // change all non visted 'O' to 'X'
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(A[i][j]=='O' && !vis[i][j]){
                A[i][j] = 'X';
            }
        }
    }
}
