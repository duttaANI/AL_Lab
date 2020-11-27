#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int mxN = 2e5;

void solve(){
	int n;
	cin >> n;
	vector<set<int>> g(n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y ,--x, --y; // 0th indexing
		g[x].insert(y);
		g[y].insert(x);
	}
	vector<int> val(n, 1); // the vertices on cycle which do not have a hanging tree will have val = 1 and other vertices val will be incremented
	queue<int> leafs;
	for (int i = 0; i < n; ++i) {
		if (g[i].size() == 1) { // the vertices on cycle which do not have a hanging tree will have val = 1 and other vertices val will be incremented
			leafs.push(i);
		}
	}
	while (!leafs.empty()) {
		int v = leafs.front();leafs.pop();
		int to = *g[v].begin();
		val[to] += val[v];
		val[v] = 0;
		g[v].clear();
		g[to].erase(v);
		if (g[to].size() == 1) { // the vertices on cycle which do not have a hanging tree will have val = 1 and other vertices val will be incremented
			leafs.push(to);
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += val[i] * 1ll * (val[i] - 1) / 2; 
		ans += val[i] * 1ll * (n - val[i]);
	}
	cout << ans << endl;
}

int32_t main(){
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}

/*
int n;
	cin >> n;
	vector<int> adj[mxN]; // array of vectors
	for(int i=0;i<n;++i){
		int a,b;
		cin >> a >> b , --a,--b; // 0th indexing
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<int> leafs;
	vector<int> val(n,1);
	for(int i=0;i<n;++i){
		if(adj[i].size()==1){
			leafs.push_back(i);
		}
	}
	while(!leafs.empty()){
		int child = leafs.front(), leafs.pop();
		int parent = adj[child][0];
		val[parent] += val[child];
		val[child] = 0;
		adj[child].clear();
		adj[parent]
		if(adj[parent].size()==1){
			leafs.push_back(parent);
		}
	}
*/