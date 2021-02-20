int Solution::solve(vector<int> &par) {
    if(par.size()==1) return 0;
    
    int nodes=par.size();
    vector<int> tree[nodes];
    int root=0;
    for(int i=0;i<par.size();i++)
    {
        if(par[i]==-1)
            root=i;
        else{
            tree[par[i]].push_back(i);
            tree[i].push_back(par[i]);
        }
    }
    
    //BFS
    queue<int> q;
    vector<int> vis(nodes,0);
    vis[root]=1;
    q.push(root);
    int frnt;
    while(!q.empty()){
        
        int k = q.size();
        while(k--){
            frnt = q.front(); q.pop();
            for(int v : tree[frnt]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    
    for(int i=0;i<nodes;++i){
        vis[i]=0;
    }
    
    vis[frnt]=1;
    queue<int> q2;
    q2.push(frnt);
    int ans=0;
    int frnt2;
    while(!q2.empty()){
        int k = q2.size();
        ++ans;
        while(k--){
            frnt2 = q2.front(); q2.pop();
            for(int v : tree[frnt2]){
                if(!vis[v]){
                    q2.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    return ans-1;
}
