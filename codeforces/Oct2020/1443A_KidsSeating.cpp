#include <bits/stdc++.h>
using namespace std;

const int safety = 13;
const int mxN = 100 + safety;
int n,a[mxN];

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		cin >> n;
		int tmp = n;
		for(int i=n; tmp; ++i,--tmp ){
			cout << i*2 << " ";
		}
		cout << "\n";
	}
	return 0;
}