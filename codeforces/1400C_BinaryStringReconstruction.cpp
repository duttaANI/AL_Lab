#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    
    int x;
    string s;
    cin >> s >> x;
    int N = int(s.size());
    string w(N, '1');

    for (int i = 0; i < N; ++i)
      if(s[i]=='0'){
        if( i-x>=0 )
          w[i-x] = '0';
        
        if( i+x<N  )
          w[i+x] = '0';
      }
  
    bool ok = true;
    for (int i = 0; i < N; ++i)
    {
      bool ele = false;
      ele = ele || ( i-x>=0 && w[i-x]=='1' ) || ( i+x<N && w[i+x]=='1' );
      // cout << ele  << " " << ele+'0' <<  " " << s[i] << " " << s[i]-'0' << "\n";
      if(ele != s[i]-'0'){
        ok = false;
        // cout << "false\n";
      }
    }
    
    if( ok ){
      cout << w;
    }else{
      cout << -1;
    }
    cout << "\n";
  }
  
  
}

/*
4
00110100101111110110010001111111110011011000011111101000011001001101001
31
00011111101001001011010000001001100011111111011111111111
17
11111000000011001100110000010101100001011110011001111001110111110010110111111111111111001011011101110111011111111101011111011001001001100100000010000101000100110
39
10011000101011010101110111000111110101100000000000000000000000100101001011111011100100110101010010100
62


*/
