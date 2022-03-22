/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int maxPathAndGlobalUpdate(TreeNode *root, int &global_max) {
    if (root == NULL) return 0;
    int l = max(0, maxPathAndGlobalUpdate(root->left, global_max));
    int r = max(0, maxPathAndGlobalUpdate(root->right, global_max));
    global_max = max(global_max, l + r + root->val);
    return root->val + max(l, r);
}
int Solution::maxPathSum(TreeNode* A) {
    int maxAns = INT_MIN;
    maxPathAndGlobalUpdate(A, maxAns);
    return maxAns;
}
