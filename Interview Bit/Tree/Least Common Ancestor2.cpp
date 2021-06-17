int b,c,ans,ans2;

void dfs(TreeNode* T){
    if(T==NULL){
        return ;
    }
    if(T->val == b){
        ans2 = b;
    }
    dfs(T->left);
    dfs(T->right);
}
 
bool solve(TreeNode* T){

    if(T==NULL){
        return false;
    }
    
    bool me = false;

    if( T->val == b || T->val == c ){
        me = true;
    }
    
    bool l = solve(T->left);
    bool r = solve(T->right);

    if( (l && r) || (me&&l) || (me&&r) ){
        ans = T->val;
    }

    return l || r || me;
} 

int Solution::lca(TreeNode* A, int B, int C) {
    b=B; c=C;
    ans=-1;
    solve(A);
    if(B==C){
        ans2 = -1;
        dfs(A);
        return ans2;
    }
    return ans;
}
