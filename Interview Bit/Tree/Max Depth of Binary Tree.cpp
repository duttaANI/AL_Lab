/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void preorder(TreeNode* node, int & ans, int level) {
    if(node) {
        if(level>ans )
        ans = level;
        ++level;
        preorder(node->right, ans, level);
        preorder(node->left , ans, level);
        --level;
    }
}
    
int Solution::maxDepth(TreeNode* A) {
    int level = 0,ans=0;
    preorder(A,ans,level);
    return ans+1;
}
