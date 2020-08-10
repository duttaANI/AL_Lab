
// Dijkstra with    priority queue  (Accepted)

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> g(n);
        for(int i=0; i<edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});   
        }
        
        vector<double> d;
        
        dijkstra(start, d, g );
        
        // for(int i=0; i<d.size(); ++i){
        //     cout << d[i] << " ";
        // }
        
        return d[end];
    }
    
private:
    void dijkstra(int s, vector<double> & d,vector< vector< pair<int,double> > >& G ) {
        int n = G.size();
        d.assign(n, 0);
        
        d[s] = 1.0;
        using pii = pair<double, int>;
        priority_queue<pii, vector<pii>> q;
        q.push({0, s});
        while (!q.empty()) {
            int v = q.top().second;
            int d_v = q.top().first;
            q.pop();
            // if (d_v != d[v])
            //     continue;

            for (auto edge : G[v]) {
                int to = edge.first;
                double len = edge.second;

                if (d[v] * len > d[to]) {
                    
                    d[to] = d[v] * len;
                    q.push({d[to], to});
                }
            }
        }
    }
};

// Dijkstra without priority queue (TLE)
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> g(n);
        for(int i=0; i<edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});   
        }
        
        vector<double> d,p;
        
        dijkstra(start, d, p, g );
        
        // for(int i=0; i<d.size(); ++i){
        //     cout << d[i] << " ";
        // }
        
        return d[end];
    }
    
private:
    void dijkstra(int s, vector<double> & d, vector<double> & p,vector< vector< pair<int,double> > >& G ) {
        int n = G.size();
        d.assign(n, 0.0);
        p.assign(n, -1);
        
        d[s] = 1.0;
        set<pair<double, int>> q;
        q.insert({0, s});
        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            for (auto edge : G[v]) {
                int to = edge.first;
                double len = edge.second;

                if (d[v] * len > d[to]) {
                    q.erase({d[to], to});
                    d[to] = d[v] * len;
                    p[to] = v;
                    q.insert({d[to], to});
                }
            }
        }
    }
};