#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	while(m--){
		int flg1=0,flg2=0;
		int l,r;
		cin >> l >> r;
		// for(int i=l-1; i<=r-1;++i){
		// 	sub = sub + s[i];
		// 	sum += s[i]-'0';
		// }
		for(int i=0;i<l-1;++i){
			if( i<l-1 && s[i]==s[l-1]){
				// cout << " flg1 " << i << "\n";
				flg1=1;
				break;
			}
		}
		for(int i=n-1;i>r-1;--i){
			if( i>r-1 && s[i]==s[r-1]){
				// cout << " flg2 " << i << "\n";
				flg2=1;
				break;
			}
		}
		// cout << flg1 << " " << flg2 << "\n";
		if(!flg1 && !flg2){
			cout << "NO\n";
		}else{
			cout << "YES\n";
		}
	}
}

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}