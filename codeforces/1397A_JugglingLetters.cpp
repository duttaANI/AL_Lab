#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    unordered_map<char, int> freq_map;

    int n;
    string str;
    cin >> n;
    for(int i=0; i<n; ++i){
      cin >> str;
      for(int j=0; j<str.length(); ++j){
        freq_map[str[j]]++;
      }
    }
    int flag = 1;
    for( auto it : freq_map ){
      if(it.second % n != 0){
        cout << "NO";
        flag = 0;
        break;
      }
    }
    if(flag){
      cout << "YES";
    }
    cout << "\n";
  }
}