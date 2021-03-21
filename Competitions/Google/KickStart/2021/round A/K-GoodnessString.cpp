#include <bits/stdc++.h>
using namespace std;

void solve(int cs){
	int N,K,cnt=0;
	cin >> N >> K;
	string S;
	cin >> S;
	for(int i=0;i<N/2;++i){
		// cout << S[i] << " " << S[N-i-1] << endl;
		if( S[i]!=S[N-i-1] ){
			cnt += 1;
		}
	}
	int ans = abs(K-cnt);
	cout << "Case #" << cs << ":" << " " << ans << endl;
}

int main(){
	int tt;
	cin >> tt;
	int ttt = tt;
	while(tt--){
		solve(ttt-tt);
	}

	return 0;
}