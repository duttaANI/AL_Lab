const int mxN = 1e5;

void dfs(int u, vector<int> adj[mxN], vector<int>& vis, vector<int>& act, int &ans){
    vis[u] = 1;
    act[u] = 1;
    
    // cout << u+1 << " u \n";
    
    for(int v : adj[u]){
        // cout << v+1 << " v \n";
        if(act[v]){
            ans=1;
            // cout << " hi \n";
            return;
        }
        else{
            if(!vis[v]){
                dfs(v,adj,vis,act,ans);
            }
        }
    }
    
    act[u]=0;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> adj[mxN];
    for(auto e : B){
        adj[e[0]-1].push_back(e[1]-1);
    }
    
    vector<int> vis(A,0),act(A,0);
    
    int ans=0;
    for(int i=0;i<A;++i){
        if(!vis[i]){
            dfs(i,adj,vis,act,ans);
        }
    }
    return ans;
}
