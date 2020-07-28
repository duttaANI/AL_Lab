// dijkstra

class Solution {
public:
    
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
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector< vector< pair< int ,int > > > G(N);
        for( auto t : times ){
            // cout << t[0] << " " << t[1] << " " << t[2] << "\n";
            G[t[0]-1].push_back( make_pair( t[1]-1, t[2]) ); // dst , weight
        }
        
        vector<int> d,p;
        
        dijkstra(K-1, d, p, G );
        
        int max=0;
        for( int i=0; i<d.size(); ++i )
        {
            // cout << d[i] << " ";
            if(d[i]>max) max = d[i];
        }
        
        return max==INT_MAX?-1:max;
    }
};