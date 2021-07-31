vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    
    vector<vector<int>> ans(n+m-1 , vector<int> (0,0));
    
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int v = i+j;
            ans[v].push_back(A[i][j]);
        }
    }
    
    return ans;
}