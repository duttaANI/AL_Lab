// link : https://www.youtube.com/watch?v=wU6udHRIkcc&t=272s
/*
in this algo if ith index has -ve value => i is it is parent
parent vector stores rank and parents
*/
class Solution {
public:
    
    bool w_union(int x, int y, vector<int> &parent) {
        int x_idx; // represents parent
        int xr = find(x,parent,x_idx); // xr is rank of parent x_idx
        //cout << x_idx << "x_idx\n";
        int y_idx; // represents parent
        int yr = find(y,parent,y_idx);
        //cout << y_idx << "y_idx\n";
        
        // perform weighted union
        if ( xr < yr ) {
           
            parent[x_idx] = xr + yr;
            parent[y_idx] = x_idx;         // collapsing path
        } else if ( yr < xr ) {
           
            parent[y_idx] = xr + yr;
            parent[x_idx] = y_idx;
        } else { // (xr == yr) != -1
            
            if (x_idx == y_idx){
                
                return false;
            } 
            else {
                int m = min (x_idx,y_idx); int b = max(x_idx,y_idx);
                parent[m] = xr + yr;
                parent[b] = m;
            }
        }
        
        return true;
    }
    
    int find(int x,vector<int> &parent, int & i) //  x_idx address is passed (by reference)
    {
        i = x;
        return parent[x]<0?parent[x]:find(parent[x],parent,i);
    }
    
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        vector<int> parent (N+1,-1);  
        
        
        for(auto &x:edges) {
            if(!w_union(x[0], x[1], parent)) return {min(x[0],x[1]),max(x[0],x[1])};
        }
        return {};
        
    }
};
