// link : https://leetcode.com/problems/ugly-number-ii/discuss/69364/My-16ms-C%2B%2B-DP-solution-with-short-explanation

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=0) return false;
        if(n==1) return 1;
        int p2=0, p3=0, p5=0;
        vector<int> dp(n);
        dp[0]=1;
        for( int i=1; i<n; ++i ){  // dp[i] is current ugly number
            dp[i] = min( {dp[p2]*2, dp[p3]*3, dp[p5]*5 });
            if(dp[i] == dp[p2]*2) p2++; 
            if(dp[i] == dp[p3]*3) p3++;
            if(dp[i] == dp[p5]*5) p5++;
        }
        return dp[n-1];
    }
};
