

long int tot;
long int mx;
int mod = 1e9+7;
vector<vector<int> > adj;

long int dfs(int u, int par, vector<int> &A){
    long int sm = A[u];
    for(int i : adj[u]){
        if(i != par){
            int tmp = dfs(i, u, A);
            cout << tmp << " tmp\n";
            sm = (sm+tmp)%mod;
            cout << sm << " sub sum\n";
            mx = max(mx, tmp*(tot-tmp)%mod);
            cout << mx << " ans\n";
        }
        
    }
    return sm;
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    tot = 0, mx = 0;
    for(int i: A) tot += i;
    cout << tot << " tot\n";
    adj.clear();
    adj.resize(A.size());
    for(int i = 0; i < B.size(); i++){
        adj[B[i][0]-1].push_back(B[i][1]-1);
        adj[B[i][1]-1].push_back(B[i][0]-1);
    }
    dfs(0, 0, A);
    return mx;
}

