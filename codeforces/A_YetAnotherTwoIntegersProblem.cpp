#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    ll a,b,diff;
    cin >> a >> b;
    diff = b - a;

    ll diffCopy = diff;

    ll ans = 0,Q;

    for (int i = 10; i >=1 ; --i )
    {
      ans += diff/i;
      Q = diff/i;
      diff -= Q*i;
    }

    cout << abs(ans) << '\n';
  }
  return 0;
}