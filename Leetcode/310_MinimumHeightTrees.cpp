// my

class Solution {
public:
    static const int mxN = 3e4;
    vector<int> adj[mxN];
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<int> deg(n,0) , vis(n,0);
        int cnt = n;
        for( auto e : edges ){
            deg[e[0]]++;
            deg[e[1]]++;
            adj[e[0]].push_back( e[1] );
            adj[e[1]].push_back( e[0] );
        }
        queue<int> q;
        for( int i=0; i<n; ++i ){
            if( deg[i]==1 && !vis[i]){
                q.push(i);
                vis[i] = 1; 
            }
        }
        int k;
        while( q.size() && cnt>2 ){
            k = q.size();
            for( int i=0; i<k; ++i ){
                int f = q.front(); q.pop(); --cnt;
                for( int v : adj[f] ){
                    deg[v]--;
                    if( deg[v]<2 && !vis[v] ){
                        q.push(v);
                        vis[v] =1;
                        
                    }
                }
            }
                
        }
        
        vector<int> ans;
        while(q.size()){
            
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};

// editorial
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n==2){
            return {0,1};
        }
        if(n==1){
            return {0};
        }
        
        vector<int> Graph[n]; // array of vectors
        vector<int> incoming(n,0);
        
        int i,c,remainingVertices=n;
        queue<int> q;
        
        vector<int> ans(n,1),res;
        
        // create a adj list graph undirected
        for(auto& p : edges)
        {
            Graph[p[1]].push_back(p[0]);
            Graph[p[0]].push_back(p[1]);
            incoming[p[0]]++;
            incoming[p[1]]++;
        }
        
        //Kahn's algo
        for(i=0; (i<incoming.size() ) ;++i){
            if(incoming[i]<=1){ // leaf
                // cout << i << endl;
                q.push(i);
            } 
        } 
        
        cout << endl;
        
        while(remainingVertices>2 )
        {
            int num_leafs = q.size();
            remainingVertices -= num_leafs;
            for (int i = 0; i < num_leafs; ++i){
                int c = q.front();
                q.pop();
                 for(auto&u:Graph[c]){
                    if(--incoming[u]==1){
                        // cout << u << endl;
                        q.push(u);
                    } 
                }
            }
           
        }
        
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};
