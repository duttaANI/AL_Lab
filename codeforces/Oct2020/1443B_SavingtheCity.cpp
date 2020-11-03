#include <bits/stdc++.h>
using namespace std;

// #define ll long long
const int safety = 13;
const int mxN = 100 + safety;
int a,b,dp[mxN]={-1};
string s;


int main(){
	int tt;
	cin >> tt;
	while(tt--){
		cin >> a >> b;
		cin >> s;

		int l = 0 ,r = s.length()-1;
		while(s[l]=='0') ++l;
		while(s[r]=='0') --r;

		s = s.substr(l,r-l+1);

		// convert all contiguous ones to single one in string
		string s2 = "";
		for(int i=0; i<s.length(); ++i){
			int flg=0;
			while(s[i]=='1'){ 
				++i;
				flg=1;
			}
			if(flg)s2 += '1';
			s2 += s[i];
		}
		// cout << s2 << "\n";
		// int l=0, r=1;
		// int n = s2.length();
		// while(l<n && s2[l]!='1'){
		// 	++l;
		// }
		// if(l>=n){
		// 	cout << 0 << "\n";
		// 	continue ;
		// }
		// dp[l] = a;
		// r=l+1;
		int ans=0;
		// while(r<n){
			
		// 	while(  r<n && s2[r]!='1'){
		// 		++r;
		// 	}
		// 	if(r>=n){
		// 		break;
		// 	}
		// 	dp[r] = min( (int)dp[l]+b*(r-l-1), (int)dp[l]+a );
		// 	ans = dp[r];

		// 	// cout << "r " << r << " dp[r] " << dp[r] << "\n";
		// 	// cout << ans << "\n";
		// 	l = r;
		// 	++r;

		// }

		vector<int> zeros;
		int cnt=0;
		for(int i=0; i<s2.length(); ++i){
			if(s2[i]=='1'){
				++i,cnt=0;
				while(s2[i]=='0') ++cnt , ++i;
				zeros.push_back(cnt);
				--i;
			}
		}

		// zeros.pop_back();

		// for(int it : zeros){
		// 	cout << it << " ";
		// }
		// cout << "\n";
		for( int i=0; i<zeros.size(); ++i ){
			
			ans += min( zeros[i]*b , a );
			// cout << ans << "\n";
		}
		if(zeros.size())
			ans+=a;
		cout << ans << "\n";
	}
	return 0;
}