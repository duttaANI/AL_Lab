#include <bits/stdc++.h>
#define ar array

//f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions

int Solution::maxProfit(const vector<int> &A) {
    int buy1=INT_MAX, buy2=INT_MAX,sell1=0,sell2=0;
    int n = A.size();
    for(int i=0; i<n;++i){
        buy1 = min({buy1,A[i]});
        sell1 = max({sell1, A[i]-buy1});
        buy2 = min({ buy2,A[i]-sell1 });
        sell2 = max({ sell2, A[i]-buy2 });
    }
    return sell2;
}
