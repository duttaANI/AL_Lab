// height are source , width are destination
class Solution {
public:
     void dfs(vector<bool>& visited, vector<vector<int>>& M, int node, stack<int>& s) {
        s.push(node);
         
        while(!s.empty()) {
            
            node = s.top();
            s.pop();
            
            if(visited[node]) continue;
            
            visited[node] = true;
            
            for (int j=0; j<M[0].size(); ++j) {
                
                if(M[node][j]==1 && !visited[j]) {
                    s.push(j);
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int ans =0;
        int h = M.size();
        
        vector<bool> visited (h,false);  stack <int> s;
        
        for(int i=0; i<h; ++i) {
            if (visited[i] == 0) {
                dfs(visited, M, i, s);
                ++ans;
            }
        }
        return ans;
    }
};