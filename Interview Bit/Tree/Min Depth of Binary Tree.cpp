/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// My
 
bool isLeaf(TreeNode* node){
    if(node->left==NULL && node->right==NULL){
        return 1;
    }
    return 0;
}
void preorder(TreeNode* node, int & ans, int level) {
    if(node) {
        if(level<ans && isLeaf(node) )
            ans = level;
        ++level;
        preorder(node->right, ans, level);
        preorder(node->left , ans, level);
        --level;
    }
}
    
int Solution::minDepth(TreeNode* A) {
    int level = 0,ans=INT_MAX;
    preorder(A,ans,level);
    return ans+1;
}

// Editorial


int Solution::minDepth(TreeNode* A) {
    if(A==NULL)
        return 0;
    if(A->left == NULL and A->right == NULL)
        return 1;
        
    if(A->left==NULL)
        return 1 + minDepth(A->right);
     
    if(A->right==NULL)
        return 1 + minDepth(A->left);  
    return 1 + min(minDepth(A->left),minDepth(A->right));
}
