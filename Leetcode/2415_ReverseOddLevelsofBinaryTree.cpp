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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q1;
        q1.push(root);
        int level = 0;
        while(q1.size() ){
            if(!(level%2)){
                int n = q1.size();
                vector<int> v;
                queue<TreeNode*> q2;
                for(int i=0;i<n;++i){
                    TreeNode* f = q1.front(); q1.pop();
                    q2.push(f);
                    if(f->left!=NULL){
                        q1.push(f->left);
                        v.push_back(f->left->val);
                    }
                    if(f->right!=NULL){
                        q1.push(f->right);
                        v.push_back(f->right->val);
                    }
                }
                reverse(v.begin(),v.end());
                
                for(int i=0;i<n;++i){
                    TreeNode* f = q2.front();q2.pop();
                    if(f->left)
                    f->left->val = v[2*i];
                    if(f->right)
                    f->right->val = v[2*i+1];
                }
                v.clear();
            }
            else{
                int n = q1.size();
                for(int i=0;i<n;++i){
                    TreeNode* f = q1.front(); q1.pop();
                    if(f->left!=NULL){
                        q1.push(f->left);
                    }
                    if(f->right!=NULL){
                        q1.push(f->right);
                    }
                }
            }
            ++level;
        }
        return root;
    }
};