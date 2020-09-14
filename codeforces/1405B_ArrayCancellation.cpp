#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<ll> a(n,0);
   
    for (int i = 0; i < n; ++i)
    {
      cin >> a[i];
    }
    
    
    ll positivity = 0;
    for (int i = 0; i < n; ++i)
    {
      if( a[i]>=0 ){
        positivity += a[i];
        a[i]=0;
      }
      else if( positivity > 0 ){
        ll add = min(positivity, abs(a[i]));
        positivity -= add;
        a[i] += add;
      }
    }

    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
      if( a[i]<0 ){
        sum += abs(a[i]);
      }
    }

    cout << sum ;
    cout << '\n';
  }
  return 0;
}