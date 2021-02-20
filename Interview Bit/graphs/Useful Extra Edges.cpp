#define ll long long
#define ar array

const int mxN = 1e5+17;

void dij(int u, vector<ar<int,2>> adj[mxN], int d[mxN]){
    memset(d,0x3f,mxN*sizeof(int));  // NOTE -> sizeof(d1) is IMP and memset(d,0x3f,sizeof(d)) is wrong
    d[u] = 0;
    priority_queue< ar<int,2> , vector<ar<int,2>> , greater<ar<int,2>> > pq;  // it contains {dist to reach city A from node B, city A}
    pq.push({0,u});
    while(pq.size()){
        ar<int,2> u = pq.top(); pq.pop();
        // link : https://cp-algorithms.com/graph/dijkstra_sparse.html
        if( u[0]>d[u[1]] ) // some priority queue reason -> We simply don't delete the old pair from the pqueue. As a result a vertex can appear multiple times with different distance in the pqueue at the same time. Among these pairs we are only interested in the pairs where the first element is equal to the corresponding value in d[], all the other pairs are old. Therefore we need to make a small modification: at the beginning of each iteration, after extracting the next pair, we check if it is an important pair or if it is already an old and handled pair.
            continue;
        for( ar<int,2> v : adj[u[1]] ){
            if( d[v[1]] > u[0] + v[0]  ){
                d[v[1]] = u[0] + v[0];
                pq.push({d[v[1]],v[1]});
            }
        }
    }
}



int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {

    int n,m;
    vector<ar<int,2>> adj1[mxN], adj2[mxN];
    int d1[mxN],d2[mxN]; // min dist to reach city i (present at ith index) from src city

    for(int i=0; i<A; ++i){
        d1[i]=d2[i]=0;
    }

    C=C-1;
    D=D-1;
    for( auto e : B ){
        adj1[e[0]-1].push_back({e[2],e[1]-1}); // {dist,city}
        adj2[e[1]-1].push_back({e[2],e[0]-1}); // {dist,city}
    }
    dij(C,adj1,d1);
    dij(D,adj2,d2);
    // int ans = mxN; // 1061109567 = 0x3f3f3f3f
    
    
    
    int ans = d1[D];
    // cout << "ans :" << ans << "\n";
    for ( auto e : E )
    {
        int s = e[0]-1;
        int d = e[1]-1;
        int w = e[2];
        ans = min({ans, (d1[s] + w + d2[d]),(d1[d] + w + d2[s])  });
        // cout << "ans :" << ans << "\n";
    }
    
    
    
    if(ans >= 1e9){
        return -1;
    }
    // cout << "ans :" << ans << "\n";
    return ans;
}
