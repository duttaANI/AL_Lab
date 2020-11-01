#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 5e5;
int n,x,a[mxN],b[mxN];


int main(){
	int tt;
	cin >> tt;
	while(tt--){
		cin >> n >> x;
		for(int i=0; i<n; ++i){
			cin >> a[i];
		}
		for(int i=0;i<n; ++i){
			cin >> b[i];
		}
		// sort(a,a+n);
		// sort(b,b+n);
		int flg =0;
		for(int i=0; i<n; ++i){
			if(a[i]+b[n-1-i]>x){
				flg=1;
				break;
			}
		}
		if(flg){
			cout << "NO\n";
		}else{
			cout << "YES\n";
		}
	}
	
	return 0;
}