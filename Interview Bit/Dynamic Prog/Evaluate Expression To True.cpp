int dp[151][151][2];
int helper(string s,int i,int j,bool isTrue)
{
    if(i>j)
    {
        return dp[i][j][isTrue]=0;
    }
    if(i==j)
    {
        if(isTrue)
        {
            return dp[i][j][isTrue]=(s[i]=='T'?1:0);
        }
        else
        {
            return dp[i][j][isTrue]=(s[i]=='F'?1:0);
        }
    }
    if(dp[i][j][isTrue]!=-1)
    {
        return dp[i][j][isTrue];
    }
    int ans=0;
    for(int k=i+1;k<j;k+=2)
    {
        if(dp[i][k-1][1]==-1)
        {
            dp[i][k-1][1]=helper(s,i,k-1,true);
        }
        if(dp[i][k-1][0]==-1)
        {
            dp[i][k-1][0]=helper(s,i,k-1,false);
        }
        if(dp[k+1][j][1]==-1)
        {
            dp[k+1][j][1]=helper(s,k+1,j,true);
        }
        if(dp[k+1][j][0]==-1)
        {
            dp[k+1][j][0]=helper(s,k+1,j,false);
        }
        int lt=dp[i][k-1][1];
        int lf=dp[i][k-1][0];
        int rt=dp[k+1][j][1];
        int rf=dp[k+1][j][0];
        if(s[k]=='&')
        {
            ans=(ans+(isTrue?(rt*lt):(lt*rf+lf*rt+lf*rf)))%1003;
        }
        if(s[k]=='|')
        {
            ans=(ans+(isTrue?(lt*rf+lf*rt+lt*rt):lf*rf))%1003;
        }
        if(s[k]=='^')
        {
            ans=(ans+(isTrue?(lt*rf+lf*rt):(lt*rt+lf*rf)))%1003;
        }
    }
    return ans%1003;
}
int Solution::cnttrue(string A) 
{
    memset(dp,-1,sizeof(dp));
    return helper(A,0,A.length()-1,true);
}

// const int mod = 1e3 + 3;

// int solve(string s, int i,int j, bool is_true,unordered_map<string,int>& mp){
    
//     if(i>j ) return 0;
//     if(i==j) {
//         if(is_true){
//             return (s[i] == 'T');
//         }
//         else{
//             return (s[i] == 'F');
//         }
//     }
    
//     string temp=to_string(i)+" "+to_string(j)+" "+to_string(is_true);
//     if(mp.find(temp)!=mp.end()){
//         // cout << "hi\n";
//         return mp[temp];
//     }
//     cout <<  mp[temp] << endl;
    
//     int ans = 0;
//     for(int k = i+1 ; k<=j+1; k=k+2){
//         int lT = solve(s,i,k-1,true,mp);
//         int lF = solve(s,i,k-1,false,mp);
//         int rT = solve(s,k+1,j,true,mp);
//         int rF = solve(s,k+1,j,false,mp);
        
//         if(s[k]=='&'){
//             if(is_true){
//                 ans = (ans + lT*rT)%mod;
//             }else{
//                 ans = (ans + lF*rT + lT*rF + lF*rF)%mod; 
//             }
//         }
//         else if(s[k]=='|'){
//             if(is_true){
//                 ans = (ans + lT*rT + lF*rT + lT*rF)%mod;
//             }else{
//                 ans = (ans + lF*rF)%mod;
//             }
//         }
//         else if(s[k]=='^'){
//             if(is_true){
//                 ans = (ans + lF*rT + lT*rF)%mod;
//             }else{
//                 ans = (ans + lF*rF + lT*rT)%mod;
//             }
//         }
//     }
//     mp[temp] = ans;
//     return mp[temp]%mod;
// }

// int Solution::cnttrue(string A) {
//     int i =0;
//     int j = A.size()-1;
//     unordered_map<string,int> mp;
//     // mp.clear();
    
//     return solve(A,i,j,true,mp);
// }







































const int mod = 1e3 + 3;

int solve(string s, int i,int j, bool is_true){
    if(i>j) return 1;
    if(i==j) {
        if(is_true){
            return s[i] == 'T';
        }
        else{
            return s[i] == 'F';
        }
    }
    
    int ans = 0;
    for(int k = i+1 ; k<=j+1; k+=2){
        int lT = solve(s,i,k-1,true);
        int lF = solve(s,i,k-1,false);
        int rT = solve(s,k+1,j,true);
        int rF = solve(s,k+1,j,false);
        
        if(s[k]=='&'){
            if(is_true){
                ans = (ans + lT*rT)%mod;
            }else{
                ans = (ans + lF*rT + lT*rF + lF*rF)%mod; 
            }
        }
        else if(s[k]=='|'){
            if(is_true){
                ans = (ans + lT*rT + lF*rT + lT*rF)%mod;
            }else{
                ans = (ans + lF*rF)%mod;
            }
        }
        else if(s[k]=='^'){
            if(is_true){
                ans = (ans + lF*rT + lT*rF)%mod;
            }else{
                ans = (ans + lF*rF + lT*rT)%mod;
            }
        }
    }
    
    return ans;
}

int Solution::cnttrue(string A) {
    int i =0;
    int j = A.size()-1;
    return solve(A,i,j,true);
}
