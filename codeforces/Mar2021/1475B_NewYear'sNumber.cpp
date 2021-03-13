#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	ll n;
	cin >> n;
	
	ll limit = n/2020;

	for(int i=0; i<=limit; ++i){
		if( 2020*i + 2021*(limit-i) == n ){
			cout << "YES\n";
			return ;
		}
	} 
	cout << "NO\n";
}

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
}