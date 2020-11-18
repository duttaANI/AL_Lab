#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long


 
int main(){
	int tt;
	cin >> tt;
	while(tt--){
		ll n,W,Wcopy,flg =0,flgANS;
		vector<int> ans;
		vector<ar<int,2>> w;

		cin >> n >> W;
		Wcopy = W;

		for(int i=0;i<n;++i){
			int b; cin >> b;
			if(b<=W){
				w.push_back({b,i+1});
				if(b>W/2){
					flg=1;
					flgANS = i+1;
					
				}
			}
		}
		// sort(w.begin(),w.end(),greater<ar<int,2>>());
		if(!flg){
			for(int i=0;i<w.size();++i){
				if(w[i][0]<=W && W > Wcopy/2){
					ans.push_back(w[i][1]);
					W-=w[i][0];
				}
			}
			
			if(W <= Wcopy/2){
				cout << ans.size() << "\n";
				for(int k=0; k<ans.size();++k){
					cout << ans[k] << " ";
				}
				cout << "\n";
			}
			else {
				cout << -1;
				cout << "\n";
			}
		}else{
			
			cout << 1 << "\n";
			cout << flgANS << "\n";
		}
	}
	return 0;
}