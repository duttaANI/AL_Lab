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
    
    bool isSame(TreeNode* a,TreeNode* b){
        if(  !a && !b ){
            return 1;
        }
        if(  (a&&!b) || (!a&&b)   ){
            return 0;
        }
        if(  a && b && a->val!=b->val ){
            return 0;
        }
        return (isSame(a->left,b->left)) && (isSame(a->right,b->right));
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(  !root && !subRoot ){
            return 1;
        }
        if(  (root&&!subRoot) || (!root&&subRoot)  ){
            return 0;
        }
        
        if(isSame(root,subRoot)){
            return 1;
        }
        
        if(  isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot)  ){
            return 1;
        }
        
        return 0;
    }
};