// my

// link : https://leetcode.com/problems/evaluate-division/discuss/455817/C%2B%2B-DFS-solution
class Solution {
public:

    unordered_map< string, vector< pair<string,double>  >  > adj;
    unordered_map< string, int >vis; // by default if entry is not there o/p is 0
    unordered_map< string, int >ext;
    double ans;
    
    void dfs( string x ,string dst, double cur  ){
        vis[x]=1;
        if(x==dst){
            ans = cur;
            return ;
        }
        for( pair<string,double> v : adj[x]  ){
            if( !vis[v.first]  ){
                dfs( v.first, dst , cur*v.second );
            }
        }
    }
     
    vector<double> calcEquation(vector<vector<string>>& equ, vector<double>& val, vector<vector<string>>& qry) {
        int n = equ.size();
        vector<double> res;
        
        for( int i=0; i<n; ++i ){
            adj[equ[i][0]].push_back({ equ[i][1],      (double)val[i] });
            adj[equ[i][1]].push_back({ equ[i][0],  (double)1.0/(double)val[i] });
            ext[ equ[i][0] ] = 1;
            ext[ equ[i][1] ] = 1;
        }
        
        int k = qry.size();
        for( int i=0;i<k;++i ){
            vis.clear(); 
            ans = -1.0;
            string src = qry[i][0],dst = qry[i][1];
            if( !ext[ src ] || !ext[ dst ]  ){
                res.push_back( -1.00000 );
                continue;
            }
            vis[ src ] = 1;
            dfs( src, dst, 1.0 );
            res.push_back( ans );
        }
        
        return res;
    }
};



// link : https://leetcode.com/problems/evaluate-division/discuss/455817/C%2B%2B-DFS-solution
class Solution {
public:
    
    bool dfs(string cur, string target, unordered_map<string, vector<pair<string, double>>>& adjlist, unordered_set<string>& visited, double& val) {
        if (!adjlist.count(target) or !adjlist.count(cur)) {
            // not in graph
            return false;
        }
        else if (cur == target) {
            // found, val is the result
            return true;
        }
        else {
             // keep searching
            visited.insert(cur);
            for (auto& node : adjlist[cur]) {
                if (!visited.count(node.first)) {
                    double lastval = val;
                    val *= node.second;
                    if (dfs(node.first, target, adjlist, visited, val)) {
                        return true;
                    }
                    val = lastval;
                }
            }
			// no path found
            return false;
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // construct graph adj list
        unordered_map<string, vector<pair<string, double>>> adjlist;
        for (int i(0); i < equations.size(); ++i) {
            string nume = equations[i][0];
            string deno = equations[i][1];
            double rst = values[i];
            
            if (!adjlist.count(nume)) {
                adjlist[nume] = vector<pair<string, double>>();
            }
            adjlist[nume].push_back(make_pair(deno, rst));
            if (!adjlist.count(deno)) {
                adjlist[deno] = vector<pair<string, double>>();
            }
            adjlist[deno].push_back(make_pair(nume, 1.0 / rst));
        }
        
        // process each query by DFS
        vector<double> rst;
        for (const auto& x : queries) {
            unordered_set<string> visited;
            double val = 1.0;
            if (dfs(x[0], x[1], adjlist, visited, val)) {
                rst.push_back(val);
            }
            else {
                rst.push_back(-1.0);
            }
        }
        return rst;
    }
};
