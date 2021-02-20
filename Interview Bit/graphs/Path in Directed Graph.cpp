#define ll long long
#define ar array

const int mxN = 1e5;


void bfs( int u, vector<int> adj[mxN], int vis[mxN]){
    vis[u] = 1;
    queue<int> q;
    q.push(u);
    
    while(!q.empty()){
        int front = q.front(); q.pop();
        for( int v: adj[front] ){
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    
}

int Solution::solve(int A, vector<vector<int> > &B) {
    int n,m;
    vector<int> adj[mxN];
    int vis[mxN] ={0};
    for(auto e: B){
        adj[e[0]-1].push_back(e[1]-1);
        // adj[e[1]-1].push_back(e[0]-1);
    }
    
    
    bfs(0,adj,vis);
    
    // for(int i=0; i<A;++i){
    //     cout << vis[i] << " ";
    // }
    // cout << endl;
    return vis[A-1];
}
