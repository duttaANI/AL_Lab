class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        vector<vector<int>> res (r, vector<int>(c,0));
        if(nums.size()==0 || r*c !=nums.size()*nums[0].size())
            return nums;
        
        queue <int> Q;
        
        for (int i=0; i<nums.size(); ++i) {
            for (int j=0; j<nums[0].size(); ++j) {
                Q.push(nums[i][j]);
            }
        }
        
        for (int i=0; i<r; ++i) {
            for (int j=0; j<c; ++j) {
                res[i][j] = Q.front();
                Q.pop();
            }
        }
        
        return res;
    }
};