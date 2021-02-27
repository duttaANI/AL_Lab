
const int M = 1e9 + 7;
int Solution::numDecodings(string A) {
    int N=A.length();
    int dp[N+1];
    for(int i=0; i<=N; i++){
        dp[i]=0;
    }
    dp[0] = 1;
    dp[1] = A[0]=='0' ? 0 : 1;
    for(int i=2; i<=N; i++){
        int oneDigit=stoi(A.substr(i-1,1));
        int twoDigit=stoi(A.substr(i-2,2));
        if(oneDigit>=1){
            dp[i] = (dp[i] + dp[i-1])%M;
        }
        if(twoDigit>=10 && twoDigit<=26){
            dp[i] = (dp[i] + dp[i-2])%M;
        }
    }
    return dp[N];
}
