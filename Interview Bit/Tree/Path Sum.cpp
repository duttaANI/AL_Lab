/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int cur = 0; 
int ans = 0;

void order(TreeNode* n, int B){
    cur += n->val;
    int gl=0,gr=0;
    if( n->left ){
        gl=1;
        order(n->left,B);
    } 
    if( n->right ){
        gr=1;
        order(n->right,B);
    }
    if( !gl && !gr && cur==B ){
        ans = 1;
        return ;
    }
    
    cur -= n->val;
}
 
int Solution::hasPathSum(TreeNode* A, int B) {
    ans = 0;
    cur = 0;
    if( A==NULL ) return 0;
    
    order(A,B);
    
    
    return ans;
}
