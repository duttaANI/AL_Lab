

class Solution{
	public:
	// your task is to complete this function
    /*
    adj : adjacency list of the graph
    V : Number of vertices
    c,d: End vertices of the given edge
    */
    
    void dfs(int u, vector<int> adj[], vector<bool>& visited, vector<int>& tin, vector<int>& low, vector<vector<int>>& ans,int & timer, int p=-1){
        visited[u] = true;
        tin[u] = low[u] = timer++;
        for(int v : adj[u]){
            if (v == p) continue;
            if (visited[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v,adj,visited,tin,low,ans,timer,u);
                low[u] = min(low[u], low[v]);
                if(low[v]>tin[u]){
                    if(u<v){
                        ans.push_back({u,v});
                    } else {
                        ans.push_back({v,u});
                    }
                }
            }
        }
    }

    
    
    int isBridge(int V, vector<int> adj[], int c, int d) {
        // Code here
        int timer=0;
        vector<bool> visited;
        vector<int> tin, low;
        vector<vector<int>> ans;
        visited.assign(V, false);
        tin.assign(V, -1);
        low.assign(V, -1);
        for (int i = 0; i < V; ++i) {
            if (!visited[i])
                dfs(i,adj,visited,tin,low,ans,timer);
        }
        sort(ans.begin(),ans.end());
        
        if(d<c){
            swap(c,d);
        }
        
        for(int i=0; i<ans.size(); ++i){
            if( ans[i][0]==c && ans[i][1]==d ){
                return 1;
            }
        }
        return 0;
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
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        