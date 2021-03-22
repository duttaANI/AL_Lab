#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	ll n,m,k;
	cin >> n >> m >> k;
	ll ans = 0;

	// ist column
	for(ll i=1; i<=n; ++i){
		if( min(i,m) %2 == 1 ){
			ans ^= k + i +1;
		}
	}

	// last row
	for( ll j=2; j<=m; ++j ){
		if( min(n,m-j+1)%2 == 1  ){
			ans ^= k+n+j;
		}
	}
	cout << ans << endl;
}

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}