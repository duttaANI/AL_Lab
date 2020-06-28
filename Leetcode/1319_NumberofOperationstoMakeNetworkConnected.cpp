class Solution {
public:
    int tot_disjoint_components = 0;
    stack<int> s;
    vector<int> Graph[100000]; // array of vectors
    
    void dfs (vector<bool>& vis, int v) {
        s.push(v);
        while (!s.empty()) {
            v = s.top(); s.pop();
            if ( vis[v] ) continue;
            vis[v] = true; 
            for (auto it = Graph[v].begin(); it != Graph[v].end(); it++) 
                if(!vis[*it])
                    s.push(*it);
        }
        ++tot_disjoint_components; // when stack becomes empty increment disjoint components of Graph
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        // create a adj list undirected graph
        for(auto& p : connections)
        {
            Graph[p[1]].push_back(p[0]);
            Graph[p[0]].push_back(p[1]);
        }
        
        if ( connections.size() >= n-1  ) {
            vector<bool> vis ( n , false );
            for ( int i=0 ; i<n ; ++i ) 
                if(!vis[i])
                    dfs (vis, i);
            return tot_disjoint_components - 1;
        }
        else {
            return -1;
        }
    }
};