#include <bits/stdc++.h>
using namespace std;

int n,m;
const int mxN = 100+10;
int a[mxN][mxN],vis[mxN][mxN];

int main(){
	int tt;
    cin >> tt;
    while(tt--){
        cin >> n >> m;
        for(int i=0; i<n; ++i){
            for(int j=0;j<m;++j){
                cin >> a[i][j];
            }
        }
        for(int i=0;i<n;++i){
        	for(int j=0;j<m;++j){
        		if( ((i+j)%2) && (a[i][j]%2) ){ // Black and odd , black should have even
        			a[i][j]+=1;
        		}
        		if ( !((i+j)%2) && !(a[i][j]%2) ){ // White and even , white should have odd
        			a[i][j]+=1;
        		}
        	}
        }
        for(int i=0; i<n; ++i){
            for(int j=0;j<m;++j){
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}














































// #include <bits/stdc++.h>
// using namespace std;
// #define ar array
// #define ll long long 
// int n,m;
// const int mxN = 100+10;
// int a[mxN][mxN],vis[mxN][mxN];

// int dX = {1,0,-1,0};
// int dY = {0,1,0,-1};

// int check(int x,int y){
//     if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && ( a[i][j]==a[i-1][j] || a[i][j]==a[i+1][j] || a[i][j]==a[i][j-1] || a[i][j]==a[i][j+1] ) ){
//         return true;
//     }
//     return false;
// }

// void dfs(int i, int j){
//     for(int i=0;i<4;++i){
//         int ni = i + dX[i];
//         int nj = j + dY[i];
//         if(check(nx,ny)){
//             vis[nx][ny] = 1;
//             dfs(nx,ny);
//         }
//     }

// }

// int main(){
// 	int tt;
//     cin >> tt;
//     while(tt--){
//         cin >> n >> m;
//         for(int i=0; i<n; ++i){
//             for(int j=0;j<m;++j){
//                 cin >> a[i][j];
//             }
//         }
//         for(int i=0; i<n; ++i){
//             for(int j=0;j<m;++j){
//                 if(!vis[i][j] && check(i,j)){
//                     dfs(i,j);
//                     vis[i][j]=1;
//                 }
//             }
//         }

//     }
// }

