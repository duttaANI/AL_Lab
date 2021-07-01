vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> ans (n,0);
    int l = 0 , r = n-1 , k = n-1;
    while(l<=r){
        if( A[l]*A[l] > A[r]*A[r] ){
            ans[k] = A[l]*A[l];
            ++l;
        }
        else{
            ans[k] = A[r]*A[r];
            --r;
        }
        --k;
    }
    return ans;
}