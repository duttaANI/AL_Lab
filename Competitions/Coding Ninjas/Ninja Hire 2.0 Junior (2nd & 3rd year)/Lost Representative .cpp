#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e3+13;
#define ar array

int n;

int cnt=0;

int mat[mxN][mxN],vis[mxN][mxN];

int dX[4]= {1,0,-1,0};
int dY[4] = {0,1,0,-1};

bool inside(int x,int y){
    if(x>=0 && x<n && y>=0 && y<n && vis[x][y]==0 && mat[x][y]==1){
        return true;
    }
    return false;
}

void dfs(int si,int sj){
    for(int i=0;i<4;++i){
        int ni = si + dX[i];
        int nj = sj + dY[i];
        if( inside(ni,nj) ){
            ++cnt;
            vis[ni][nj] =1;
            dfs(ni,nj);
        }
    }
}

int main(){
    // write your code
    int tt;
    cin >> tt;
    while(tt--){
        
        cin >> n;
        vector<ar<int,2>> mp;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                vis[i][j]=0;
            }
        }
        for(int i=0;i<n;++i){
            mp.push_back({i,0});
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cin >> mat[i][j];
            }
        }
        int lost;
        cin >> lost;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j]==1 && vis[i][j]==0){
                    vis[i][j]=1;
                    cnt=1;
                    dfs(i,j);
                    mp[cnt] = {i,j};
                    // cout << cnt << " " << i << " " << j << "\n";
                }
            }
        }
        cout << mp[lost][0] << " " << mp[lost][1] << endl;
    }
    return 0;
}