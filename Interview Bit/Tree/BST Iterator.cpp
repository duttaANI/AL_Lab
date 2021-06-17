/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
stack<TreeNode*> s;
BSTIterator::BSTIterator(TreeNode *root) {
    TreeNode* node = root;
    while(node){
        s.push(node);
        node = node->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return (s.size()>0);
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* t = s.top();
    s.pop();

    TreeNode* cur = t->right;
    while(cur){
        s.push(cur);
        cur = cur->left;
    }

    return t->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
