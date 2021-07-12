vector<int> Solution::solve(vector<vector<int> > &A) {
    vector<int> ans;
    int k = A.size();
    int n = A[0].size();
    priority_queue< int, vector<int>, greater<int> > pq;
    for(int i=0;i<k;++i){
        for(int j=0;j<n;++j){
            pq.push(A[i][j]);
        }
    }
    
    while(pq.size()){
        int f = pq.top() ; pq.pop();
        ans.push_back(f);
    }
    
    return ans;
}