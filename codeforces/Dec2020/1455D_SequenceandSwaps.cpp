#include <bits/stdc++.h>
using namespace std;

int n;

bool not_sorted(vector<int> & a){
	for(int i=1;i<n;++i){
		if(a[i]<a[i-1]){
			return 1;
		}
	}
	return 0;
}

void solve(){
	int x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	int steps=0;
	while(not_sorted(a)){
		++steps;
		int i=0;
		while(i<n && a[i]<=x){
			++i;
		}
		if(i==n){
			cout << -1 << endl;
			return ;
		}
		swap(a[i],x);
	}
	cout << steps << endl;
	return ;
}

int32_t main(){
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}