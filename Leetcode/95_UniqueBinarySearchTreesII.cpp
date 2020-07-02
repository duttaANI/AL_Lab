/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<TreeNode*> genTrees (int start, int end) {
    if(start>end) return {NULL};
    if(start==end) return {new TreeNode(start)};
    
    vector<TreeNode*> trees;
    
    for (int i=start; i<=end; ++i) {
        vector<TreeNode*> leftTrees = genTrees (start,i-1 );
        auto rightTrees = genTrees (i+1 ,end );
        for (auto l : leftTrees) {
            for (auto& r:rightTrees) {
                auto t = new TreeNode(i);
                t->left = l;
                t->right = r;
                trees.push_back(t);
            }
        }
    }
    return trees;
}

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return genTrees(1,n);
    }
};