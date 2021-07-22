// even if frequency of elements is zero in map but it is counted in map.size() if before its frequency was non zero , so we have to map.erase() to remove such elements from size of map
vector<int> Solution::dNums(vector<int> &A, int B) {
    
    if( B > A.size() ){
        return {};
    }
    
    int temp = 0;
    int N = A.size();
    vector<int> ans(N-B+1,0);
    unordered_map<int,int> mp;
    
    for(int i=0;i<B;++i){
        mp[A[i]]++;
    }
    ans[0] = mp.size();
    
    for(int i=B; i<N; ++i){
        mp[A[i-B]]--;
        // cout << mp[A[i-B]] << " " << A[i-B] << endl;
        if(mp[A[i-B]]==0){
            mp.erase(A[i-B]);
            // cout << A[i-B] << endl;
        }
        mp[A[i]]++;
        // cout << mp[A[i]] << " " << A[i] << endl;
        ans[i-B+1]=mp.size();
    }
    
    return ans;
}
