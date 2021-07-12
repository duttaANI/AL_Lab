TreeNode* solve(int l , int r, const vector<int> &A){
    if( l<=r ){
        int mid = l + (r-l)/2;
        TreeNode * T = new TreeNode(A[mid]);
        T -> left = solve(l,mid-1,A);
        T ->right = solve(mid+1,r,A);
        return T;
    }
    return NULL;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int n = A.size();
    if(n==0) return NULL;
    return solve(0,n-1,A);
}