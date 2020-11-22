#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,ans=0;
	cin >> n;

	while(n>3){
		if( n%2==1){
			n-=1;
			int temp = n/2;
			n/=temp;
			ans +=2;
		}else{
			int temp = n/2;
			n/=temp;
			++ans;
		}
	}
	if(n==2){
		++ans;
	}
	if(n==3){
		ans+=2;
	}
	cout << ans << endl;
}

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}