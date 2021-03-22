#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	string s;
	cin >> s;
	for( ll i=0; i+4 < s.size(); ++i ){
		if( s.substr(i,5)=="party" ){
			s[i+2] = 'w';
			s[i+3] = 'r';
			s[i+4] = 'i';
		}
	}
	cout << s << endl;
}

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}