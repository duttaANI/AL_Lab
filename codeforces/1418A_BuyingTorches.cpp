#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    ll x,y,k,ans=0;
    cin >> x >> y >> k;
    // ll curSticks = 1;
    ll totSticks = 1;
    ll reqSticks = k*(1+y);
    // while( totSticks < reqSticks ){
    //   // sell
      
    //   --totSticks;
    //   // buy
    //   totSticks += x;

    //   ++ans;
    // }



    ans = ( k*(1+y) -1 )/(x-1);

    if( ( k*(1+y) -1 )% (x-1) != 0)
      ++ans;

    cout << ans+k;
    cout << '\n';
  }
  return 0;
}