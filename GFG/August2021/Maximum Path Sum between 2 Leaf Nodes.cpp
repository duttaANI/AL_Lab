class Solution {
public:

    int maxPathSumUtil(struct Node *root, int &res)
    {
        // Base cases
        if (root==NULL) return 0;
        if (!root->left && !root->right) return root->data;
     
        // Find maximum sum in left and right subtree. Also
        // find maximum root to leaf sums in left and right
        // subtrees and store them in ls and rs
        int ls = maxPathSumUtil(root->left, res);
        int rs = maxPathSumUtil(root->right, res);
     
     
        // If both left and right children exist
        if (root->left && root->right)
        {
            // Update result if needed
            res = max(res, ls + rs + root->data);
     
            // Return maximum possible value for root being
            // on one side
            return max(ls, rs) + root->data;
        }
     
        // If any of the two children is empty, return
        // root sum for root being on one side
        return (!root->left)? rs + root->data:ls + root->data;
    }


    int maxPathSum(Node* root)
    {
        // code here
        int res = INT_MIN;
   
        int val = maxPathSumUtil(root, res);

   
        if(res == INT_MIN)
        {
          return val;
        }
   
        return res;
    }
};