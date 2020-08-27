#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int p,f;       cin >>    p >> f;
    int cnts,cntw; cin >> cnts >> cntw;
    int s,w;       cin >>    s >> w;

    int ans = 0;

    if(s>w){
      swap(s,w);
      swap(cnts,cntw);
    }
    int s1,s2,w1,w2;
    for (int s1 = 0; s1 <= min(cnts,p/s); ++s1)
    {
      w1 = min(cntw,(p-s*s1)/w);
      s2 = min(cnts-s1,f/s);
      w2 = min(cntw-w1,(f-s*s2)/w);
      ans = max(ans,s1+w1+s2+w2);
    }

    cout << ans << '\n';
  }
  return 0;
}


// int take(int weight, int & cnt, int & weight_capacity){

//   int cur_weight=0;
//   int cur_cnt=0;
//   // while( weight_capacity > ( cur_weight + weight ) && cnt > cur_cnt ){
//   //   cur_weight += weight;
//   //   ++cur_cnt;
//   // }

//   // cnt -= cur_cnt;
//   // weight_capacity -= cur_weight;

//   cur_cnt = min(cnt,weight_capacity/weight);
//   weight_capacity -= cur_cnt*weight;
//   cnt -= cur_cnt;

//   return cur_cnt;
// }
 
// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(0);
//   int tt;
//   cin >> tt;
//   while (tt--) {
//     int p,f;       cin >>    p >> f;
//     int cnts,cntw; cin >> cnts >> cntw;
//     int s,w;       cin >>    s >> w;

//     int ans = 0;

//     cout << "case:" << tt << "\n";
//     if(s<w){
//       cout << "s<w\n";
//       ans += take(s,cnts,p);
//       cout << ans << '\n';
//       ans += take(w,cntw,p);
//       cout << ans << '\n';
//       ans += take(s,cnts,f);
//       cout << ans << '\n';
//       ans += take(w,cntw,f);
//       cout << ans << '\n';
//     }else{
//       cout << "w<s\n";
//       ans += take(w,cntw,p);
//       cout << ans << '\n';
//       ans += take(s,cnts,p);
//       cout << ans << '\n';
//       ans += take(w,cntw,f);
//       cout << ans << '\n';
//       ans += take(s,cnts,f);
//       cout << ans << '\n';
//     }

//     //cout << ans << '\n';
//   }
//   return 0;
// }