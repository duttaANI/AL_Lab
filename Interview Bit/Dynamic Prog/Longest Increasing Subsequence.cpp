#include <bits/stdc++.h>

const int mxN = 3e3;

int dp[mxN];

int Solution::lis(const vector<int> &A) {
    int n = A.size(),maxans=1;
    dp[0] = 1;
    for(int i=0; i<n ;++i){
        int maxval = 0;
        for(int j=0 ;j<i; ++j){
            if( A[i] > A[j] ){
                maxval = max({maxval,dp[j]});
            }
            dp[i] = maxval + 1;
            maxans = max({maxans,dp[i]});
        }
    }
    return maxans;
}
