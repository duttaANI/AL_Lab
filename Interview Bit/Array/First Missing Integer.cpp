int Solution::firstMissingPositive(vector<int> &A) {
    // my is memory limit exceeded
    // map<int,int> mp;
    // int n  = A.size();
    // for( auto i : A ){
    //     mp[i]++;
    // }
    // for(int i=1;i<=n+1;++i){
    //     mp[i]--;
    // }
    // for(auto it : mp){
    //     if( it.first<=0 ) continue;
    //     else{
    //         if(it.second<0){
    //             return it.first;
    //         }
    //     }
    // }
    // return -100;
    int n = A.size();
    for (int i = 0; i < n; i++) {
        if (A[i] > 0 && A[i] <= n) {
            int pos = A[i] - 1;
            if (A[pos] != A[i]) {
                swap(A[pos], A[i]);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] != i + 1) return (i + 1);
    }
    return n + 1;
}