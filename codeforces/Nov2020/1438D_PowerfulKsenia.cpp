// https://www.youtube.com/watch?v=e1TylJJr6Bw
#include <bits/stdc++.h>
using namespace std;
int n;
const int mxN = 1e5;
int a[mxN];
int allXOR;

int main(){
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	allXOR = a[0];
	for(int i=1;i<n;++i){
		allXOR = allXOR^a[i];
	}
	if(n%2==1){
		cout << "YES\n";
		cout << n-2 << "\n";
		for(int i=0; i+3<=n; i+=2){
			cout << i+1 << " " << i+2 << " " << i+3 << "\n";
		}
		for(int i=0; i+3<n; i+=2){
			cout << i+1 << " " << i+2 << " " << n << "\n";
		}
	}
	else if(allXOR){
		cout << "NO\n";
	}else{
		cout << "YES\n";
		cout << n-3 << "\n";
		for(int i=0; i+3<=n; i+=2){
			cout << i+1 << " " << i+2 << " " << i+3 << "\n";
		}
		for(int i=0; i+4<n; i+=2){
			cout << i+1 << " " << i+2 << " " << n-1 << "\n";
		}
	}

	return 0;
}