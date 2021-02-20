// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define ll long long
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<ll> d(n,0);
	    vector<int> p(n, -1);

	    for(int i=0; i<n; ++i){
	        for( auto e : edges ){
	            if( d[e[1]] > d[e[0]] + e[2] ){
    				d[e[1]] = max ((ll)-1e15, d[e[0]] + e[2] );
    				p[e[1]] = e[0];
    			}
	        }
	    }
	    
	    int x = -1;
	    for( auto e : edges ){
            if( d[e[1]] > d[e[0]] + e[2] ){
				d[e[1]] = max ((ll)-1e15, d[e[0]] + e[2] );
				p[e[1]] = e[0];
				x = e[0];
			}
        }
        
        if( x==-1 ){
            return 0;
        }
        return 1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends