
#include <bits/stdc++.h>

int bfs(int A, int src, vector<vector<int>>& adj, vector<bool> &vis){
    vector<int> p(A+5,-1);
    vis[src] = 1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            
            if( !vis[v] ){
                vis[v] = true;
                p[v] = u;
                q.push(v);
            }
            else if( p[u]!=v ){
                return true;
            }
        }
    }
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<vector<int>> adj(A+5);
    for( auto e : B){ // undirected
        adj[e[0]-1].push_back(e[1]-1);
        adj[e[1]-1].push_back(e[0]-1);
    }
    vector<bool> vis(A+5,false); 
    for(int i=0; i<A;++i){
        if(!vis[i] && bfs(A,i,adj,vis)){
            return true;
        }
    }
    return false;
}


// int dfs(int u, int pu, vector<vector<int>>& adj ){
//     vis[u] = 1;
//     p[u] = pu;
//     for( int v : adj[u] ){
//         if( v==pu ){ // no self loops
//             continue;
//         }
//         if( vis[v]==1 ){
//             return 1;
//         }
//         else
//             dfs(v,u,adj);
//     }
//     return 0;
// }
