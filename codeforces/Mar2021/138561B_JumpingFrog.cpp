#include <bits/stdc++.h>
#define ar array
using namespace std;

const int mxN = 5e5;
// vector<int> adj[mxN];

void solve(){

	// for(int i=0;i<mxN;++i){
	// 	adj[i].clear();
	// }

	int n,dest=-1;
	cin >> n;
	vector<int> vec (n,0);
	vector<int> vis(n,0);

	vector<vector<int>> adj ( n  );


	for(int i=0;i<n;++i){
		cin >> vec[i];

		if(vec[i]==0){
			dest = i;
		}

		if(i+vec[i]<n)
		adj[i].push_back(i+vec[i]);
		if(i-vec[i]>=0)
		adj[i].push_back(i-vec[i]);
	}

	if(dest==-1){
		cout << -1 << endl;
		return ;
	}

	// if(n==1 && vec[0]==0){
	// 	cout << 0 << endl;
	// 	return;
	// }
	

	queue<ar<int,2>> q;
	q.push({0,0});
	vis[0] = 1;

	while(!q.empty()){
		ar<int,2> f = q.front(); q.pop();

		if(f[0]==dest){
			cout << f[1] << endl;
			return ;
		}

		for(int v : adj[f[0]]){
			if(!vis[v]){
				vis[v] = 1;

				// if(v==dest){
				// 	cout << f[1]+1 << endl;
				// 	return ;
				// }

				q.push({v,f[1]+1});
			}
		}
	}

	
	cout << -1 << endl;
	

}

int main(){
	
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}