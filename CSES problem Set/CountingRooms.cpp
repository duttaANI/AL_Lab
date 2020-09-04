#include <bits/stdc++.h>
 
using namespace std;

bool a[1000][1000];  // '.' -> 0 , '#' -> 1

void countRoom( int x, int y, int n, int m ){
	a[x][y] = true;

	if( x+1<=n-1 &&  a[x+1][y]==0) 
		countRoom( x+1,y,n,m );
	if( x-1>=0   &&  a[x-1][y]==0)
		countRoom( x-1,y,n,m );
	if( y+1<=m-1 &&  a[x][y+1]==0)
		countRoom( x,y+1,n,m );
	if( y-1>=0   &&  a[x][y-1]==0)
		countRoom( x,y-1,n,m );
}
 
int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int n,m,ans=0;
	cin >> n >> m;
	
	char ch;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> ch;
			if(ch=='.')
				a[i][j] = 0;
			else
				a[i][j] = 1;
		}
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < m; ++j)
	// 	{
	// 		cout << a[i][j];  
	// 	}
	// 	cout << "\n";
	// }

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(!a[i][j] ){
				++ans;
				countRoom( i,j,n,m );
			}
		}
	}

	cout << ans;

	return 0;
}
