// int Solution::solve(int A, vector<vector<int> > &B) {
//     if(A<=3)
//         return 0;
//     //to store parent of each node i
//     int parent[A+1]={0};
//     parent[1]=-1;
//     //to store number of edges in the subtree with root i
//     int edges[A+1]={0};
//     for(int i=0;i<B.size();i++)
//     {
//         parent[B[i][1]]=B[i][0];
//         edges[B[i][0]]++;
//     }
//     for(int i=A;i>1;i--)
//         edges[parent[i]]+=edges[i];
//     int ans=0;
    
//     for(int i=2;i<=A;i++)
//     {
//         if(edges[i]%2==1)
//             ans++;
//     }
//     return ans;
// }



int help(int root, unordered_map<int, vector<int>>& adj, int& ans, int p){
    if((adj[root]).size() == 1 && adj[root][0] == p){ // leaf node, p is parent node
        return 1;
    }
    int nodes = 1; // size of the current tree
    for(auto child : adj[root]){
        if(child == p)continue;
        int sz = help(child, adj, ans, root); // subtree size
        if(sz % 2 == 0){
            ans++;
        }else{
            nodes += sz;
        }
    }
    return nodes;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    unordered_map<int, vector<int>> adj; // adjacency list
    for(int i = 0; i < B.size(); i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    // choose root 
    int root = B[0][0];
    int ans = 0;
    int sz = help(root, adj, ans, -1); // help returns size of the tree
    return ans;
}

// My


const int mxN =1e5;
int ans = 0;

int help( int cur , vector<int> adj[mxN], int par ){
    int nodes = 1;
    
    for( int v : adj[cur] ){
        if( v==par  ) continue;
        int sz = help ( v,adj,cur );
        if( sz%2==0 ) ++ans;
        else{
            nodes += sz;
        }
    }
    
    return nodes;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    ans = 0;
    vector<int> adj[mxN];
    for( auto e : B ){
        adj[ e[0]-1 ].push_back( e[1]-1 );
        adj[ e[1]-1 ].push_back( e[0]-1 );
    }
    
    help(0,adj, -1);
    
    return ans;
}
