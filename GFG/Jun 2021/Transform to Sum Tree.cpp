class Solution {
  public:
  
    int convertToSumTree(Node* root)
    {
        // base case: empty tree
        if (root == nullptr) {
            return 0;
        }
     
        // recursively convert the left and right subtree first before
        // processing the root node
        int left = convertToSumTree(root->left);
        int right = convertToSumTree(root->right);
     
        // stores the current value of the root node
        int old = root->data;
     
        // update root to the sum of left and right subtree
        root->data = left + right;
     
        // return the updated value + the old value (sum of the tree rooted at
        // the root node)
        return root->data + old;
    }
      
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        // Your code here
        convertToSumTree(node);
    }
};