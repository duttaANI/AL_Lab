/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 TreeNode* dfs(TreeNode* A, TreeNode* B){
    if(A==NULL&&B==NULL) return NULL;
    if(A!=NULL && B==NULL) return A;
    if(A==NULL && B!=NULL) return B;
    TreeNode * C = new TreeNode(A->val+B->val);
    
    C->left = dfs(A->left,B->left);
    C->right = dfs(A->right,B->right);
    
    return C;
 }
 
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    if(A==NULL&&B==NULL) return NULL;
    if(A!=NULL && B==NULL) return A;
    if(A==NULL && B!=NULL) return B;
    
    return dfs(A,B);
}
