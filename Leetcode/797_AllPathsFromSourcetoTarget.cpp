class Solution {
public:
    
    vector< vector<int> > paths;
    
    void dfs(int x, vector<int> & cur, int trgt, vector<vector<int>>& graph, vector<int> & vis ){
        if(  x==trgt ){
            cur.push_back(x);
            paths.push_back( cur );
            cur.pop_back();
            return ;
        }
        vis[x] = 1;
        cur.push_back( x );
        
        for(int v : graph[x]){
            if( !vis[v] ){
                dfs( v, cur, trgt, graph, vis );
            }
        }
        
        vis[x] = 0;
        cur.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int trgt = graph.size() - 1;
        vector<int> cur, vis(graph.size(),0);
        int src = 0;
        dfs( 0, cur, trgt, graph , vis);
        return paths;
    }
};