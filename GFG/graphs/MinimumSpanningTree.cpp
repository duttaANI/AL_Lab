// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
	public:
	#define ar array
	// Function to construct and print MST for
    // a graph represented using adjacency
    // list representation, with V vertices.
    static const int mxN= 1e4;
    static bool cmp(ar<int,3>& a , ar<int,3>& b){
        return a[2]<b[2];
    }
    
    int p[mxN];
    
    int find(int x){
        return (p[x]^x)?p[x]=find(p[x]):x;
    }
    
    int join(int x, int y){
        if( (x=find(x) ) == (y=find(y) )  ){
            return 0;
        }
        p[x] = y;
        return 1;
    }
    
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        
        int ans = 0;
        
        vector<ar<int,3>> e;
        for(int i=0; i<V; ++i){
            for(int j=0; j<adj[i].size(); ++j){
                // cout << i << " " << adj[i][j][0] << " " << adj[i][j][1] << endl;
                e.push_back({i,adj[i][j][0],adj[i][j][1]});
            }
        }
        
        int n = e.size();
        
        // cout << n << endl;
        
        sort(e.begin(),e.end(),cmp);
        
        for(int i=0;i<V;++i){
            p[i] = i;
        }
        
        for(int i=0; i<n;++i){
            
            if(join(e[i][0],e[i][1])){
                ans += e[i][2];
            }
        } 
        
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends