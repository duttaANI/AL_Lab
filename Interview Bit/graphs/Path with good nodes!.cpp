#include <bits/stdc++.h>

#define ar array
const int  mxN = 1e5;


void dfs(vector<int> &A, int C, int node, vector<int> adj[mxN], int &gnode, int& ans,bool vis[mxN]){
    vis[node]=1;
    // cout << node+1 << " node " << adj[node].size() << " node size \n";
    if(A[node]){
        // cout << "A\n";
        ++gnode;
    }
    
    // check for leaf
    if( adj[node].size()==1 && gnode<=C && node!=0 ){
        // cout << gnode << "\n";
        ++ans;
    }
    
    for( int v : adj[node] ){
        if(!vis[v]){
            dfs(A,C,v,adj,gnode, ans, vis);
        }
    }
    
    if(A[node]){
        --gnode;
    }
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    
    bool vis[mxN];
    memset(vis,0,sizeof(vis));

    vector<int> adj[mxN];
    int gnode = 0;
    int ans = 0;
    
    for(auto e : B){
        adj[e[0]-1].push_back(e[1]-1);
        adj[e[1]-1].push_back(e[0]-1);
    }
    
    dfs( A, C, 0, adj, gnode, ans, vis);
    
    return ans;
}
