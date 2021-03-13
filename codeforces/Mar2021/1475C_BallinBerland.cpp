#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 2e5;

void solve(){
	int A, B, k;
	cin >> A >> B >> k;
	vector<int> a(A), b(B);
	vector<pair<int, int>> edges(k);
	for (auto &[x, y] : edges) {
		cin >> x;
	}
	for (auto &[x, y] : edges) {
		cin >> y;
	}
	for (auto &[x, y] : edges) {
		x--;
		y--;
		a[x]++;
		b[y]++;
	}
	ll ans = 0;
	for (auto &[x, y] : edges) {
		ans += k - a[x] - b[y] + 1;
	}
	cout << ans / 2 << "\n";
}


// void solve(){

// 	set<int> intersect;
	
// 	unordered_map< int , set<int> > adj;
// 	int a ,b ,k;
// 	cin >> a >> b >> k;
// 	vector<int> by(k,0), gl(k,0);
// 	for(int i=0;i<k;++i){
// 		cin >> by[i];
// 		--by[i];
// 	}
// 	for(int i=0;i<k;++i){
// 		cin >> gl[i];
// 		--gl[i];
// 	}
	
// 	for(int i=0;i<k;++i){
// 		adj[by[i]].insert(gl[i]);
// 	}

// 	ll res = 0;
// 	for(int i=0;i<k;++i){
// 		if(adj[i].size()==0) continue;
// 		for(int j=i+1;j<k;++j){
// 			if(adj[j].size()==0) continue;

// 			set_intersection(adj[i].begin(), adj[i].end(), adj[j].begin(), adj[j].end(),
//                  std::inserter(intersect, intersect.begin()));

			
// 			int c =  intersect.size();
// 			int a =  max(adj[i].size()-c,(size_t)1);
// 			int b =  max(adj[j].size()-c,(size_t)1);

// 			cout << i << " j " << j << " a " << a << " b " << b << " c " << c << endl;

// 			ll ans  = a*b + ( c*(c-1) );
// 			res += ans;
// 		}
// 		intersect.clear();
// 	}
// 	cout  << res << endl << endl;
// }

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
}