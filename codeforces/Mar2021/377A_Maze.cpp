#include <bits/stdc++.h>
using namespace std;
#define ar  array

int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};

int n,m,k;

stack< ar<int,2>> s;

void dfs(int x,int y,vector<vector<char>> & g, vector<vector<int>>& vis){
	vis[x][y] = 1;
	s.push({x,y});

	// cout << x << " " << y << endl;
	for(int i=0;i<4;++i){
		int nx = x + dX[i];
		int ny = y + dY[i];
		if( nx>=n || ny>=m || nx<0 || ny<0 ) continue;
		if(!vis[nx][ny] && g[nx][ny]=='.')
			dfs(nx,ny,g,vis);
	}

}

int main(){
	
	cin >> n >> m >> k;

	vector<vector<char>> g(n , vector<char> (m));
	vector<vector<int>> vis ( n, vector<int> (m,0) );
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<m;++j){
			cin >> g[i][j]; 
		}
	}
	int flag  = 1;
	for(int i=0; i<n && flag; ++i){
		for(int j=0;j<m && flag; ++j){
			if(!vis[i][j] && g[i][j]=='.'){
				dfs(i,j,g,vis);
				flag = 0;
			}
		}
	}

	for(int i=0; i<k; ++i){
		ar<int,2> t = s.top(); s.pop();
		g[t[0]][t[1]] = 'X';
	}

	for(int i=0;i<n;++i){
		for(int j=0;j<m; ++j){
			cout << g[i][j];
		}
		cout << endl;
	}

	return 0;
}