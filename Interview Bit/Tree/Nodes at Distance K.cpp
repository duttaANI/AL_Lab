map<TreeNode*, TreeNode*> parent;
TreeNode* target;
vector<int> ans;
void dfs(TreeNode* root, int B){
    if(root->val==B){
        target = root;
    }
    if(root->left!=NULL){
        parent[root->left] = root;
        dfs(root->left, B);
    }
    if(root->right!=NULL){
        parent[root->right] = root;
        dfs(root->right, B);
    }
}

void bfs(int C){
    
    map<TreeNode*, int> depth;
    queue<TreeNode*> q;
    q.push(target);
    depth[target] = 0;
    
    while(!q.empty()){
        TreeNode* cur = q.front();
        q.pop();
        
        if(parent.find(cur)!=parent.end()){
            TreeNode* t = parent[cur];
            if(depth.find(t)==depth.end() || depth[t]>1+depth[cur]){
                depth[t] = 1+depth[cur];
                if(depth[t]==C){
                    ans.push_back(t->val);
                }
                q.push(t);
            }
        }
        
        if(cur->left!=NULL){
            TreeNode* t = cur->left;
            if(depth.find(t)==depth.end() || depth[t]>1+depth[cur]){
                depth[t] = 1+depth[cur];
                if(depth[t]==C){
                    ans.push_back(t->val);
                }
                q.push(t);
            }
        }
        
        if(cur->right!=NULL){
            TreeNode* t = cur->right;
            if(depth.find(t)==depth.end() || depth[t]>1+depth[cur]){
                depth[t] = 1+depth[cur];
                if(depth[t]==C){
                    ans.push_back(t->val);
                }
                q.push(t);
            }
        }
    }
}

vector<int> Solution::distanceK(TreeNode* A, int B, int C) {
    parent.clear();
    ans.clear();
    dfs(A, B);
    bfs(C);
    return ans;
}