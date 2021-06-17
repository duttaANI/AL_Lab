/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *res(const vector<int> &vec, int start, int end){
    if(start > end) return nullptr;
    if(start == end) return new TreeNode(vec[start]);
    int mid = start + (end-start)/2;
    TreeNode *node = new TreeNode(vec[mid]);
    node->left = res(vec, start, mid-1);
    node->right = res(vec, mid+1, end);
    return node;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return res(A, 0, A.size()-1);
}

