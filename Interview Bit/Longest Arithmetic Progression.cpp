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