/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* root ) {
    if (root == NULL) return NULL;
    queue<TreeNode*> q ;
    q.push(root);
    while(!q.empty()){
        TreeNode* cur = q.front(); q.pop();
        TreeNode * temp = cur->left;
        cur->left = cur->right;
        cur->right = temp;
        if(cur->left!=NULL) q.push(cur->left);
        if(cur->right!=NULL)q.push(cur->right);
    }
    return root;
}
