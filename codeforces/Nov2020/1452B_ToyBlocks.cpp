#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

void solve(){
   int n;
   cin>>n;
   
   vector<int> v(n);
   for(auto& x : v) cin>>x;
   
   sort(v.begin(),v.end()); // ascending
   // for(int i : v){
   // 		cout << i << " ";
   // }
   // cout  << "\n";
   ll maxy=v[n-1];
   // cout << maxy << " maxy \n";
   ll req=0;
   for(int i=1; i<n; i++) req+=maxy-v[i];
   // cout << req << " req \n";
   if(v[0]<=req){ // v[0] is smallest element
       cout<<req-v[0]<<endl;
   }
   else { // sum should be divisible by n-1
       ll temp=v[0]-req;
       temp%=n-1;
       if(temp==0){
           cout<<0<<endl;
       }
       else {
           cout<<n-1-temp<<endl; // subtract remainder
       }
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