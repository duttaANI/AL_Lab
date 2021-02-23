

class Solution {
public:
    
    int Memo(int l,int r,int a, int b, vector<int>& cuts, vector<vector<int>>& dp){
        if(l<0||l>r||r>=cuts.size()){
            return 0;
        }
        if(l==r){
            return b-a;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int ans=INT_MAX;
        for(int i=l; i<=r; ++i){
            ans = min({ans, b-a + Memo(l,i-1,a,cuts[i],cuts,dp) + Memo(i+1,r,cuts[i],b,cuts,dp) });
        }
        dp[l][r]=ans;
        return dp[l][r];
    }
    
    int minCost(int A, vector<int>& cuts) {
        int n = cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp (n, vector<int>(n,-1));
        int l =0;
        int r =n-1,ans;
        ans=Memo(l,r,0,A,cuts,dp);
        return ans;
    }
};