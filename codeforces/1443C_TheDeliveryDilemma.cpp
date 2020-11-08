#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

const int mxN = 2e5;
int a[mxN],b[mxN];
int n;

// bool cmp(ar<int,2> x,ar<int,2> y ){
// 	if(x[0]<y[0]) return true;
//     if(x[0]==y[0]) return x[1]>y[1];
//     return false;
// }

int main()
{
	int tt;
	cin >> tt;
	while(tt--){
		cin >> n;
		vector<ar<ll,2>> c ;
		for(int i=0; i<n; ++i){
			cin >> a[i]; // courier
		}
		
		for(int i=0; i<n; ++i){
			cin >> b[i];
		}

		for(int i=0;i<n;++i){
			c.push_back({a[i],b[i]});
		}

		sort(c.begin(),c.end());

		for(int i=n-2; i>=0; --i){
			c[i][1] += c[i+1][1];
		}

		// for(int i=0; i<n ;++i){
		// 	cout << c[i][0] << " " << c[i][1] << "\n";
		// }

		ll ans = c[0][1];

		for(int i=0; i<n; ++i){
			ans = min({ans,max(c[i][0],c[i+1][1]) });
		}
		ans = min(ans,c[n-1][0]);

		cout << ans << endl;
	}
	
	
	return 0;
}