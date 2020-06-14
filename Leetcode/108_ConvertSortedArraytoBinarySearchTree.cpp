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
    
    TreeNode* constTreeFromArr( vector<int>& nums, int left , int right ) {
        if (left > right) return NULL;
        int mid = left + (right-left)/2;
        
        TreeNode* node = new TreeNode (nums[mid]);
        
        node->left = constTreeFromArr(nums, left, mid -1);
        node->right = constTreeFromArr(nums, mid+1, right);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        
        return constTreeFromArr(nums, 0, nums.size()-1);
    }
};