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
    
    int height (TreeNode* node) {
        if(node) {
            return max(height(node->left) , height(node->right)) +1;
        }
        return 0;
    }
    
    int bal_fac(TreeNode* node) {
        if(node) {
            return height(node->left) - height(node->right);
        }
        return 0;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return abs(bal_fac(root)) < 2 && isBalanced(root->left) && isBalanced(root->right);
        
    }
};