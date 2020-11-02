#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int SAFETY = 13;
const int mxN = 5e5 + SAFETY ;
int n,k,a[mxN],b[mxN];

int main(){
	cin >> n >> k;
	for(int i=0; i<n; ++i){
		cin >> a[i+1];
	}
	a[0] = -1e9;
	a[n + 1] = 2e9;
	for(int i=0; i<n+2; ++i){
		a[i] -= i;
	}
	for(int i=0; i<k; ++i){
		cin >> b[i+1]; // b stores idx in sorted order
	}
	b[k+1]=n+1; // if k=0 and other values for k
	int ans = 0;
	for(int i=0; i<k+1;++i){
		int l=b[i], r=b[i+1];
		if (a[l] > a[r]) {
			puts("-1");
			return 0;
		}
		vector<int> lis;
		// below code stores longest increasing subsequence in vector lis ex : if a={4,3,1,2,3} then lis will store {1,2,3}
		for(int j=l+1 ; j<r; ++j){
			if(a[l]<=a[j] && a[j]<=a[r]){
				auto pos = upper_bound(lis.begin(),lis.end(),a[j]);
				// cout << a[j] << " " << pos - lis.begin() +1  << "\n";
				if(pos==lis.end()){
					lis.push_back(a[j]);
				}
				else{
					*pos = a[j];
				}
			}
		}
		ans += (r-l-1) - (int)lis.size();
	}
	cout << ans << endl;
	
	return 0;
}