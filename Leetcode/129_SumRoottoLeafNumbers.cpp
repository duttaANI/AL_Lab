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
    
    int inorder(TreeNode* node, int prev) {
        
        if(node) {
            int num;
            num = prev*10 +  node->val;
            if (!node->left && !node->right) {return num;}
            return inorder(node->left, num) + inorder(node->right, num);
        }
        return 0;
        
    }
    
    int sumNumbers(TreeNode* root) {
        
        return inorder(root, 0);
    }
};