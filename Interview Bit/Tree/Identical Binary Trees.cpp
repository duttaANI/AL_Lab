/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool solve(TreeNode* A, TreeNode* B){
    if(A==NULL && B==NULL){
        return true;
    }
    else if ( ( A!=NULL && B==NULL ) || (B!=NULL && A==NULL)  ){
        return false;
    }
    
    if( A->val==B->val && solve(A->left,B->left) && solve(A->right,B->right) ){
        return true;
    }
    return false;
}
 
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    return solve(A,B);
}
