#include <bits/stdc++.h>
using namespace std;

const int mxN = 3e4;
vector<int> adj[mxN];

int main(){
	int n , t;
	cin >> n >> t;
	vector<int> vec(n,0);
	for(int i=0;i<n-1;++i){
		cin >> vec[i];
		adj[i].push_back(i+vec[i]);
	}

	
	vector<int> vis(n,0);
	
	queue<int> q;
	q.push(0);
	vis[0] = 1;

	while(!q.empty()){
		int f = q.front(); q.pop();
		for(int v : adj[f]){
			if(!vis[v]){
				vis[v] = 1;
				q.push(v);
			}
		}
	}

	if( vis[t-1]){
		cout << "YES";
	}
	else{
		cout << "NO";
	}

}