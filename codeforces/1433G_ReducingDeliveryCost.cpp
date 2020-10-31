#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 1e3;

int n,m,k;
vector<ar<ll,2>> adj[mxN];
vector<ar<ll,2>> r;
ll dis[mxN][mxN];

void dij(int u, ll d[mxN]){
	memset(d,0x3f,sizeof(ll)*mxN);  // NOTE -> sizeof(d1) is IMP and memset(d,0x3f,sizeof(d)) is wrong
	d[u] = 0;
	priority_queue< ar<ll,2> , vector<ar<ll,2>> , greater<ar<ll,2>> > pq;  // it contains {dist to reach city A from node B, city A}
	pq.push({0,u});
	while(pq.size()){
		ar<ll,2> u = pq.top(); pq.pop();
		// link : https://cp-algorithms.com/graph/dijkstra_sparse.html
		if( u[0]>d[u[1]] ) // some priority queue reason -> We simply don't delete the old pair from the pqueue. As a result a vertex can appear multiple times with different distance in the pqueue at the same time. Among these pairs we are only interested in the pairs where the first element is equal to the corresponding value in d[], all the other pairs are old. Therefore we need to make a small modification: at the beginning of each iteration, after extracting the next pair, we check if it is an important pair or if it is already an old and handled pair.
			continue;
		for( ar<ll,2> v : adj[u[1]] ){
			if( d[v[1]] > u[0] + v[0]  ){
				d[v[1]] = u[0] + v[0];
				pq.push({d[v[1]],v[1]});
			}
		}
	}
}



int main(){
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i)
	{
		ll x,y,w;
		cin >> x >> y >> w; --x,--y;
		adj[x].push_back({w,y});
		adj[y].push_back({w,x}); // {dist,city}
	}

	for(int i=0; i<k; ++i){
		int a,b;
		cin >> a >> b, --a,--b;
		r.push_back({a,b});
	}

	for (int v = 0; v < n; ++v) {
		dij(v, dis[v]);
	}

	int ans = INT_MAX;
	for (int v = 0; v < n; ++v) {
		for( ar<ll,2> a : adj[v] ){ // {dist,city}
			int cur =0;
			for( ar<ll,2> a2 : r ){ // {src,dst} routes
				cur += min({dis[a2[0]][a2[1]],dis[a2[0]][v]+dis[a[1]][a2[1]],dis[a2[0]][a[1]]+dis[v][a2[1]]});
			}
			ans = min(ans,cur);
		}
	}
	cout << ans;

	return 0;
}