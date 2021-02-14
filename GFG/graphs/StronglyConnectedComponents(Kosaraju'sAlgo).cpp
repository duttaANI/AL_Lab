// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
	public:
	/*  Function to find the number of strongly connected components
    *   using Kosaraju's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */
    
    void dfs1(int u, vector<int> & stk, vector<int>& vis,vector<int> adj[]){
        vis[u] = 1;
        for(int v: adj[u]){
            if(!vis[v]){
                dfs1(v,stk,vis,adj);
            }
        }
        stk.push_back(u);
    }
    
    void dfs2(int u, vector<int>& vis,vector<int> Radj[]){
        vis[u] = 1;
        for(int v : Radj[u]){
            if(!vis[v]){
                dfs2(v,vis,Radj);
            }
        }
    }
    
    int kosaraju(int V, vector<int> adj[]) {
        //code here
        int ans =0;
        
        // rev graph
        vector<int> Radj[5000];
        for(int u=0 ; u<V; ++u){
            for(int v : adj[u]){
                Radj[v].push_back(u);
            }
        }
        
        vector<int> stk;
        vector<int> vis (V,0);
        for(int i=0; i<V; ++i){
            if(!vis[i]){
                dfs1(i,stk,vis,adj);
            }
        }
        
        vis.assign(vis.size(), 0);
        
        while(stk.size()){
            int frnt = stk[stk.size()-1]; 
            stk.pop_back();
            if(!vis[frnt]){
                ++ans;
                dfs2(frnt, vis, Radj);
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
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends