#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 2e5;
int a[mxN+1],h[mxN+1];
int n;

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		cin >> n;
		for(int i=0; i<n; ++i){
			cin >> a[i];
		}
		h[0] = 0;
		int lst = 0;
		for(int i=1; i<n; ++i){
			if(i>1 && a[i-1]>a[i]){
				++lst;
			}
			h[i] = h[lst] + 1;
		}
		cout << h[n - 1] << endl;
	}
	return 0;
}