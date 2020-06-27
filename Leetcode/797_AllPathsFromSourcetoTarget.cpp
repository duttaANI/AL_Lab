// link : https://leetcode.com/problems/all-paths-from-source-to-target/discuss/118647/C%2B%2B-DFS-Recursive-Easy-to-Understand
class Solution {
public:
    
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& ans, vector<int> path, int src ) {
        if ( src == graph.size()-1 )
        {
            path.push_back(src);
            ans.push_back(path);
        }
        else {
            path.push_back(src);
            for ( auto n : graph[src] )
                dfs (graph, ans, path, n);
            //path.pop_back();
        }
           
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;   vector<int> path;
        
        dfs(graph, ans, path, 0);
        
        return ans;
    }
};