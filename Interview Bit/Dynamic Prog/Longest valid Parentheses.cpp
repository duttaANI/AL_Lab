int Solution::longestValidParentheses(string s) {
    int n = s.size();
    vector<int> dp(n,0); //Lets construct dp[i] where dp[i] denotes the longest set of parenthesis ending at index i.
    for(int i=0; i<n; ++i){
        if(s[i]=='('){
            dp[i] = 0;
        }
        else if(s[i]==')'){
            if( s[i-1]=='('){
                dp[i] = dp[i-2]+2;
            }else if( s[i-1]==')' && s[i-1-dp[i-1]] == '(' ){
                dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];
            }
        }
    }
    
    int ans=0;
    for(int i=0;i<n;++i){
        ans = max({ans,dp[i]});
    }
    return ans;
}
