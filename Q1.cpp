#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dig(ll x){
	int digits=0;
	while(x){
		++digits;
		x /=10;
	}
	return digits;
}

void solve(){
	ll N,Z,p;
	cin >> N >> Z >> p;
	int ans = 0;

	for(int k=1; k<N; ++k){
		ll Div = pow(10,k);
		ll A = Z/Div;
		ll B  = Z%Div;

		if(A%p==0 && B%p==0 && dig(A)+dig(B) == N ){
			++ans;
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
}