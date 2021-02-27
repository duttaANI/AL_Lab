#include <bits/stdc++.h>
#define ar array

int dp[1001]; // dp[i] represents the length of the longest increasing subsequence possible considering the array elements up to the ith index only ,by necessarily including the ith element

int Solution::solve(vector<vector<int> > &A) {
    dp[0] = 1;
    int n = A.size(),maxans=0;
    for(int i=0; i<n;++i){
        int maxval = 0;
        for(int j=0; j<i; ++j){
            if(A[i][0] > A[j][1]){
                maxval = max({maxval,dp[j]});
            }
        }
        dp[i] = maxval + 1;
        maxans = max(maxans,dp[i]);
    }
    
    return maxans;
}
