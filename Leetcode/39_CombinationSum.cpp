// link :https://www.youtube.com/watch?v=9lQnt4p7_nE
class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& temp, int start, int target, vector<int>& candidates) {
        
        if( 0==target ) {
            ans.push_back(temp);
            return ;
        } 
        
        for (int i=start; i<candidates.size(); ++i) {  
            
            if(candidates[i]>target) return ;
            
            temp.push_back(candidates[i]);
            
            dfs(ans, temp, i, target-candidates[i], candidates);
          
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        
        vector<vector<int>> ans; vector<int> temp;
     
        dfs(ans, temp, 0, target, candidates);
         
        return ans;
    }
};