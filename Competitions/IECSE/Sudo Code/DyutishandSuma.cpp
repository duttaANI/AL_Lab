#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1001;

int t[mxN];

int main() {
	
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> t[i];
		}

		ll D=0,S=0;
		bool flg =1;
		int start=0; int end = n-1;
		while( start<end ){
			int f = t[ start ]; int b = t[ end ];
			                                                  int startCopy = start, endCopy = end, DCopy = D, SCopy = S;
			if( f>b ){
				++start;
				if(flg) {
					D+=f;
				}else{
					S+=f;
				}
			}else if ( f<b ){
				--end;
				if(flg) {
					D+=b;
				}else{
					S+=b;
				}
			}else{
					--end;
				if(flg) {
					D+=b;
				}else{
					S+=b;
				}
			
			}

			flg= (!flg);
		}

		if(flg){
			D+=t[ start ];
		}else{
			S+=t[ start ];
		}

		cout << D << " " << S << "\n";
	}
}

















































// #include <iostream>
// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;

// const int mxN = 1001;

// int t[mxN],dp[mxN][mxN]; // dp[x][y] ->  means the max value we can get if it it's our turn and only coins between x and y remain.(Inclusively)
// int n;

// int utill(vector<int>& v, vector<vector<int>> &dp, int i, int j){
//     if(i > j) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
    
//     int a = v[i] + min(utill(v,dp, i+1, j-1), utill(v, dp, i+2, j));
//     int b = v[j] + min(utill(v,dp,i, j-2), utill(v,dp, i+1, j-1));
//     dp[i][j] = max(a, b);
                    
//     return dp[i][j];
// }

// int main() {
	
// 	int tt;
// 	cin >> tt;
// 	while (tt--) {
		
// 		int sum = 0;
// 		cin >> n;
// 		vector <int> a(n,0);
// 		for (int i = 0; i < n; ++i)
// 		{
// 			cin >> a[i];
// 			sum += a[i];
// 		}

// 		vector<vector<int>> dp(n, vector<int>(n, -1));

// 		int D = utill(a, dp, 0, n-1);

// 		//cout << diff << " diff \n";

// 		cout << D << " " << (sum-D) << "\n";
		
// 	}
// }









































// #include <iostream>
// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;

// const int mxN = 1001;

// int t[mxN],dp[mxN][mxN]; // dp[x][y] ->  how much more scores that the first-in-action player will get from i to j than the second player.
// int n;

// int getDiff() {
    
//     for (int i = 0; i < n; i++) { dp[i][i] = t[i]; }
//     for (int len = 1; len < n; len++) {
//         for (int i = 0; i < n - len; i++) {
//             int j = i + len;
//             dp[i][j] = max(t[i] - dp[i + 1][j], t[j] - dp[i][j - 1]);
//         }
//     }

//     for (int i = 0; i < n; ++i)
//     {
//     	for (int j = 0; j < n; ++j)
//     	{
//     		cout << dp[i][j] << " ";
//     	}
//     	cout << "\n";
//     }

//     return dp[0][n - 1];
// }

// int main() {
	
// 	int tt;
// 	cin >> tt;
// 	while (tt--) {
		
// 		int sum = 0;
// 		cin >> n;
// 		for (int i = 0; i < n; ++i)
// 		{
// 			cin >> t[i];
// 			sum += t[i];
// 		}

// 		int diff = getDiff();

// 		//cout << diff << " diff \n";

// 		cout << (sum+diff)/2 << " " << (sum-diff)/2 << "\n";
		
// 	}
// }












































// #include <iostream>
// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;

// int main() {
	
// 	int tt;
// 	cin >> tt;
// 	while (tt--) {
// 		int N;
// 		cin >> N;
// 		deque <ll> t;
// 		int temp;
// 		for(int i=0; i<N; ++i){
// 			cin >> temp, t.push_back(temp);
// 		}
		
// 		ll D=0,S=0;
// 		bool flg =1;
		
// 		while(t.size()>1){
// 			int end = t.size();
// 			int f = t.at(0), b = t.at(end-1); 
// 			if( f>b ){
// 				t.pop_front();
// 				if(flg) {
// 					D+=f;
// 				}else{
// 					S+=f;
// 				}
				
// 			}else if ( f<b ){
// 				t.pop_back();
// 				if(flg) {
// 					D+=b;
// 				}else{
// 					S+=b;
// 				}
// 			}else{
// 				continue;
// 			}
// 			flg=!flg;
// 		}

// 		if(flg){
// 			D+=t.at(0);
// 		}else{
// 			S+=t.at(0);
// 		}

// 		cout << D << " " << S << "\n";
// 	}
	
// 	return 0;
// }