// using dijkstra 3 <getting max cost from parents>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int INF = 1000000000;

int getMaxCost( vector<int> & path, vector< vector< pair<unsigned,int> > > G ){
    int ans=0,cur;
    int n = path.size()-1;
    //cout <<  "path " << path[n] << "\n";
    while( n!=0 ){
        //cout << n << " ";
        cur = G[path[n]][n].second;
        if(cur>ans)
            ans=cur;
        n= path[n];
        //cout << path[n] << "\n";
    }
    //cout << "ans " << ans << "\n";
    return ans;
}

void dijkstra(int s,vector<int> & d, vector< pair<int,int> > & record,vector< vector< pair<unsigned,int> > >& G,vector<int> & path ) {
    int n = G.size();
    d.assign(n, INF);
    path.assign(n, -1);
    record.push_back( make_pair(1, INF ));
 
    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : G[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                path[to] = v;
                q.erase({d[to], to});
                d[to] = d[v] + len;
                
                if( to==n-1  ){
                    //cout << "n-1 " << d[v] + len << "\n";
                    record.push_back( make_pair(getMaxCost(path,G),d[v] + len ) );                     
                }
                
                q.insert({d[to], to});
            }
        }
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m,b,c,ans=INF,cur;
    unsigned a,n;
    cin >> n >> m;
    vector< vector< pair<unsigned,int> > > G(n);
    for(int i=0; i<m; ++i){
        cin >> a >> b >> c;
        G[a-1].push_back( make_pair(b-1,c) ); // dst , weight
    }

    // for( unsigned i =0; i<G.size(); ++i){
    //   for(unsigned j=0; j<G[i].size(); ++j)
    //   {
    //     cout << G[i][j].first << " " << G[i][j].second << " ";
    //   }
    //   //cout << "\n";
    // }

    vector<int> min_cost,path; // min_cost->d
    vector< pair<int,int> > record;
    dijkstra(0,min_cost,record,G,path);
    
    for(auto i: record)
        cout << i.second << " " << i.first << "\n";

    for(auto i: record){
        cur = i.second - i.first + i.first/2;
        if(ans>cur)
            ans=cur;
    }
    
    cout << ans;
    
    return 0;
}


// using dijkstra 2
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

// static void dfs(vector< vector< pair<unsigned,int> > >& graph,vector<vector<int> >& ans, vector<int> path, unsigned src , int cost, vector<bool> vis ) {
//     if(!vis[src]){
//         vis[src] = true;
//         //cout << "size " << graph.size() <<  "src " << src << "\n";
//         if ( src == graph.size()-1 )
//         {
//             path.push_back(cost);
//             ans.push_back(path);
//         }
//         else {
//             path.push_back(cost);
//             //if( src+1<graph.size()-1 )
//             for ( auto n : graph[src] ){
//                 //cout << "n.first, n.second" << n.first << " " <<  n.second << "\n";
//                 if(!vis[n.first])
//                 dfs (graph, ans, path, n.first, n.second, vis);
//             }

//         }
//     }
// }
    
// static vector<vector<int> >allPathsSourceTarget( vector< vector< pair<unsigned,int> > >& graph) {
//     vector< vector< int > > ans;   vector< int > path;
//     vector<bool> vis (graph.size(),false);
//     dfs(graph, ans, path, 0, 0, vis);
//     return ans;
// }

const int INF = 1000000000;

void dijkstra(int s, vector<int> & d, vector< pair<int,int> > & record,vector< vector< pair<unsigned,int> > >& G ) {
    int n = G.size();
    d.assign(n, INF);
    record.assign(1, INF);

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : G[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                if(to==n-1 && record[record.size()-1]> d[v]+len)
                    record.push_back( make_pair(d[v] + len,len) );
                q.insert({d[to], to});
            }
        }
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m,b,c;
    unsigned a,n;
    cin >> n >> m;
    vector< vector< pair<unsigned,int> > > G(n);
    for(int i=0; i<m; ++i){
        cin >> a >> b >> c;
        G[a-1].push_back( make_pair(b-1,c) ); // dst , weight
    }

    // for( unsigned i =0; i<G.size(); ++i){
    //   for(unsigned j=0; j<G[i].size(); ++j)
    //   {
    //     cout << G[i][j].first << " " << G[i][j].second << " ";
    //   }
    //   //cout << "\n";
    // }

    vector<int> min_cost;
    vector< pair<int,int> > record;
    dijkstra(0,min_cost,record,G);
    
    for(auto i: record)
        cout << i << " ";
    
    //cout << min_cost[n-1] - record[n-1] + record[]/2
    
    return 0;
}




// using djikstra ------------------------------------------------------------------------------------------------------------------

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int INF = 1000000000;

void dijkstra(int s, vector<int> & d, vector<int> & maxele,vector< vector< pair<unsigned,int> > >& G ) {
    int n = G.size();
    d.assign(n, INF);
    maxele.assign(n, -1);

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : G[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                if(maxele[to]<edge.second)
                    maxele[to] = edge.second;
                q.insert({d[to], to});
            }
        }
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m,b,c;
    unsigned a,n;
    cin >> n >> m;
    vector< vector< pair<unsigned,int> > > G(n);
    for(int i=0; i<m; ++i){
        cin >> a >> b >> c;
        G[a-1].push_back( make_pair(b-1,c) ); // dst , weight
    }

    // for( unsigned i =0; i<G.size(); ++i){
    //   for(unsigned j=0; j<G[i].size(); ++j)
    //   {
    //     cout << G[i][j].first << " " << G[i][j].second << " ";
    //   }
    //   //cout << "\n";
    // }

    vector<int> min_cost, maxele;
    dijkstra(0,min_cost,maxele,G);
    
//     for(auto i: min_cost)
//         cout << i << " ";
//     cout << "\n";
    
//     for(auto i: maxele)
//         cout << i << " ";
//     cout << "\n";
//     cout << maxele[n-1] << " " << min_cost[n-1] << "\n";
    cout << min_cost[n-1] - maxele[n-1] + maxele[n-1]/2;
    
    return 0;
}





// using unordered_map ------------------------------------------------------------------------------------------------------------------------------
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

static void dfs(vector< unordered_map<unsigned,int>  >& graph,vector<vector<int> >& ans, vector<int> path, unsigned src , int cost, vector<bool> vis ) {
    if(!vis[src]){
        vis[src] = true;
        //cout << "size " << graph.size() <<  "src " << src << "\n";
        if ( src == graph.size()-1 )
        {
            path.push_back(cost);
            ans.push_back(path);
        }
        else {
            path.push_back(cost);
            //if( src+1<graph.size()-1 )
            for ( auto n : graph[src] ){
                //cout << "n.first, n.second" << n.first << " " <<  n.second << "\n";
                if(!vis[n.first])
                dfs (graph, ans, path, n.first, n.second, vis);
            }

        }
    }
}
    
static vector<vector<int> >allPathsSourceTarget( vector< unordered_map<unsigned,int> >& graph) {
    vector< vector< int > > ans;   vector< int > path;
    vector<bool> vis (graph.size(),false);
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

    vector< vector<int> > ans;   vector<int> price(1000000,0); int maxele;
    ans = allPathsSourceTarget(G);
    //cout << "ans\n";

    if(ans.size()==0)
      cout << -1;

    for( unsigned i =0; i<ans.size(); ++i){
      maxele=0;
      for(unsigned j=1; j<ans[i].size(); ++j)
      {
        if(ans[i][j]>maxele)
          maxele = ans[i][j];
        //cout << ans[i][j] << " ";
        price[i] = price[i] + ans[i][j] ;
      }
        //cout << maxele << "\n";
        //cout << "\n";
      price[i] = price[i] -maxele + maxele/2;
      //cout << price[i] << "\n";
    }
    
    int A=2147483647;
    for(unsigned i=0; i<ans.size(); ++i)
    {
      if(A>price[i])
        A = price[i];
    }
    cout << A;
    return 0;
}

// using vectors ----------------------------------------------------------------------------------------------------------------------------------------

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static void dfs(vector< vector< pair<unsigned,int> > >& graph,vector<vector<int> >& ans, vector<int> path, unsigned src , int cost, vector<bool> vis ) {
    if(!vis[src]){
        vis[src] = true;
        //cout << "size " << graph.size() <<  "src " << src << "\n";
        if ( src == graph.size()-1 )
        {
            path.push_back(cost);
            ans.push_back(path);
        }
        else {
            path.push_back(cost);
            //if( src+1<graph.size()-1 )
            for ( auto n : graph[src] ){
                //cout << "n.first, n.second" << n.first << " " <<  n.second << "\n";
                if(!vis[n.first])
                dfs (graph, ans, path, n.first, n.second, vis);
            }

        }
    }
}
    
static vector<vector<int> >allPathsSourceTarget( vector< vector< pair<unsigned,int> > >& graph) {
    vector< vector< int > > ans;   vector< int > path;
    vector<bool> vis (graph.size(),false);
    dfs(graph, ans, path, 0, 0, vis);
    return ans;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m,b,c;
    unsigned a,n;
    cin >> n >> m;
    vector< vector< pair<unsigned,int> > > G(n);
    for(int i=0; i<m; ++i){
        cin >> a >> b >> c;
        G[a-1].push_back( make_pair(b-1,c) ); // dst , weight
    }

    // for( unsigned i =0; i<G.size(); ++i){
    //   for(unsigned j=0; j<G[i].size(); ++j)
    //   {
    //     cout << G[i][j].first << " " << G[i][j].second << " ";
    //   }
    //   //cout << "\n";
    // }

    vector< vector<int> > ans;   vector<int> price(1000000,0); int maxele;
    ans = allPathsSourceTarget(G);
    //cout << "ans\n";

    if(ans.size()==0)
      cout << -1;

    for( unsigned i =0; i<ans.size(); ++i){
      maxele=0;
      for(unsigned j=1; j<ans[i].size(); ++j)
      {
        if(ans[i][j]>maxele)
          maxele = ans[i][j];
        //cout << ans[i][j] << " ";
        price[i] = price[i] + ans[i][j] ;
      }
        //cout << maxele << "\n";
        //cout << "\n";
      price[i] = price[i] -maxele + maxele/2;
      //cout << price[i] << "\n";
    }
    
    int A=2147483647;
    for(unsigned i=0; i<ans.size(); ++i)
    {
      if(A>price[i])
        A = price[i];
    }
    cout << A;
    return 0;
}

