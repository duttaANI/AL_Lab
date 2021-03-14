int Solution::solve(vector<int> &A) {
    unordered_map<int,int> mp;
    
    for(int i=0;i<A.size();++i){
        mp[A[i]]++;
    }
    
    for(int i=0;i<A.size();++i){
        if(mp.find(A[i])->second >= 2 ){
            return mp.find(A[i])->first;
        }
       
    }
    return -1;
}
