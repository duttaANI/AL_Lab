#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 300, INF = 1e9;
int a[mxN];
int n;
int dp[mxN+1][2*mxN+1];

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		cin >> n;
		for(int i=0; i<n; ++i){
			cin >> a[i];
			--a[i]; // convert to 0th indexing
		}
		sort(a, a+n);
		for(int i=0; i<=n; ++i){
			for(int t=0; t<=2*n; ++t){
				dp[i][t] = INF;
			}
		}
		dp[0][0] = 0;
		for(int i=0; i<=n; ++i){
			for(int t=0; t<=2*n; ++t){
				if(dp[i][t]<INF){
					if(i<n)
						dp[i+1][t+1] = min( dp[i+1][t+1],dp[i][t] + abs(a[i]-t) ); // select dish
					dp[i][t+1] = min( dp[i][t+1], dp[i][t]); // do not select dish
				}
			}
		}
		cout << dp[n][2*n-1] << endl;
	}
	return 0;
}