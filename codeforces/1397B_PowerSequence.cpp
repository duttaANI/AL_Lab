#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  long long int ans = 1e15;
  int n,val;
  cin >> n;
  vector <int> a,copyA;
  long long int f1 = -n;
  for(int i=0; i<n; ++i){
    cin >> val;
    a.push_back(val);
    f1 += val ;
  }

  sort(a.begin(),a.end());
  int c = 0;
  while( pow(c,n-1) <= f1 + a[n-1] ){ // c^n−1 ≤ f(1)+amax
    c++;
    long long int cur = 0;
    for(int i=0; i<n; ++i){
      cur += abs( a[i] - pow(c-1,i) );
    }
    if(cur < ans){
      ans = cur;
    }
  }
  // cout << "c: " << c << "\n";
  // cout << "f1 + a[n-1] " << f1 + a[n-1] << "\n";
  // for(int i=0; i<n; ++i){
  //   ans += abs( a[i] - pow(c-1,i) );
  // }

  cout << ans;
}