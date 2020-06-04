class Solution {
public:
    //bellman ford.
    //just run it K+1 iterations.
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int sink, int K) {
        
        vector<int> prev(n, 1e8);
        prev[src] = 0;
        vector<int> Cur(prev);
        for(int z=0; z<=K; z++){
            for(auto edge: flights)
                Cur[edge[1]] = min(Cur[edge[1]], prev[edge[0]] + edge[2]);
            prev = Cur;
       
        }
        return prev[sink] == 1e8 ? -1 : prev[sink];
    }
};



// My code fails <Floyds Algo>
class Solution {
public:
    
    void floyds(vector<vector<int>>& adj_mat,int n, int & K)
    {
        int i,j,k;

        for(k=0;k<n;k++)  // for traversing all nodes
            for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(i==j) adj_mat[i][j]=0;
                else {
                    if(adj_mat[i][j] > adj_mat[i][k]+adj_mat[k][j] && K>0 ) { 
                        --K;
                        adj_mat[i][j]=min(adj_mat[i][j],adj_mat[i][k]+adj_mat[k][j]);
                    }
                }
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> graph (n, vector<int> (n, 0) );
        
        for (auto & f : flights) {
            graph[f[0]][f[1]] = f[2];
        }
        
        floyds (graph,n,K);
        
        //cout << K << "\n";
        
        return K>=0? (graph[src][dst]>0)?graph[src][dst]:-1:-1;
    }
};