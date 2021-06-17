/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
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

vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;
    preorder(A,ans,0);
    return ans;
}
