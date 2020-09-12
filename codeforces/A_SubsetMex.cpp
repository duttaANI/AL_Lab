#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n,val;
    cin >> n;
    map <int,int> mp;
    for (int i = 0; i < n; ++i)
    {
      cin >> val;
      mp[val]++;
    }

    int A=-1,B=-1;
    map<int, int>::iterator itr;
    for( itr = mp.begin(); itr != mp.end(); ++itr ){
      if( itr->first - 1 == A && itr->second>0 ){
        A++;
        mp[itr->first]--;
      }
      if( itr->first - 1 == B && itr->second>0 ){
        B++;
        mp[itr->first]--;
      }
    }
    cout << A + B + 2;
    cout << '\n';
  }
  return 0;
}
