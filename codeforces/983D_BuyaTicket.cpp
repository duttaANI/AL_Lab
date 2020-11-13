// diff
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long 
const int mxN = 2e5 + 1000;
vector<ar<ll,2>> adj1 [mxN];
ll d1[mxN],n,m;

void dij( ){
	
    priority_queue< ar<ll,2> , vector<ar<ll,2>> , greater<ar<ll,2>>  > pq; // std::greater<T> would cause the smallest element to appear as the top().
    for(int i=0; i<n; ++i){
    	pq.push({d1[i],i});
    }
    while(pq.size()){
    	ar<ll,2> u = pq.top(); pq.pop();
    	if(u[0]>d1[u[1]]) continue;
    	for( ar<ll,2> v : adj1[u[1]] ){
    		if( d1[v[1]] > u[0]+v[0] ){
    			d1[v[1]] = u[0] + v[0];
    			pq.push({d1[v[1]],v[1]});
    		}
    	}
    }
}

int main(){
	cin >> n >> m;
	for(int i=0;i<m;++i){
		ll a,b,c;
		cin >> a >> b >> c,--a,--b;
		adj1[a].push_back({2*c,b});
    	adj1[b].push_back({2*c,a});
	}
	for(int i=0; i<n; ++i){
		ll a;
		cin >> a;
    	d1[i] = a;
    }
    dij();
    for(int i=0;i<n;++i){
    	cout << d1[i] << " ";
    }
}

/*vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {
	vector<int> ans;
    for(auto e : B){
    	adj1[e[0]-1].push_back({2*e[2],e[1]-1});
    	adj1[e[1]-1].push_back({2*e[2],e[0]-1});
    }
    n = A.size();
    for(int i=0; i<n; ++i){
    	d1[i] = A[i];
    }


   	
    return ans;
}
*/