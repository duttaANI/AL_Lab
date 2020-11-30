#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

bool cmp(ar<ll,2> a,ar<ll,2> b){
	return a[0]>b[0];
}

void solve(){
	ll n;
	cin >> n;
	vector<ar<ll, 2>> val;
	for (long long i = 2; i * i <= n; ++i) {
		int cnt = 0;
		while (n % i == 0) {
			++cnt;
			n /= i;
		}
		if (cnt > 0) {
			val.push_back({cnt, i});
		}
	}
	if (n > 1) {
		val.push_back({1, n});
	}
	sort(val.begin(), val.end(),cmp); // descending order
	vector<long long> ans(val[0][0], val[0][1]);
	for (int i = 1; i < int(val.size()); ++i) {
		for (int j = 0; j < val[i][0]; ++j) {
			ans.back() *= val[i][1];
		}
	}

	cout << ans.size() << endl;
	for (auto it : ans) cout << it << " ";
	cout << endl;
}

int32_t main(){
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}

	return 0;
}