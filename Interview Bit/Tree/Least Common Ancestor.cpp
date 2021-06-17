//My

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















/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans=-1;
bool recur(TreeNode* A, int B, int C){
    bool flag = false;
    if(A==NULL){
        return false;
    }
    else if( A->val == B && A->val==C ){
        ans = B;
        return true;
    }
    else if( A->val == B || A->val==C ){
        flag =  true;
    }
    
    bool l = recur(A->left,B,C);
    bool r = recur(A->right,B,C);
    
    // cout << l << " <-l r-> " << r << " Aval : " << A->val << endl;
    
    if( l + r + flag >=2 ){
        ans = A->val;
    }
   
    
   
    return  (l || r || flag);
}
 
int Solution::lca(TreeNode* A, int B, int C) {
    ans = -1;
    recur(A,B,C);
    return ans;
}
