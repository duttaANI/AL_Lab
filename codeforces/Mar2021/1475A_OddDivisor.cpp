#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	ll n;
	cin >> n;
	// ll one_bits = (int)log2(n)+1;
	// cout << one_bits << endl;
	double a=log2(n);
    int b=a;
	if( b==a && n!=1 ){

		cout << "NO\n";
	}
	else{
		cout << "YES\n";
	}
}

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
}