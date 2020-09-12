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
    vector<ll> v(n);
    for(int i=0; i<n; ++i){
      cin >> v[i];
    }

    sort(v.begin(),v.end());


    ll ans=v[n-1]*v[n-2]*v[n-3]*v[0]*v[1];
    ll ans1=v[n-1]*v[0]*v[1]*v[2]*v[3];
    ll ans2=v[n-1]*v[n-2]*v[n-3]*v[n-4]*v[n-5];
    ans=max({ans,ans1,ans2});
    cout << ans << '\n';
  }
  return 0;
}