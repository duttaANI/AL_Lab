#include <bits/stdc++.h>
using namespace std;
#define ar array

void solve(){
	vector<int> freq1 (26,0);
	vector<int> freq2 (26,0);

	int n,m;
	cin >> n >> m;
	string a,b;
	cin >> a >> b;

	for(int i=0;i<n;++i){
		freq1[a[i]-'a']++;
		freq2[b[i]-'a']++;
	}
	for(int i=0;i<25;++i){
		if(freq1[i]<freq2[i]){
			cout << "NO\n";
			return ;
		}
		freq1[i] -= freq2[i];
		if(freq1[i]%m!=0){
			cout << "NO\n";
			return ;
		}
		freq1[i+1]+=freq1[i];
	}

	cout << "YES\n";
}

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}

/*
m=m-1
sort(a.begin(),a.end());
sort(b.begin(),b.end());
if(a>b) {
	cout << "1 NO\n";
	return ;
}
int i;
cout << a << "\n" << b << "\n";
for( i=0;i+m<n;i+=m){
	if(a[i]!=a[i+m] || b[i]!=b[i+m]){
		cout << "2 NO\n";
		return ;
	}
	++i;
}
for( i=i-m+1;i<n;++i){
	if(a[i]!=b[i]){
		cout << "3 NO\n";
		return ;
	}
}

*/