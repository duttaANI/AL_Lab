int Solution::maxSubArray(const vector<int> &A) {
    int cur= A[0] , max_s = A[0];
    int n = A.size();
    for(int i=1;i<n;++i){
        cur = max({ cur+A[i], A[i] });
        if( cur>max_s ){
            max_s = cur;
        }
    }
    return max_s;
}