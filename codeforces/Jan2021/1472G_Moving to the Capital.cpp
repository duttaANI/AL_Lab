
#include <bits/stdc++.h>
using namespace std;

vector<int> calcDist(vector<vector<int>> const &g) {
  vector<int> dist(g.size(), -1);
  dist[1] = 0;
  queue<int> pq;
  pq.push(1);
  while (!pq.empty()) {
    int u = pq.front();
    pq.pop();
    for (int v : g[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        pq.push(v);
      }
    }
  }

  return dist;
}

void dfs(int u, vector<vector<int>> const &g, vector<int> const &dist, vector<int> &dp, vector<bool> &used) {
  used[u] = true;
  dp[u] = dist[u];
  for (int v : g[u]) {
    if (!used[v] && dist[u] < dist[v]) {
      dfs(v, g, dist, dp, used);
    }

    if (dist[u] < dist[v]) {
      dp[u] = min(dp[u], dp[v]);
    } else {
      dp[u] = min(dp[u], dist[v]);
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }

  vector<int> dist = calcDist(g);
  vector<int> dp(n + 1);
  vector<bool> used(n + 1);
  dfs(1, g, dist, dp, used);
  for (int i = 1; i <= n; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}









// BELOW IS TLE
// #include <bits/stdc++.h>
// using namespace std;

// #define ar array
// #define ll long long

// const int mxN = 2e5, mxM = 2e5;
// int n,m;

// ll d1[mxN];

// void dij(int u, vector<ar<ll,2>> adj[mxN], ll d[mxN]){
// 	memset(d,0x3f,sizeof(d1));  // NOTE -> sizeof(d1) is IMP and memset(d,0x3f,sizeof(d)) is wrong
// 	d[u] = 0;
// 	priority_queue< ar<ll,2> , vector<ar<ll,2>> , greater<ar<ll,2>> > pq;  // it contains {dist to reach city A from node B, city A}
// 	pq.push({0,u});
// 	while(pq.size()){
// 		ar<ll,2> u = pq.top(); pq.pop();
// 		// link : https://cp-algorithms.com/graph/dijkstra_sparse.html
// 		if( u[0]>d[u[1]] ) // some priority queue reason -> We simply don't delete the old pair from the pqueue. As a result a vertex can appear multiple times with different distance in the pqueue at the same time. Among these pairs we are only interested in the pairs where the first element is equal to the corresponding value in d[], all the other pairs are old. Therefore we need to make a small modification: at the beginning of each iteration, after extracting the next pair, we check if it is an important pair or if it is already an old and handled pair.
// 			continue;
// 		for( ar<ll,2> v : adj[u[1]] ){
// 			if( d[v[1]] > u[0] + v[0]  ){
// 				d[v[1]] = u[0] + v[0];
// 				pq.push({d[v[1]],v[1]});
// 			}
// 		}
// 	}
// }

// void dfs(int u, vector<ll> &dp, vector<bool> &used, ll d1[mxN], vector<ar<ll,2>> adj1[mxN]) {
// 	used[u] = true;
// 	dp[u] = d1[u];
// 	for ( auto v : adj1[u]) { // v[1] is child of u
// 		if (!used[v[1]] && d1[u] < d1[v[1]]) {
// 			dfs(v[1], dp, used, d1, adj1);
// 		}

// 		if (d1[u] < d1[v[1]]) {
// 			dp[u] = min( (ll)dp[u], dp[v[1]]);
// 		} 
// 		else {
// 			dp[u] = min( (ll)dp[u], d1[v[1]]);
// 		}
// 	}
// }

// int main(){
// 	int tt;
// 	cin >> tt;
// 	while(tt--){
// 		vector<ar<ll,2>> adj1[mxN];
// 		ll d1[mxN];
// 		cin >> n >> m;
// 		for (int i = 0; i < m; ++i)
// 		{
// 			ll a,b;
// 			cin >> a >> b ; --a,--b;
// 			adj1[a].push_back({1,b}); // {dist,city}
// 		}
// 		dij(0, adj1, d1);

// 		// for(int i=0; i<n;++i){
// 		// 	cout << d1[i] << " ";
// 		// }
// 		// cout << "\n";

// 		vector<ll> dp(n + 1);
// 		vector<bool> used(n + 1);
// 		dfs(0, dp, used, d1,adj1);
// 		for (int i = 0; i < n; i++) {
// 			cout << dp[i] << " ";
// 		}
// 		cout << endl;
// 	}
// 	return 0;
// }