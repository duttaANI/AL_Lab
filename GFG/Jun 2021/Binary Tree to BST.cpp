class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void inorder(Node *root, vector<int> &v){
        if(!root)
        return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    
    void rearrange(Node *root, vector<int> &v){
        if(!root)
        return;
        rearrange(root->left, v);
        root->data = v.back();
        v.pop_back();
        rearrange(root->right, v);
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> v;
        inorder(root, v);
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        rearrange(root, v);
        return root;
    }
};