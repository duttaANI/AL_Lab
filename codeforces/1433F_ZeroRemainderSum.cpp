#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define ar array
#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int mxN = 71;
const int INF = 1e9; 
int n,m,k;
int a[mxN][mxN];
ll dp[mxN][mxN][mxN][mxN];

int main(){
	cin >> n >> m >> k;
	forn(i,n) forn(j,m) cin >> a[i][j];

	forn(i,mxN) forn(j,mxN) forn(cnt,mxN) forn(rem,mxN) dp[i][j][cnt][rem] = -INF;
	dp[0][0][0][0] = 0;

	forn(i,n) forn(j,m) forn(cnt,m/2+1) forn(rem,mxN) {
		if(dp[i][j][cnt][rem]==-INF) continue;
		int ni = (j==m-1?i+1:i);
		int nj = (j==m-1?0:j+1);

		// we don't select the element
		if(ni!=i){ // row changed
			dp[ni][nj][0][rem] = max(dp[ni][nj][0][rem],dp[i][j][cnt][rem]);
		}else{
			dp[ni][nj][cnt][rem] = max(dp[ni][nj][cnt][rem],dp[i][j][cnt][rem]);
		}

		if (cnt + 1 <= m / 2){
			// we select the element
			int nrem = (rem + a[i][j]) % k;
			if(ni!=i){ // row changed
				dp[ni][nj][0][nrem] = max(dp[ni][nj][0][nrem],dp[i][j][cnt][rem]+a[i][j]);
			}else{
				dp[ni][nj][cnt+1][nrem] = max(dp[ni][nj][cnt+1][nrem],dp[i][j][cnt][rem]+a[i][j]);
			}
		}

	}

	cout << max((ll)0,dp[n][0][0][0]);

	return 0;
}