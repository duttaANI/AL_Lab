/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    vector<vector<int> > res;
    
    queue<TreeNode*> curQ;
    vector<int> q;
    q.push_back(A->val);
    curQ.push(A);
    
    while(q.size()){
        int k = q.size();
        res.push_back(q);
        q.clear();
        while(k--){
            TreeNode * frnt = curQ.front(); curQ.pop();
            
            if(frnt->left){
                curQ.push(frnt->left);
                q.push_back(frnt->left->val);
            }
            if(frnt->right){
                curQ.push(frnt->right);
                q.push_back(frnt->right->val);
            }  
        }
        
    }
    vector<int> ans;
    for(int i=res.size()-1; i>=0; --i){
        for(int j=0 ; j<res[i].size(); ++j){
             ans.push_back(res[i][j]);
        }
    }
    return ans;
}
