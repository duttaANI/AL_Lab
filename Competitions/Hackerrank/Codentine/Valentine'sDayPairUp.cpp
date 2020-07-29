// SPOJ : https://www.spoj.com/problems/DCOWS/
// refer https://github.com/AliOsm/CompetitiveProgramming/blob/master/SPOJ/DCOWS%20-%20Dancing%20Cows.cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

long long n, m;
long long dp[5001][5001];
vector<int> g, b;

long long calc(long long i, long long j) {
    if(i == g.size()) return 0;
    if(j == b.size()) return 2 * 1e18 + 1;
    
    long long &res = dp[i][j];
    if(res != -1) return res;
    
    return res = min(calc(i+1, j+1) + abs(g[i] - b[j]), calc(i, j+1));
}

int main() {
    cin >> n >> m;
    
    g.resize(n);
    b.resize(m);
    
    for(long long i = 0; i < n; i++) cin >> g[i];
    for(long long i = 0; i < m; i++) cin >> b[i];
    
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    
    memset(dp, -1, sizeof dp);
    cout << calc(0, 0) << endl;
    
    return 0;
}
