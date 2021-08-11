class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int m=days[n-1];
        vector<int>dp(m+1);
        dp[0]=0;
        unordered_set<int>s;
        for(int i=0;i<n;i++)
            s.insert(days[i]);
        for(int i=1;i<=m;i++){
            int c1=dp[i-1];
            int c2=(i-7)>0?dp[i-7]:0;
            int c3=(i-30)>0?dp[i-30]:0;
            if(s.find(i)!=s.end())
                dp[i]=min(c1+costs[0],min(c2+costs[1],c3+costs[2]));
            else
                dp[i]=dp[i-1];
        }
        return dp[m];
    }
};