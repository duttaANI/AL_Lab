static const int mxN = 1e5;
int p[mxN],sz[mxN];
int find(int x){
    return p[x]^x? p[x]=find(p[x]):x;
}

int join(int x, int y){
    if( (x=find(x)) == (y=find(y)) ){
        return 0;
    }
    p[x] = y;
    // sz[y] += sz[x];
    return 1;
}

// int size(int x){
//     return sz[find(x)];
// }

int Solution::solve(int A, vector<vector<int> > &graph) {
    int n = graph.size();
    set<int> s;
    memset(p,0,sizeof(p));
    memset(sz,0,sizeof(sz));
        
    for(int i=0; i<mxN; ++i){
        sz[i]=1;
    }
    
    for(int i=0;i<A;++i){
        p[i]=i;
    }
    
    for(auto e: graph ){
       join(e[0]-1,e[1]-1);
    }
    
    for(int i=0;i<A;++i){
        // cout << i << " " << find(p[i]) << endl;
        s.insert( find(p[i]) );
    }
    
    return s.size();
}