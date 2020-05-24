// link: https://leetcode.com/problems/combinations/discuss/27111/My-shortest-c%2B%2B-solutionusing-dfs
class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& temp, int start, int temp_size, int n, int k) {
        
        if(temp_size==k ) {
            ans.push_back(temp);
            return ;
        }
        
        for (int i=start; i<n; ++i) {   
            temp.push_back(i+1);
            
            dfs(ans, temp, i+1, temp_size+1, n, k);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans; vector<int> temp;
        if(n<k)return ans;
        dfs(ans, temp, 0, 0, n, k);
         
        return ans;
    }
};