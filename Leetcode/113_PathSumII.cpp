/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void dfs(vector<vector<int>>& ans, TreeNode* node, int sum, int cur_sum, vector<int>& temp ) {
        
        if (node) {
            temp.push_back(node->val);
            cur_sum += node->val;
                
            dfs(ans, node->left , sum, cur_sum, temp);
            dfs(ans, node->right, sum, cur_sum, temp);
                
            if (!node->left && !node->right && cur_sum==sum )
                ans.push_back(temp);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs (ans, root, sum, 0, temp);
        
        return ans;
    }
};