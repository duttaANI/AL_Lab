// The map::count() is a built-in function in C++ STL which returns 1 if the element with key K is present in the map container
int Solution::solve(const vector<int> &arr) {
    int n = arr.size(), res = 2;
    if(n <= 2)
        return n;
    vector<unordered_map<int, int>> dp(n);  //(key, value) => ( difference, value) = longest Arithmetic sequence till position with difference 
    
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            int diff = arr[j] - arr[i];
            dp[i][diff] = dp[j].count(diff) > 0 ? dp[j][diff] + 1 : 2;
            res = max(res, dp[i][diff]);
        }
    }
    return res;
}


// Alternate 

int Solution::solve(const vector<int> &A) {
    int n = A.size();

	if (n < 3) return n;

	vector<vector<int> > dp(n, vector<int>(n, -1));

	map<int, int> pos;

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {

			dp[i][j] = 2;

			int dif = A[j] - A[i];

			int need = 2 * A[i] - A[j];

			if (pos.count(need) == 0) continue;

			dp[i][j] = max(dp[i][j], dp[pos[need]][i] + 1);

		}
		pos[A[i]] = i;

	}

	int ans = 2;

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {

			ans = max(ans, dp[i][j]);

		}

	}

	return ans;
}


// Numbers are too large in input A , memory limit exceeded 
// #define ll long long 
// const ll mxN = 1e9;
// int Solution::solve(const vector<int> &A) {
//     ll res = 2;
//     int n = A.size();
//     if(n==1) return 1;
//     vector<vector<ll>> dp(n, vector<ll>(100000, 0));
//     for (int i = 0; i < n; ++i)
//         for (int j = i + 1; j < n; ++j)  {
//             ll d = A[j] - A[i] + mxN;
//             dp[j][d] = max((ll)2, dp[i][d] + (ll)1 );
//             res = max(res, dp[j][d]);
//         }
//     return (int)res;
// }

// Below O(n^3) TLE

// int Solution::solve(const vector<int> &A) {
//     int n = A.size();
//     if(n==1) return 1;
//     int ans=0;
//     for (int i=0;i<=n-1;++i){
//         for(int j=i+1;j<=n-1;++j){
//             int cur = 2;
//             int lst = A[j];
//             int dif = A[j] - A[i];
//             for (int k=j+1;k<=n-1;++k){
//                 if (A[k] == lst + dif){
//                         cur++;
//                         lst = A[k];
//                 }
//             }  
//             ans = max(ans, cur);   
//         }
//     }
//     return ans;
// }
