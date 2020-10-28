#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll nCr(ll n, ll k) 
{ 
    ll res = 1; 
  
    // Since C(n, k) = C(n, n-k) 
    if (k > n - k) 
        k = n - k; 
  
    // Calculate value of 
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
    for (ll i = 0; i < k; ++i) { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
  
    return res; 
} 

ll factorial(ll x){
	int res=1;
	for(ll i=1; i<=x; ++i){
		res *= i;
	}
	return res;
}

int n;

int main(){
	cin >> n;

	ll ans = nCr(n,n/2)*factorial(n/2-1)*factorial(n/2-1)/2;
	cout << ans;

	return 0;
}