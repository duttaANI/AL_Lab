// link : https://cp-algorithms.com/algebra/module-inverse.html
    #include<bits/stdc++.h>
    #define int long long
    #define maxn 300005
    #define mod 998244353
    using namespace std;
     
    int n,a[maxn],ans,fac[maxn],inv[maxn];
     
    signed main()
    {
    	cin>>n;
    	for(int i=1;i<=2*n;i++)
    		cin>>a[i];
    	sort(a+1,a+2*n+1);
    	for(int i=1;i<=n;i++)	ans=(ans+a[n*2-i+1]-a[i])%mod;
    	inv[0]=inv[1]=fac[1]=fac[0]=1;
    	for(int i=2;i<=n*2;i++)
    	{
    		fac[i]=fac[i-1]*i%mod;
    		inv[i]=((-mod/i*inv[mod%i])%mod+mod)%mod;
    	}
    	for(int i=2;i<=n*2;i++)
    		inv[i]=inv[i-1]*inv[i]%mod;
    //	cout<<inv[2]<<endl;
    	cout<<ans*fac[n*2]%mod*inv[n]%mod*inv[n]%mod<<endl;
    }
// #include <bits/stdc++.h>
// using namespace std;

// #define ar array
// #define ll long long

// const int mod = 998244353;
// const int _ = 3e5+5;
// int n,a[_],inv[_],fac[_],ifac[_],ans;

// ll nCr(ll n, ll k) 
// { 
//     ll res = 1; 
  
//     // Since C(n, k) = C(n, n-k) 
//     if (k > n - k) 
//         k = n - k; 
  
//     // Calculate value of 
//     // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
//     for (ll i = 0; i < k; ++i) { 
//         res = ( res%M * (n - i)%M )%M; 
//         res = ( (res%M) / ((i + 1)%M) )%M; 
//     } 
  
//     return res; 
// } 

// void initialize(){
// 	fac[0] = ifac[0] = 1, inv[1] = 1;
// 	for (int i = 1; i <= 2*n; ++i) {
// 		fac[i] = (ll)fac[i - 1] * i % mod;
// 		if (i != 1) inv[i] = (ll)inv[mod % i] * (mod - mod / i) % mod;
// 		ifac[i] = (ll)ifac[i - 1] * inv[i] % mod;
// 	}
// 	return ;
// }


// int main(){

// 	cin >> n;
// 	for(int i=0;i<2*n;++i){
// 		cin >> a[i+1];
// 	}
// 	int sum = 0;
// 	sort(a+1,a+2*n+1);
// 	for(int i=1;i<=n;i++)	ans=(ans+a[n*2-i+1]-a[i])%mod;

// 	// initialize();

// 	fac[0] = ifac[0] = 1, inv[1] = 1;
// 	for (int i = 1; i <= 2*n; ++i) {
// 		fac[i] = (ll)fac[i - 1] * i % mod;
// 		if (i != 1) inv[i] = (ll)inv[mod % i] * (mod - mod / i) % mod;
// 		ifac[i] = (ll)ifac[i - 1] * inv[i] % mod;
// 	}

// 	cout << ans << " " << fac[2*n]%mod << " " << ifac[n]%mod << "\n";
	
// 	cout << ans*fac[2*n]%mod*ifac[n]%mod*ifac[n]%mod;
// 	// cout << ans2 ;
	
// 	return 0;
// }



