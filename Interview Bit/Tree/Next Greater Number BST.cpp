/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* FindMin(TreeNode *root){
    if(root == NULL) return NULL;
    while(root->left != NULL) root = root->left;
    return root;
}

TreeNode* Find(TreeNode *root, int B){
    while(root != NULL){
        if(root->val == B) return root;
        if(B > root->val) root = root->right;
        else root = root->left;
    }
    return NULL;
}

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // if node has right subtree, go deep leftmost of right subT (min of right subT)
    // when no right subtree -> go to nearest ancestor for which gn node is in left subT
    
    TreeNode *curr = Find(A, B); // first find the node in question
    if(curr == NULL) return NULL;
    // if currnode has right subtree
    if(curr->right != NULL) return FindMin(curr->right);
    // if no right subtree
    else {
        TreeNode *successor = NULL;
        TreeNode *ancestor = A;
        while(ancestor != curr){
            if(curr->val < ancestor->val){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else ancestor = ancestor->right;
        }
        return successor;
        
    }
    
    
    
}
