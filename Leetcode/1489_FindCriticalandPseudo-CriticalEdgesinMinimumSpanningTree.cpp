// link : https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/discuss/697761/C%2B%2B-Solution-enumerating-edges-with-explanation
class UnionFind {
public:
    UnionFind(int n) {
        rank = vector<int>(n, 1);
        f.resize(n);
        for (int i = 0; i < n; ++i) f[i] = i;
    }
    
    int Find(int x) {
        if (x == f[x]) return x;
        else return f[x] = Find(f[x]);
    }
    
    void Union(int x, int y) {
        int fx = Find(x), fy = Find(y);
        if (fx == fy) return;
        if (rank[fx] > rank[fy]) swap(fx, fy);
        f[fx] = fy;
        if (rank[fx] == rank[fy]) rank[fy]++;
    }
    
private:
    vector<int> f, rank;
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        int origin_mst = GetMST(n, edges, -1);
        vector<int> critical, non_critical;
        for (int i = 0; i < edges.size(); ++i) {
            if (origin_mst < GetMST(n, edges, i)) {
                critical.push_back(edges[i][3]);
            } else if (origin_mst == GetMST(n, edges, -1, i)) {
                non_critical.push_back(edges[i][3]);
            }
        }
        return {critical, non_critical};
    }
    
private:
    int GetMST(const int n, const vector<vector<int>>& edges, int blockedge, int pre_edge = -1) {
        UnionFind uf(n);
        int weight = 0;
        if (pre_edge != -1) {
            weight += edges[pre_edge][2];
            uf.Union(edges[pre_edge][0], edges[pre_edge][1]);
        }
        for (int i = 0; i < edges.size(); ++i) {
            if (i == blockedge) continue;
            const auto& edge = edges[i];
            if (uf.Find(edge[0]) == uf.Find(edge[1])) continue;
            uf.Union(edge[0], edge[1]);
            weight += edge[2];
        }
        for (int i = 0; i < n; ++i) {
            if (uf.Find(i) != uf.Find(0)) return 1e9+7; // means MST could not be formed
        }
        return weight;
    }
};


// My solution doesnt work but Krushkals algo works properly as taken from CP Algorithms

class Solution {
public:
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
       
        // vector<Edge> edges;
        vector<vector<int>> ANS;
        vector<int> cr, pcr;
        sort(edges.begin(), edges.end(),cmp);
        
        int base = MST(n, edges, -1);
        // cout << base << "\n";
        
        for (int i = 0; i<edges.size(); i++){
          int newVal = MST(n, edges, i);
          // cout << newVal << "\n";
          if (newVal > base) cr.push_back(i);
          else{
              newVal = MST_p(n, edges, i);
              if (newVal == base) pcr.push_back(i);
          }
        }
        
        ANS.push_back(cr);
        ANS.push_back(pcr);
        return ANS;
    }
    
private:
    
    int MST_p(int n,vector<vector<int>>& edges, int include ){
        
        vector<int> parent,rank;
        int cost = 0;
        vector<vector<int>> result;
        
        // result.push_back(edges[include]);
        parent.resize(n);
        rank.resize(n);
     
        for (int i = 0; i < n; i++){
            make_set(i,parent,rank);
        }
        
        // include edges[include]
        cost += edges[include][2];
        result.push_back(edges[include]);
        union_sets(edges[include][0], edges[include][1], parent, rank);
        
        int count=0;
        for ( auto e : edges) {
            if( count == include ) {
                // cout << "count " << count << "\n";
                ++count;
                continue;
            }
            if ( find_set(e[0], parent) != find_set(e[1], parent) ) {
                cost += e[2];
                result.push_back(e);
                union_sets(e[0], e[1], parent, rank);
            }
            ++count;
        }
        return cost;
    }
    
    int MST(int n,vector<vector<int>>& edges, int remove ){
        
        vector<int> parent,rank;
        int cost = 0;
        vector<vector<int>> result;
        
        parent.resize(n);
        rank.resize(n);
     
        for (int i = 0; i < n; i++){
            // if( remove == i) continue;
            make_set(i,parent,rank);
        }
        
        int count=0;
        for ( auto e : edges) {
            if( count == remove ) {
                // cout << "count " << count << "\n";
                ++count;
                continue;
            }
            if ( find_set(e[0], parent) != find_set(e[1], parent) ) {
                cost += e[2];
                result.push_back(e);
                union_sets(e[0], e[1], parent, rank);
            }
            ++count;
        }
        
        return cost;
    }

    void make_set(int v, vector<int>& parent, vector<int>& rank) {
        parent[v] = v;
        rank[v] = 0;
    }

    int find_set(int v, vector<int>& parent) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v], parent);
    }

    void union_sets(int a, int b, vector<int>& parent, vector<int>& rank) {
        a = find_set(a,parent);
        b = find_set(b,parent);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }

    struct Edge {
        int u, v, weight;
        bool operator<(Edge const& other) {
            return weight < other.weight;
        }
    };

    static bool cmp(vector<int> a, vector<int> b){  // sort in order of left point of each interval
        return a[2] < b[2];
    }
    
};