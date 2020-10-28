#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

int tt;

int main(){
	cin >> tt;
	while(tt--){
		int x;
		cin >> x;
		int dig = x%10;
		int total_dig = 0;
		while(x){
			total_dig++;
			x/=10;
		}
		//cout << total_dig << "\n";
		cout << (10*(dig-1) + (total_dig)*(total_dig+1)/2 ) << "\n";
	}

	return 0;
}