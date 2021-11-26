#include <bits/stdc++.h>
using namespace std;

// node 0 is the root

#define MAXN 50000
 
int depth[MAXN];           // stores depth for each node
int parent[MAXN];          // stores first parent for each node
 
vector < int > adj[MAXN];

unordered_map<int,int> mp; // vertix , subtree sum value
 
void addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
void dfs(int cur, int prev)
{
    // marking parent for each node
    parent[cur] = prev;
 
    // marking depth for each node
    depth[cur] = depth[prev] + 1;
 
    // propogating marking down the tree
    for (int i=0; i<adj[cur].size(); i++)
        if (adj[cur][i] != prev)
            dfs(adj[cur][i],cur);
}
 
void preprocess()
{
    // a dummy node
    depth[0] = -1;
 
    // precalclating 1)depth.  2)parent.
    // for each node
    dfs(1,0);
}
 
// Time Complexity : O(Height of tree)
// recursively jumps one node above
// till both the nodes become equal
int LCANaive(int u,int v)
{
    if (u == v)  return u;
    if (depth[u] > depth[v])
        swap(u, v);
    v = parent[v];
    return LCANaive(u,v);
}
 
// Function to perform the DFS
// Traversal on the given Tree
void dfs(int v, int p, int ans[], vector<int>& vals )
{
     
    // To check if v is leaf vertex
    bool isLeaf = 1;
 
    // Initialize answer for vertex v
    ans[v] = INT_MIN;
 
    // Traverse adjacency list of v
    for(int u : adj[v])
    {
        if (u == p)
            continue;
             
        isLeaf = 0;
        dfs(u, v, ans, vals);
 
        // Update  subtree sum
        ans[v] = (ans[u] + vals[v]);
    }
 
    // If v is leaf
    if (isLeaf)
    {
        ans[v] = vals[v];
    }
}
 
// Function to calculate maximum
// subtree sum for each vertex
void printAnswer(int n, vector<int>& values)
{ 
    // Stores largest subtree
    // sum for each vertex
    int ans[n] ;
 
    // Calculate answer
    dfs(0, -1, ans, values);
 
    // Print the result
    for(int i=0;i<n;++i)
    {
        // cout << x << " ";
        mp[i] = ans[i];
    }
}

int solve(vector<int> &A , vector<vector<int>> &B){
    for(auto e: B){
        // adj[e[0]-1].push_back(e[1]-1);
        // adj[e[1]-1].push_back(e[0]-1);
        addEdge(e[0]-1,e[1]-1);
    }

    int ans = 0;

    preprocess();

    int nodes = A.size();

    printAnswer(nodes,A);

    for(int i=0;i<nodes;++i){
        for(int j=i+1;j<nodes;++j){
            int lca = LCANaive(i,j);
            if( lca!=i && lca!=j ){
                ans = max(ans, (mp[i]^mp[j]));
            }
        }
    }

    return ans;

}

int main(){
    // vector<int> A = {1,2};
    // vector<vector<int>> B = {
    //     {1,2}
    // };

    vector<int> A = {8,4,3};
    vector<vector<int>> B = {
        {1,2},
        {1,3}
    };


    cout << solve(A,B) << endl;

    return 0;
}