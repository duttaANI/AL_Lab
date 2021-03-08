#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll n,k;



void solve(){
	ll p;
	cin >> n >> k >> p;
	vector <int> a (n,0),b(k,0);

	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	sort(a.begin(),a.end());

	for(int i=0;i<k;++i){
		cin >> b[i];
	}
	sort(b.begin(),b.end());

	const ll inf = 1e17;
	// ll dp[k+1][n+1]; // dp[position of key][last person] min cost
	vector<vector<ll>> dp ( k+1 , vector<ll> ( n+1,inf ) );
	// for (int i = 0; i <= k; ++i)
	// {
	// 	for(int j=0;j<n;++j){
	// 		dp[i][j] = inf;
	// 	}
	// }

	dp[0][0] = 0; // base case

	for (ll i = 0; i < k; ++i)
	{
		for(ll j=0;j<=n;++j){
			// dont take key
			dp[i+1][j] = min({ dp[i+1][j], dp[i][j] });

			//do take key
			if(j<n){
				dp[i+1][j+1] = min( dp[i+1][j+1], max(dp[i][j] , abs( a[j]-b[i] ) + abs(b[i]-p) ) );
			}
		}
	}

	cout << dp[k][n] << endl;
}

int main(){
	int tt;
	// cin >> tt;
	tt = 1;
	while(tt--){
		solve();
	}
	return 0;
}