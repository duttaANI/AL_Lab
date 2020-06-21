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
    
    void preorder(TreeNode* node, vector<int>& ans, int level) {
        if(node) {
            if(level>=ans.size())
            ans.push_back(node->val);
            ++level;
            preorder(node->right, ans, level);
            preorder(node->left , ans, level);
            --level;
        }
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        preorder(root, ans, 0);
        
        return ans;
    }
};