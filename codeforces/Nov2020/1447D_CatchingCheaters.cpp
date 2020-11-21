#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 5e3+1;

int dp[mxN][mxN],ans=0; // max similarity score

int main(){
	int n,m;
	string A,B;
	cin >> n >> m;
	cin >> A >> B;
	for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(A[i-1]==B[j-1]) dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 2);
            
            dp[i][j] = max({dp[i][j],dp[i-1][j]-1,dp[i][j-1]-1});
            
            ans=max(ans,dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}