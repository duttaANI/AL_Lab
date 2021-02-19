// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

/*

int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

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


class Solution {
public:
    vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
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
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}  // } Driver Code Ends