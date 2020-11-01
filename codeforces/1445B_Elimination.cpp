#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

int a,b,c,d;

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		cin >> a >> b >> c >> d;
		if(b>=c){
			cout << a+b;
		}else if( d>=a ){
			cout << c+d;
		}else if( a+b>=c+d ) // b<c
		{
			cout << a+b;
		}else{
			cout << c+d;
		}
		cout << endl;
	}
	
	return 0;
}