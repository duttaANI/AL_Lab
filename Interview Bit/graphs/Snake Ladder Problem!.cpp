
int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    vector<int> adj[100];
    unordered_map <int,int> mp;
    for(auto e : A){
        mp[e[0]-1]=(e[1]-1);
    }
    for(auto e : B){
        mp[e[0]-1]=(e[1]-1);
    }
    for(int i=0;i<100; ++i){
        for(int j=1;j<=6;++j){
            if(i+j<100)
                adj[i].push_back(i+j);
        }
    }
    
    queue <int> q;
    q.push(0);
    
    vector<int> vis(100,0);
    vis[0] = 1;
    int ans=0;
    while(!q.empty()){
        int k = q.size();
        ++ans;
        // cout << endl;
        while(k--){
            int frnt = q.front(); q.pop();
            // cout << frnt+1 << endl;
            if(frnt==99){
                return ans-1;
            }
            for(int v : adj[frnt]){
                if(!vis[v]){
                    vis[v]=1;
                    if(mp.find(v)!=mp.end()){
                        v=mp[v];
                    }
                    
                    q.push(v);
                }
            }
        }
    }
    return -1;
}

