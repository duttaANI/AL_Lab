#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long


void solve(){
    ll n,r,b;
    cin >> n >> r >> b;
    n -= 2*min({r,b});

    ll mx = max({r,b});

    mx -= min(r,b);

    // cout << " mx " << mx << "\n";
    // cout << " n " << n << "\n";

    if(2*mx <= n){
        cout << "How very smart\n";
    }else{
        cout << "idiots\n";
    }
}

int main() {
	// your code goes here
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
	return 0;
}

/*
1<=T<=10^5
N is even
2<=N,R,B<=10^18
R+B<=N


*/