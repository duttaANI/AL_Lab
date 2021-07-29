#define ar array

int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if(n<2) return 0;
    vector<int> dp(n,0); // smallerOnLeft
    // vector<int> idx(n,0);
    int MIN = A[0];
    dp[0] = MIN;
    for(int i=1;i<n;++i){
        if( MIN > A[i]  ){
            MIN = A[i];
            // idx[i] = i;
        }
        dp[i] = MIN;
    }
    
    int ans = 0;
    for(int i=1;i<n;++i){
        if( A[i]-dp[i] > ans ){
            ans = A[i]-dp[i];
        }
    }
    return ans;
}