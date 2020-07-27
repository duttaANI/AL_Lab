#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

static void dfs(vector< unordered_map<unsigned,int>  >& graph,vector<vector<int> >& ans, vector<int> path, unsigned src , int cost, vector<int>& vis ) { // & in vis is sure
    // cout << "src " << src+1 << "\n";
    // for(auto i: vis)
    //     cout << i << " " ;
    // cout << "\n";
    
    if(vis[src]==0){
        if(src!=graph.size()-1)
            vis[src] = 1;  // being explored
        if ( src == graph.size()-1 )
        {
            path.push_back(cost);
            ans.push_back(path);
        }
        else {
            path.push_back(cost);
            for ( auto n : graph[src] ){ 
                dfs (graph, ans, path, n.first, n.second, vis);
            }
            vis[src] = 2; // visited
        }
    }else if (vis[src]==1){ // cycle detected
        //cout << "src should be 2 " << src+1 << "\n"; 
        cout << -1;
        exit(0);
    }else{
        return;
    }
}
    
static vector<vector<int> >allPathsSourceTarget( vector< unordered_map<unsigned,int> >& graph) {
    vector< vector< int > > ans;   vector< int > path;
    vector<int> vis (graph.size(),0); // 0-> not visited , 1->being explored, 2->visited
    dfs(graph, ans, path, 0, 0, vis);
    return ans;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m,b,c;
    unsigned a,n;
    cin >> n >> m;
    vector< unordered_map<unsigned,int> > G(n);
    for(int i=0; i<m; ++i){
        cin >> a >> b >> c;
        G[a-1].insert( make_pair(b-1,c) ); // dst , weight
    }

    vector< vector<int> > ans;   vector<int> price(1000000,0); 
    ans = allPathsSourceTarget(G);

    if(ans.size()==0)
      cout << -1;

    for( unsigned i =0; i<ans.size(); ++i){
      for(unsigned j=1; j<ans[i].size(); ++j)
      {
        //cout << ans[i][j] << " ";
        price[i] = price[i] + ans[i][j] ;
      }
      //cout << "\n";
      //cout << price[i] << "\n";
    }
    
    int A=-2147483646;
    for(unsigned i=0; i<ans.size(); ++i)
    {
      if(A<price[i])
        A = price[i];
    }
    cout << A;
    return 0;
}
