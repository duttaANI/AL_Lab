int Solution::solve(vector<int> &A, int B) {
    int res = 0, oddCount = 0;
    unordered_map<int, int> umap;
    umap[0] ++;
    for(auto it: A) {
        oddCount += it%2;
        res += umap[oddCount - B];
        umap[oddCount] ++;
    }
    return res;
}