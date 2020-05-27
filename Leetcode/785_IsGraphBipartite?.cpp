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