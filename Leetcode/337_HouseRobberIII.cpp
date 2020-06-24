// Dynamic Prog
// link : https://leetcode.com/problems/house-robber-iii/discuss/79330/Step-by-step-tackling-of-the-problem
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
    
    int rob(TreeNode* root) {
        
        unordered_map<TreeNode* , int> dp;
        return robSub (root, dp);
    }
    
     int robSub(TreeNode* root,unordered_map<TreeNode* , int> & dp){ // robSub gives optimal soln for subtree
         if (root == NULL ) return 0;
         if ( dp.find(root) != dp.end() ) return dp.find(root)->second ;
         
         int val = 0;
         
         if(root->left) {
             val += robSub(root->left->left, dp) + robSub(root->left->right, dp); // grandChild
         }
         if(root->right) {
             val += robSub(root->right->left, dp) + robSub(root->right->right, dp); // grandChild
         }
         
         val = max(val + root->val, robSub(root->left, dp) + robSub(root->right, dp)); 
         
         dp.insert({root,val});
         
         return val;
     }
};




































