
void solve(int start,int n,vector<vector<int>> & ans, vector<int> & A ){
    if( start == n-1 ){
        ans.push_back(A);
        return ;
    }
    
    for(int i= start; i<n;++i){
        swap(A[start],A[i]);
        solve(start+1,n,ans,A);
        swap(A[start],A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    sort(A.begin(),A.end());
    int n = A.size();
    int start = 0;
    solve(start ,n,ans,A);
    return ans;
}