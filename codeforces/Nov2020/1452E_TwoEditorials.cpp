#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

int n,m,k;

vector<ar<int,2>> v;
 

bool cmp( ar<int,2> a , ar<int,2> b){
	return (a[0]+a[1]) < (b[0]+b[1]);
}

int32_t main(){
	cin >> n  >> m >> k;
	vector<ll> su(m + 1); // su -> means suffix max sum
	for(int i=0;i<m;++i){
		int l,r;
		cin >> l >> r ,--l; // --l to get correct overlap
		v.push_back({l,r});
	}

	sort(v.begin(),v.end(),cmp);

	for(int i=0; i<n-k+1; ++i){ // second author wrt editorial
		ll cur = 0;
		for(int j=m-1;j>=0;--j){
			cur+= max(0,min(v[j][1],i+k) - max(i,v[j][0]) );
			su[j] = max(su[j],cur);
		}
	}

	ll ans = su[0];
	for(int i=0; i<n-k+1; ++i){ // first author wrt editorial
		ll cur = 0;
		for(int j=0;j<m;++j){
			cur+= max(0,min(v[j][1],i+k) - max(i,v[j][0]) );
			
			ans = max(ans,cur+su[j+1]);
		}
	}
	cout  << ans ;

	return 0;
}