vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue< int , vector<int>  > pq ;
    int n = A.size();
    for(int i=0;i<n;++i){
        pq.push(A[i]);
    }
    
    vector<int> ans;
    for(int i=0;i<B;++i){
        int f = pq.top(); pq.pop();
        ans.push_back(f);
    }
    
    return ans;
}