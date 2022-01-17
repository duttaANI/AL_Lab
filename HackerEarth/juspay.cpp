/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;

unordered_map <int,int> IDtomy,mytoID;

void dijkstra(int s, vector<int> & d, vector<int> & p,vector< vector< pair<int,int> > >& G ) {
        int n = G.size();
        d.assign(n, INT_MAX);
        p.assign(n, -1);
        
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
                    p[to] = v;
                    q.insert({d[to], to});
                }
            }
        }
    }

int main(){
	int N;
	cin >> N;

    vector< vector< pair< int ,int > > > G(N);

    for(int i=0;i<N;++i){
        int temp;
        cin >> temp;
        IDtomy[temp] = i;
        mytoID[i] = temp;
    }

    int edge;
    cin >> edge;

    for(int i=0;i<edge; ++i){
        int a,b,c;
        cin >> a >> b >> c;
        G[ IDtomy[a] ].push_back( make_pair( IDtomy[b], c ) );
    }

    int src,dst;
    cin >> src >> dst;

	vector<int> d,p;
	
	dijkstra(IDtomy[src], d, p, G );

    // for(int i =0;i<N;++i){
    //     cout << mytoID[i] << " " << mytoID[p[i]] << endl;
    // }

    // int ans = p[IDtomy[dst]];
    
    int ans = -1;
    if(  d[IDtomy[dst]]!=INT_MAX )
    ans =  d[IDtomy[dst]];
    cout << ans;
    return 0;
}




















/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

#define ar array

vector<int> adj[mxN],Radj[mxN];
int vis[mxN];
unordered_map <int,int> IDtomy,mytoID;


int main(){
    int N;
    set<int> ans;
    cin >> N;
    for(int i=0;i<N;++i){
        int temp;
        cin >> temp;
        IDtomy[temp] = i;
        mytoID[i] = temp;
    }

    int edge;
    cin >> edge;

    for(int i=0;i<edge; ++i){
        int a,b;
        cin >> a >> b;
        adj[IDtomy[a]].push_back(IDtomy[b]);
        Radj[IDtomy[b]].push_back(IDtomy[a]);
    }

    int src , dst;
    cin >> src >> dst;

    queue<int> q;

    vis[ IDtomy[src]  ] = 1;
    q.push(IDtomy[src]);

    while(q.size()){
        int k = q.size();
        for(int i=0; i<k ; ++i){
            int f = q.front(); q.pop();
            
            for(  int v : adj[f] ){
                if( v == IDtomy[dst] ){
                    ans.insert(mytoID[f]);
                    // cout << mytoID[f] << " ";
                }
                if( !vis[v] ){
                    q.push(v);
                    vis[v] =1;
                    // cout << mytoID[v] << endl;
                }
            }
        }
    }

    int all_followers= adj[IDtomy[dst]].size();

    // for( int v:Radj[IDtomy[dst]] ){
    //     if( vis[v] ){
    //         cout << mytoID[v] << " ";
    //     }
    // }

    if(ans.size())

    for(int i : ans){
        cout << i << " ";
    }

    else{
        cout << -1;
    }

    // cout << ans;

    return 0;
}












/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

#define ar array

vector<int> adj[mxN];
int vis[mxN];
unordered_map <int,int> IDtomy,mytoID;


int main(){
    int N,ans =0;
    cin >> N;
    for(int i=0;i<N;++i){
        int temp;
        cin >> temp;
        IDtomy[temp] = i;
        mytoID[i] = temp;
    }

    int edge;
    cin >> edge;

    for(int i=0;i<edge; ++i){
        int a,b;
        cin >> a >> b;
        adj[IDtomy[a]].push_back(IDtomy[b]);
        // adj[IDtomy[b]].push_back(IDtomy[a]);
    }

    int src , dst;
    cin >> src >> dst;

    queue<int> q;

    vis[ IDtomy[src]  ] = 1;
    q.push(IDtomy[src]);

    while(q.size()){
        int f = q.front(); q.pop();
        for(  int v : adj[f] ){
            if( !vis[v] ){
                q.push(v);
                vis[v] =1;
                // cout << mytoID[v] << endl;
            }
        }
    }

    if(vis[IDtomy[dst]]){
        ans = 1;
    }

    cout << ans;

    return 0;
}
