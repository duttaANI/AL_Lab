#include <bits/stdc++.h>
using namespace std;

void solve(){
	int X,jumps=0;
	cin >> X;
	while (X > 0)
        X -= ++jumps;
 
    if (X == -1)
        jumps++;

    cout << jumps << endl;
}

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}