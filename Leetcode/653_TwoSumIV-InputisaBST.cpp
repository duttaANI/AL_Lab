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
    set<int> s;
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return 0;
        if(s.find(root->val)!=s.end())
        { 
            return 1;
        }
        else
            s.insert(k-root->val);
        
        return findTarget(root->left,k) || findTarget(root->right,k);
    }
};
