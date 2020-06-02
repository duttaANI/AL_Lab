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
    
    int minDepth(TreeNode* root) {
        int res = 0;
        queue<TreeNode *> myQueue;
        if (root)
            myQueue.push(root);
        while (!myQueue.empty()) {
            int l = myQueue.size();
            res++;
            for (int i = 0; i < l; i++) {
                TreeNode *tmp = myQueue.front();
                if (!(tmp->left) && !(tmp->right))
                    return res;
                if (tmp->left)
                    myQueue.push(tmp->left);
                if (tmp->right)
                    myQueue.push(tmp->right);
                myQueue.pop();
            }
        }
        return res;
    }
};