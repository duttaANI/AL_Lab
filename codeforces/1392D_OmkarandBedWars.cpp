#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 

void solve() {
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    while(s.size() && s[0] == s.back()) {
        cnt++;
        s.pop_back();
    }
    if(s.empty()) {
        if(cnt <= 2) {
            cout << "0\n";
            return;
        }
        if(cnt == 3) {
            cout << "1\n";
            return;
        }
        cout << (cnt + 2) / 3 << '\n';
        return;
    }
    s.push_back('$');
    for(int i = 0; i + 1 < s.size(); i++) {
        cnt++;
        if(s[i] != s[i + 1]) {
            ans += cnt / 3;
            cnt = 0;
        }
    }
    cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
    // for (long long int i = 0; i < n; ++i)
    // {
    //   if(s[i]!=s[i+1])
    //   {
    //     rotate(s.begin(),s.begin()+i+1,s.end());
    //     break;
    //   }
    // }

  }
  return 0;
}

/*
test case

11
129
LLLLLRRRRRRRRRLLLLLLLLLLRRRRRRRRRLRRRRRRRRRRLLLLLLLRRLLLLLLLRRRRLLLLLLLRRRRRRRRRLLLLLLRRLLLLLLLRRLLRRRRRRLLLLRRRRRRRRRRLLRRRRLLLR
52
RRRRRLLLLLLRRRRLLLLLLRRRLLRRRRRRRRRRLLRRLLLLLLLRRRRL
51
RRRLLLLRRRRRRRRRRLLLLLLLLRRRRRRRRRRLLLRRLLLLLRRRRRR
144
LLLLLLLRRRRRRLLLLLLLLLLRRRRRRRRRRLLLRRRRRRRRRLLLRRRRLLLLLLLLRRRRRRRRLLLLLLLLLLRRRRRRRRRRLLLLLRRLLLLLLLLLRRRRRRRRLLLLLLLLRRRRRRRRRLLLLLLLRRRRRRLR
43
LLLLLLRLLLLRRRRRRRRLLLLLRRRRRRRRRLLLLLRRRRR
21
RRRRRRLRRRRRRRRLLLLLL
164
LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRLLLLRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
1
L
2
RR
3
RRR
7
RRRRRRR


o/p
35
13
14
41
11
6
53
0
0
1
3
*/

