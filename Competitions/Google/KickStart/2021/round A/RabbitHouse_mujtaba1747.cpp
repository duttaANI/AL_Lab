// Seek Knowledge from the Cradle to the Grave

// Author : Syed Mujtaba

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
#define int             long long
#define ld              long double
#define ll              long long
#define pb              push_back
#define fi              first
#define se              second
#define mt              make_tuple
#define endl            '\n'
#define test            int _o_; cin>>_o_; while(_o_--)
#define fast_io         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define tree            tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 200064;
const ld  eps  = 1e-6;
const int mod  = 998244353;//1000000007; //998244353// 1e9 + 7
const int inf  = 1000000007; // 1e9 + 7
const int MAX  = 8000000000000000064LL;
const int MIN  = -8000000000000000064LL;

// int fact[1000007]={0};
// int spf[(int)(1e7) + 20];
// bool prime[(int)((1e7) + 20)];
// int gcd(int a,int b){if(b==0)return a; return gcd(b,a%b);}
// int lcm(vector < int > &a) { /*Be careful LCM mayOverflow, use prime analysis in that case*/int ret = a[0], sz = a.size();for (int i = 1; i < sz; i++) {ret = (ret * a[i]) / (__gcd(a[i], ret));}return ret;}
// void sp(int n){spf[1]=1;for(int i=2;i<n;i++)spf[i]=i;for(int i=4;i<n;i+=2)spf[i]=2;for(int i=3;i*i<n;i++){if(spf[i]==i){for(int j=i*i;j<n;j+=i)if(spf[j]==j)spf[j]=i;}}}
// void sieve(int n){memset(prime,true,sizeof(prime) );for(int p=2;p*p<=n;p++){if(prime[p]==true)for(int i=p*p;i<=n;i+=p)prime[i]=false;}prime[0]=false;prime[1]=false;}
int xyp(int x,int y){int res=1;while(y>0){if(y%2==1) res=(res*x)%mod;x=(x*x)%mod;y/=2;}return res%mod;}
int inv(int x){return xyp(x,mod - 2);}
int inv_euclid(int a, int m = mod){int m0 = m;int y = 0, x = 1;if (m == 1)return 0;while (a > 1){int q = a / m;int t = m;m = a % m, a = t;t = y;y = x - q * y;x = t;}if (x < 0)x += m0;return x;}
// void init() {fact[0]=1;fact[1]=1;for(int i=2;i<1000007;i++)fact[i]=(fact[i-1]*i)%mod;}
// int ncr(int n,int r) {int res=1; res=fact[n]; res=(res*(xyp(fact[r],mod-2)))%mod; res=(res*(xyp(fact[n-r],mod-2)))%mod; return res;}
// int npr(int n,int r) {int res=1; res=fact[n]; res=(res*(xyp(fact[n-r],mod-2)))%mod; return res; }
bool isp(int a){if(a == 2)return true;if(a == 1)return false;for(int x= 2; x <= sqrt(a) + 1; x++)if(a % x == 0)return false;return true;}
int add(int a, int b){return (a%mod + b%mod + ((MAX)/mod)*mod)%mod;}
int sub(int a, int b){return (a%mod - b%mod + ((MAX)/mod)*mod)%mod;}
int mul(int a, int b){return ((a%mod)*(b%mod) + ((MAX)/mod)*mod)%mod;}
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// #define p_set tree< pair<int,int> ,  null_type ,  less<pair<int,int>> ,  rb_tree_tag ,  tree_order_statistics_node_update>
// #define i_set tree< int ,  null_type ,  less< int > ,  rb_tree_tag ,  tree_order_statistics_node_update>
// freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};
int leq(vector<int> &va, int x){return upper_bound(va.begin(), va.end(), x) - va.begin();}
signed main()
{
    fast_io
    #ifndef ONLINE_JUDGE 
    // freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
   	int TC;
   	cin >> TC;
   	int X, Y;
   	for (int TT = 1; TT <= TC; TT++) {
   		int r, c;
   		cin >> r >> c;
   		int a[r + 4][c + 4];
   		memset(a, 0, sizeof(a));
   		int ans = 0;
   		map < int, set < pair < int, int > > > mp;
   		for (int i = 1; i <= r; i++) {
   			for (int j = 1; j <= c; j++) {
   				cin >> a[i][j];
   				if (a[i][j] != 0)
   					mp[a[i][j]].insert({i, j});
   			}
   		}
   		while (!mp.empty()) {
   			int k = (--mp.end()) -> fi;
   			if (k == 1) break;
   			set < pair < int, int > > vis;
   			for (auto z : mp[k]) {
   				int x = z.fi;
   				int y = z.se;
   				for (int i = 0; i < 4; i++) {
   					X = x + dx[i];
   					Y = y + dy[i];
   					if (X <= r && X >= 1 && Y >= 1 && Y <= c) {
   						if (a[X][Y] < (a[x][y] - 1) && !vis.count({X, Y})) {
   							vis.insert({X, Y});
   							ans += (a[x][y] - 1 - a[X][Y]);
   							mp[a[X][Y]].erase({X, Y});
   							a[X][Y] = a[x][y] - 1;
   							mp[a[X][Y]].insert({X, Y});
   						}
   					}
   				}
   			}
   			mp.erase(k);
   		}


   		cout << "Case #" << TT << ": ";
   		cout << ans << endl;
   	}
}
