const int mod = 1000007;
#define ll long long
int Solution::coinchange2(vector<int> &coins, int amount) {
    ll dp[amount+1];
    
        for(int i=0;i<=amount;i+=1){
            dp[i]=0;
        }
        dp[0]=1;
        
        for(auto coin : coins){
            for(int i=coin;i<=amount;i+=1){
                dp[i]= (dp[i]+ dp[i-coin])%mod;
            }
        }
        
        return dp[amount]%mod;
}
