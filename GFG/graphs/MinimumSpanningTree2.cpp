class Solution{
    public:
    // Function to construct and print MST for
    // a graph represented using adjacency
    // list representation, with V vertices.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        int mincost=0;
        vector<bool> vis(V+1,false);
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
     pq.push({0,0});
     while(!pq.empty()){
      pair<int,int> s = pq.top();
      pq.pop();
      int x = s.second;
      if(vis[x])continue;
      mincost+=s.first;
      vis[x]=true;
      for(auto y: adj[x]){
        if(!vis[y[0]])
          pq.push({y[1],y[0]});
      }
     }
     return mincost;
    }
};
