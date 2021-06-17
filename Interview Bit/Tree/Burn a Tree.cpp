/*

Definition for binary tree*/

// struct TreeNode {

// int val;

// TreeNode *left;

// TreeNode *right;

// TreeNode(int x) : val(x), left(NULL), right(NULL) {}

// };

map <TreeNode*, vector<TreeNode*> > adj;
TreeNode * beg;

void filladj(TreeNode* A, int B){
    if(A->val == B) beg = A;
    if(A->left!=NULL){
        adj[A].push_back(A->left);
        adj[A->left].push_back(A);
        filladj(A->left, B);
    }
    if(A->right!=NULL){
        adj[A].push_back(A->right);
        adj[A->right].push_back(A);
        filladj(A->right, B);
    }
    return ;
}

int Solution::solve(TreeNode* A, int B) {
    adj.clear();
    filladj(A,B);
    queue <TreeNode* > q;
    q.push(beg);
    
    int ans = 0;
    set<TreeNode *> vis;
    vis.insert(beg);
    // bfs
    while(!q.empty()){
    
        int s = q.size();
        while(s--)
        {
            TreeNode* x = q.front();
            q.pop();
            for(TreeNode* v: adj[x]){
                if(!vis.count(v)){
                    q.push(v);
                    vis.insert(v);
                }
            }
        }
        ++ans;
    }
    
    return ans-1;
}
