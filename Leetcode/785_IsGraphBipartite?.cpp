// My
class Solution {
public:
    
    static const int mxN = 100;
    int vis[mxN];
    int col[mxN];
    int ans = 1;
    int n;
    
    void dfs(int x,vector<vector<int>>& graph, int c=0){
        // cout << x << "  node \n";
        vis[x] = 1;
        col[x] = c;
        for(int v : graph[x] ){
            if(!vis[v]){
                dfs(v,graph,!c);
            }
            else if ( col[v]!= (!c)  ){
                ans = 0;
                return ;
            }
        }
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        for(int i=0;i<n;++i){
            if(!vis[i]){
                dfs(i,graph);
            }
        }
        
//         for(int i=0;i<n;++i){
//             cout << col[i] << " " << vis[i] << endl;
//         }
        
        return ans;
    }
};


class Solution {
public:
    
    bool DFS(vector<vector<int>>& graph, int source, vector<bool>& discovered, vector<int>& color) {
        
        int tot_dest = graph[source].size();
        int i=0;
        while (i<tot_dest) {
            
            if(!discovered[graph[source][i]])
            {
                discovered[graph[source][i]] = true;
                color[graph[source][i]] = !color[source];
                if(!DFS(graph, graph[source][i], discovered, color))
                    return false;
                
            }
            else if (color[source] == color[graph[source][i]])
            {
                return false;
            }
            
            ++i;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> color (nodes,0);   vector<bool> discovered (nodes,false);
        
        for(int i=0; i<nodes; ++i) { // for disconnected graphs
            if ( discovered[i]==0  &&  !DFS(graph, i, discovered, color))
              return false;
        }
        return true;
    }
};
