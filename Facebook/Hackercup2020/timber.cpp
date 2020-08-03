#include <bits/stdc++.h>
using namespace std;

#define test            int T_T; cin>>T_T; while(T_T--)
#define fast_io         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl            "\n"

signed main()
{
    fast_io
    int tc = 0;
    test
   	{
   			tc++;
   			int n;
   			cin >> n;
   			vector<pair<int,int>> in (n);
            for (size_t i = 0; i < n; i++)
            {
                scanf("%d%d", &in[i].first, &in[i].second );  // position , height
            }
            sort(in.begin(),in.end()); // sort acc to position
   			map<int,int> dp;
            int answer = 0;
            for( pair<int,int> p : in ){ // if a value in cpp map doesnt exist then o/p is 0
                int pos = p.first;
                int h = p.second;
                dp[pos+h] = max( dp[pos+h] , dp[pos] +h ); // tree falls right
                dp[pos] = max( dp[pos], dp[pos-h] + h );   // tree falls left
                answer = max({answer,dp[pos],dp[pos+h]});
            }

			cout << "Case #" << tc << ": ";
            cout << answer;
			cout << endl;

   	}
    return 0;       
}
