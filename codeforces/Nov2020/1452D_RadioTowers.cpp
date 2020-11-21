/*
If we know m is prime, then we can also use Fermats’s little theorem to find the inverse.

pow(a,(m-1)) ≡ 1 (mod m)
If we multiply both sides with a-1, we get

pow(a,-1) ≡ pow(a, m-2) (mod m)

*/

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int MOD = 998244353; // it is prime
int n;

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
    int ans = 1;
    while(y > 0)
    {
        if(y % 2 == 1)
            ans = mul(ans, x);
        x = mul(x, x);
        y /= 2;
    }
    return ans;
}

int divide(int x, int y)
{
    return mul(x, binpow(y, MOD - 2)); // using fermats little theorem
}

int main()
{
    int n;
    cin >> n;
    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++)
        fib[i] = add(fib[i - 1], fib[i - 2]);
    cout << divide(fib[n], binpow(2, n)) << endl;    
    return 0;
}