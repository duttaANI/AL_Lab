#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 5e3;
int tt;
int a[mxN];

int main(){
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		vector< ar<int,2> > p;

		for(int i=0; i<n; ++i){
			cin >> a[i];
		}
		int flg = 0;
		for( int i =1; i<n; ++i ){
			if( a[i-1]!=a[i] ){
				flg = 1;
				break;
			}
		}

		if(!flg){
			cout << "NO\n";
		}else{
			cout << "YES\n";
			int idx;
			for( int i=0; i<n; ++i ){
				if( a[i]!=a[0] ){
					idx = i;
					p.push_back({0+1,i+1});
				}
			}
			for(int i=1; i<n; ++i){
				if( a[i]==a[0] )
				p.push_back({idx+1,i+1});
			}

			for( ar<int,2> itr : p ){
				cout << itr[0] << " " << itr[1] << "\n";
			}
		}
	}

	return 0;
}