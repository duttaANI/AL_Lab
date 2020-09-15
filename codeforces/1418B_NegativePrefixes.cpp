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
    vector<int> a(n,0);
    vector<int> b(n,0);

    for (int i = 0; i < n; ++i)
    {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
      cin >> b[i];
    }

    vector<int> unlocked;
    for (int i = 0; i < n; ++i)
    {
      if(b[i]==0){
        unlocked.push_back(a[i]);
      }
    }

    sort(unlocked.begin(),unlocked.end(),greater<int>());

    int itr = 0;
    for (int i = 0; i < n; ++i)
    {
      if(b[i]==0){
        a[i] = unlocked[itr];
        ++itr;
      }
    }

    for (int i = 0; i < n; ++i)
    {
      cout << a[i] << " ";
    }

    cout << '\n';
  }
  return 0;
}