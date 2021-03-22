#include <bits/stdc++.h>
using namespace std;

void solve(){
	int w1,w2,x1,x2,M;
	cin >> w1 >> w2 >> x1 >> x2 >> M;
	if( (w2-w1) >= M*x1 && (w2-w1) <= M*x2 ){
		cout << 1 << endl;
	}
	else{
		cout << 0 << endl;
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