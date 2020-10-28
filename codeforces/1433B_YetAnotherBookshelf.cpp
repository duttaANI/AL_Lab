#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

int tt;
int a[50];

int main(){
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		for(int i=0; i<n; ++i){
			cin >> a[i];
		}
		int left=0;;
		for(int i=0; i<n; ++i){
			if(a[left]==0){
				++left;
			}else{
				break;
			}
		}
		int right = n-1;
		for(int i=n-1; i>=0; --i){
			if(a[right]==0){
				--right;
			}else{
				break;
			}
		}
		int ans = 0;
		for( int i=left; i<=right ;++i ){
			if(a[i]==0){
				++ans;
			}
		}
		cout << ans << "\n"
	}

	return 0;
}