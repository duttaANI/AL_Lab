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
    
    bool inorder (TreeNode* node, TreeNode* node2) {
        if (node && node2) {
            if(node->val == node2->val)
            {
                return inorder(node->left,node2->left) && inorder(node->right,node2->right);
            }
            return false;
        }
        else if( (node && !node2) || (!node && node2)  ) return false;
        else
            return true;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return inorder(p,q);
    }
};