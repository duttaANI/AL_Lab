#include <bits/stdc++.h>
#define ll long long
using namespace std;



void solve(){
	int a,x,b,y;
	cin >> a >> x >> b >> y;
	if( b>a && y>=x ){
		cout << "NO\n";
		return ;
	}
	// else if(a>b && y>0 ){
	// 	cout << "YES\n";
	// }
	else{
		int flg  = 0;
	    double min_j = (a-b)/(y-x);

	    if(  min_j <= pow(10,9) && (a-b)%(y-x) == 0 ){
			cout << "YES\n";
			return ;
		}

		while(  min_j > (double)(int)(min_j) && min_j*y + b <= pow(10,9)  ){ // while min_j is a fraction 
			min_j *= 10;
		}

		if(  min_j <= pow(10,9) && (a-b)%(y-x) == 0 ){
			cout << "YES\n";
			return ;
		}
		cout << "NO\n";

		
	}
	
}

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
}