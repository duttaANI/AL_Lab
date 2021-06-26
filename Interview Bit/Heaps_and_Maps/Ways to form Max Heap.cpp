#define MAXN 105

long long int dp[MAXN];  	/* dp[i] = number of max heaps for i distinct integers */
long long int nck[MAXN][MAXN];	/* nck[i][j] = i choose j if i>=j else 0 */
int log_2[MAXN];			/* log_2[i] = int(log_2 base 2 of i) */
long long int MOD = 1000000007;

long long int choose(int n,int k)
{
        if(k>n)
            return 0;
	if(n<=1)
	    return 1;
	if(k==0)
	    return 1;

        if(nck[n][k]!=-1)
            return nck[n][k];
        long long int answer = choose(n-1,k-1) + choose(n-1,k);
        answer%=MOD;
        nck[n][k] = answer;
        return answer;
}
    
int getL(int n)
{
        if(n==1)
            return 0;
            
        int h = log_2[n];
        int p = n - ((1<<(h)) - 1);
        int m = (1<<h);
        if(p>=(m/2))
            return (1<<(h)) - 1;
        else
            return (1<<(h)) - 1 - ((m/2) - p);
}

long long int getNumberOfMaxHeaps(int n)
{
        if(n<=1)
            return 1;
            
        if(dp[n]!=-1)
            return dp[n];

        int L = getL(n);
        long long int ans = (choose(n-1,L)*getNumberOfMaxHeaps(L))%MOD*(getNumberOfMaxHeaps(n-1-L));
        ans%=MOD;
        dp[n] = ans;
        return ans;
}


int Solution::solve(int n) {
    
     for(int i=0;i<=n;i++)
            dp[i]=-1;
            
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                nck[i][j] = -1;
                
        int currlog_2Answer = -1;
        int currPower2 = 1;
        for(int i=1;i<=n;i++)
        {
	    if(currPower2==i)
            {
                currlog_2Answer++;
                currPower2*=2;
            }
            log_2[i] = currlog_2Answer;
        }
        
        return (int)getNumberOfMaxHeaps(n);
    
}

/*
Shameek's ans
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PB push_back
#define FI first
#define SE second
#define MP make_pair
#define ALL(cont) cont.begin(), cont.end()
#define mod 1000000007ll
#define SIZE 100100ll


ll power(ll a, ll b)
{
    a = a%mod;
    ll res = 1;
    while(b)
    {
        if(b&1)
            res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}

ll inverse(ll a)
{
    return power(a,mod-2);
}

ll fact[10000010];
ll ifact[10000010];

void factprecomp()
{
    fact[0] = 1;
    ifact[0] = 1;
    for(ll i=1;i<10000010;i++)
    {
        fact[i]=(i*fact[i-1])%mod;
        ifact[i]=(inverse(i)*ifact[i-1])%mod;
    }
}

ll ncr(ll n, ll r)
{
    if(r>n) return 0;
    ll val = fact[n];
    val = (val*ifact[n-r])%mod;
    val = (val*ifact[r])%mod;
    return val;
}

ll lefter(ll n)
{
    if(n<=1)    return 0;
    ll h = log2(n);
    ll sum = power(2,h)-1;
    ll extra = n-sum;
    ll a = power(2,h-1)-1;
    ll val = min(sum, a+extra);
    return val;
}

ll memo[10000010];

ll heaper(ll a)
{
    if(memo[a]!=-1)
        return memo[a];
    ll left = lefter(a);
    ll chose = ncr(a-1,left);
    ll val = (chose*(heaper(left)))%mod;
    val = (val*heaper(a-1-left))%mod;
    memo[a] = val;
    return val;
}

ll solve(ll a)
{
    if(a<=2)    return 1;

    factprecomp();
    
    for(ll i=0;i<10000010;i++)
        memo[i] = -1;
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;
    return heaper(a);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout<<solve(10000000)<<endl;


    return 0;


}

*/
