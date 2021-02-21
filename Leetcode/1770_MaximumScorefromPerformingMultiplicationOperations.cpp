class Solution {
public:
    #define r (n - (i-l) - 1)
    int dp[1001][1001];
    int n;
    
    int Recur(vector<int>& nums, vector<int>& mul, int l, int i){
        if( i==mul.size() ){
            return 0;
        }
        
        if(dp[l][i]!=-1){
            return dp[l][i];
        }
        
        int op1 = mul[i]*nums[l] + Recur(nums,mul, l+1,i+1);
        int op2 = mul[i]*nums[r] + Recur(nums,mul, l  ,i+1);
        dp[l][i] = max({op1,op2});
        return dp[l][i];
    }
    
    int maximumScore(vector<int>& nums, vector<int>& mul ) {
        n=0;
        int l =0;
        n =nums.size();
        int i=0;
        memset(dp,-1,sizeof(dp));
        return Recur(nums,mul,l,i);
    }
};