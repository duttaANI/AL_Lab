
int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    // cout << B.size() << " " << C.size() << "\n"; 
    vector<int> adj[A+5];
    vector<int> incoming(A+5,0);
    vector<int> toposort;
    for( int i=0; i<B.size(); ++i ){ // directed
        adj[B[i]].push_back(C[i]);
        incoming[C[i]]++;
    }
    
    queue<int> q;
    for(int i =1; i<=A; ++i){
        if(incoming[i]==0){
            q.push(i);
            // cout << i << "\n";
        }
    }
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        // cout << "u " << u << "\n";
        toposort.push_back(u);
        for(int v : adj[u]){
            if( (--incoming[v])==0 ){
                q.push(v);
            }
        }
    }
    
    // for(int i : toposort){
    //     cout << i << " ";
    // }
    
    // cout << "\n" << toposort.size() << "  topo size\n";
    
    if(toposort.size()==A){
        return 1;
    }
    return 0;
}
