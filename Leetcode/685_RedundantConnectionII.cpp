// link : https://leetcode.com/problems/redundant-connection-ii/discuss/108045/C%2B%2BJava-Union-Find-with-explanation-O(n)

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0), candA, candB;
        // step 1, check whether there is a node with two parents
        for (auto &edge:edges) {
            if (parent[edge[1]] == 0)
                parent[edge[1]] = edge[0]; 
            else {
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = 0;
            }
        } 
        // step 2, union find
        for (int i = 1; i <= n; i++) parent[i] = -1;
        for (auto &edge:edges) {
            if (edge[1] == 0) continue;
            int pu,pv;
            int u = edge[0], v = edge[1], ur = find(parent, u, pu), vr = find(parent, v, pv); // ur -> rank of parent pu , vr ..
            
            // cout << u << " " << v << " " << pu << " " << pv << " " << ur << " " << vr << "\n";
          
            if (pu == pv) {
                if (candA.empty()) return edge;
                return candA;
            }
            
            // perform weighted union
            if ( ur < vr ) {   // rank of pu is lesser implies that it has more children compared to pv

                parent[pu] = ur + vr;        // increasing magnitude ( ranks are -ve) of rank of pu since it's children incresed by amount "vr"
                parent[pv] = pu;         // collapsing path
            } else if ( vr < ur ) {
                parent[pv] = ur + vr;
                parent[pu] = pv;
            } else { // (ur == vr) 
                parent[pu] = ur + vr;
                parent[pv] = pu;
            }
        }
        return candB;
    }
private:
    
    int find(vector<int> &parent, int x, int & i) //  pu address is passed (by reference)
    {
        /*
        this function returns the rank of parent
        */
        i = x;
        return parent[x]<0?parent[x]:find(parent,parent[x],i);
    }
    
};