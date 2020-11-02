#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

ll p,q;

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		cin >> p >> q;
		if(p%q) {
			cout << p << endl; continue;
		}
		ll ans=0;
		for(int i=1 ; i*i <= q; ++i){
			ll tmp = p;
			if(!(q%i)){ // i is a factor of q << then q/i is also a factor of q >>
				if(i!=1){
					while(!(tmp%q)) { // till q divides p
						tmp/=i;
					}
					ans = max(ans,tmp);
				}
				// cout << "i " << i << "\n";
				tmp = p;
				while(!(tmp%q)) {
					tmp/=(q/i); // << since q/i is also a factor of q >>
				}
				ans = max(ans,tmp);
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}




















































// #include <bits/stdc++.h>
// using namespace std;

// #define ar array
// #define ll long long

// ll p,q;



// int main(){
// 	int tt;
// 	cin >> tt;
// 	while(tt--){
// 		cin >> p >> q;
// 		if(q>p){
// 			cout << p;
// 		}else{
// 			ll ans;
// 			if( p%q!=0 ){
// 				cout << p;
// 			}
// 			else{
// 				for(ll i=sqrt(p)+1; i>=1 ; --i){
// 					if(p%i==0 && i%q!=0){
// 						ans= i;
// 						break;
// 					}
// 				}
// 				cout << ans;
// 			}
// 		}

// 		cout << endl;
// 	}
	
// 	return 0;
// }