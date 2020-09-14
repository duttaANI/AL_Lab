#include <bits/stdc++.h>

using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n,0);
    int mi = 0;
    for (int i = 0; i < n; ++i)
    {
      cin >> a[i];
      mi = (a[i]>a[mi])?i:mi;
    }
    vector<int> b(n);
    b[0] = a[mi]; a[mi] = 0;
    int cg = b[0];
    for (int i = 1; i < n; ++i)
    {
      int ci = 0, cans = 0;
      for (int j = 0; j < n; ++j)
      {
        if( a[j] && __gcd(a[j], cg) > cans ){
          ci = j;
          cans = __gcd(a[j], cg);
        }
      }
      b[i] = a[ci];
      cg = cans;
      a[ci] = 0;
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << ' ';
    cout << '\n';
  }
  return 0;
}