#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 1e3;

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		int n; cin >> n;
		string s; cin >> s;
		int ans = 0;
		// int i=1;
		// char flag;
		// for(; i<n; ++i){
		// 	if(s[i-1]==s[i]){
		// 		++ans;
		// 		flag = s[i];
		// 		++i;
		// 		break;
		// 	}
		// }
		// for(; i<n; ++i){
		// 	if(s[i-1]==s[i] && s[i]==flag){
		// 		++ans;
		// 	}
		// }
		int ans1=0;
		for(int i=1;i<n;++i){
			if(s[i-1]==s[i] && s[i]=='1') ++ans1; 
		}
		int ans2=0;
		for(int i=1;i<n;++i){
			if(s[i-1]==s[i] && s[i]=='0') ++ans2; 
		}
		ans = max(ans2,ans1);
		cout << ans << "\n";
	}
	return 0;
}