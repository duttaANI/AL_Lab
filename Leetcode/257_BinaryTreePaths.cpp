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
    
    void insertPaths(TreeNode* node, string str, vector<string>& res) {
        
        if (!node) return;  // base-case
        
        str += to_string(node->val);
        if(!node->left && !node->right) {
            res.push_back(str);
        }
        
        insertPaths(node->left,str +"->",res);
        insertPaths(node->right,str +"->",res);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> res;
        insertPaths(root,"",res);
        return res;
    }
};