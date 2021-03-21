#include <bits/stdc++.h>
using namespace std;
#define ar array

int R,C,in[300][300];

// dir
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};

// check in sq

int valid(int x,int y){
	if( x>=0 && y>=0 && x<R && y<C ){
		return 1;
	}
	return 0;
}

// to push or not ?
int p(int x,int y){
	int cnt = 0;
	for(int i=0;i<4;++i){
		int nx = x + dX[i];
		int ny = y + dY[i];
		if( valid(nx,ny) && in[x][y]-in[nx][ny]>1 ){
			++cnt;
		}
	}
	if(cnt>0){
		return 1;
	}
	return 0;
}

int setter(int x,int y){
	int box = 0;
	for(int i=0;i<4;++i){
		int nx = x + dX[i];
		int ny = y + dY[i];
		if( valid(nx,ny) && in[x][y]-in[nx][ny]>1 ){
			box += (in[x][y]-in[nx][ny]-1);
			in[nx][ny] += (in[x][y]-in[nx][ny]-1);
		
			// cout << "box" << box << " ";
		}
	}
	// cout << x << " " << y << " " << box << endl;
	return box;
}


void solve(int cs){
	int ans = 0;


	cin >> R >> C;
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			cin >> in[i][j];
		}
	}

	queue< ar<int,2> > q;

	// multisourse bfs
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			if( p(i,j) ){
				q.push({i,j});
				// cout << i << " " << j << endl;
				// vis[i][j] = 1;
			}
		}
	}

	while(!q.empty()){
		ar<int,2> f = q.front(); q.pop();
		// vis[f[0]][f[1]] = 1;
		ans += setter(f[0],f[1]);
		for(int i=0;i<4;++i){
			int nx = f[0] + dX[i];
			int ny = f[1] + dY[i];
			if( valid(nx,ny) && p(nx,ny) ){
				q.push({nx,ny});
			}
		}
	}

	// for(int i=0;i<R;++i){
	// 	for(int j=0;j<C;++j){
	// 		cout << in[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	cout << "Case #" << cs << ":" << " " << ans << endl;
}

int main(){
	int tt;
	cin >> tt;
	int ttt = tt;
	while(tt--){
		solve(ttt-tt);
	}

	return 0;
}