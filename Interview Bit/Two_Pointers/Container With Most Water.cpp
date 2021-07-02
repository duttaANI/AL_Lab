int Solution::maxArea(vector<int> &A) {
    int l= 0, r = A.size()-1;
    int ans = 0;
    while(l<r){
        ans = max({ans,(r-l)*min({A[l],A[r]})});
        if(A[l]<A[r]){
            ++l;
        }
        else{
            --r;
        }
    }
    return ans;
}