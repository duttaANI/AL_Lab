#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 3e5;
int tt;
int a[mxN],b[mxN-1];

int main(){
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		int mxIdx = -1;
		int mx = -1;
		for(int i=0; i<n; ++i){
			cin >> a[i];
		}

		for(int i=1; i<n; ++i){
			b[i-1] = abs(a[i]-a[i-1]);
		}

		for(int i=1; i<n; ++i){
			if(a[i]>mx && b[i-1]>0){
				mx = max(a[i],a[i-1]);
				// cout << "mx " << mx << "\n";
				mxIdx = a[i]>a[i-1]?i:i-1;
			}
		}
		if(a[0]>mx && b[0]>0){
			mx = a[0];
			mxIdx = 0;
		}


		int flag = 0;
		for(int i=1; i<n; ++i){
			if( a[i-1]!=a[i] ){
				flag = 1;
				break;
			}
		}

		if(!flag){
			cout << -1 << "\n";
		}else{
			cout << mxIdx+1 << "\n";
		}
	}

	return 0;
}