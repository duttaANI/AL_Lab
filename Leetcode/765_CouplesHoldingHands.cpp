// link : https://medium.com/@jolyon129/765-couples-holding-hands-a9ce4d50b25e
class Solution {
public:
    
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
    
    int minSwapsCouples(vector<int>& row) {
        
        vector<int> adj[60],Radj[60];
        int n = row.size();
        for(int i=0,j=0;j<n/2; i+=2,++j){
            adj[row[i]/2].push_back( row[i+1]/2 );
            adj[row[i+1]/2].push_back( row[i]/2 );
        }
        
        for(int i=0;i<(n/2); i++ ){
            for( int v : adj[i] ){
                Radj[v].push_back(i);
            }
        }
        
        int scc=0;
        vector<int> stk;
        vector<int> vis (60,0);
        for(int i=0; i<(n/2); ++i){
            if(!vis[i]){
                dfs1(i,stk,vis,adj);
            }
        }
        
        vis.assign(vis.size(), 0);
        
        while(stk.size()){
            int frnt = stk[stk.size()-1]; 
            stk.pop_back();
            if(!vis[frnt]){
                ++scc;
                dfs2(frnt, vis, Radj);
            }
        }
        
        // cout << scc << " scc \n";
        return n/2 - scc;
    }
};

